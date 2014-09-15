////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/22
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "service/lanService.h" // This include must be first due to windows-specific include order requirements
#include <cassert>
#include "dmcServer.h"
#include "peripherals/plc/plcDriver.h"
#include <device/deviceMgr.h>

namespace dmc {

	//------------------------------------------------------------------------------------------------------------------
	DmcServer::DmcServer(int _argc, const char** _argv)
		:mService(nullptr)
	{
		loadDefaultConfig(); // This fills every important thing with default values
		processArguments(_argc, _argv); // Execution arguments can override default configuration values
		// Prerequisites for launching the service
		initHardware();
		loadDatabase();
		// Actually start the service
		launchService();
	}

	//------------------------------------------------------------------------------------------------------------------
	void DmcServer::processArguments(int _argc, const char** _argv) {
		for(int i = 0; i < _argc; ++i) {
			std::string argument(_argv[i]);
			if(argument.substr(0,9)=="-plcPort=") {
				mPlcPortName = argument.substr(9);
			}
		}
	}

	//------------------------------------------------------------------------------------------------------------------
	DmcServer::~DmcServer(){
		// Prerequisites for launching the service
		if(mService)
			delete mService;
	}

	//------------------------------------------------------------------------------------------------------------------
	bool DmcServer::update() {
		assert(mService);
		mService->update();
		return true;
	}

	//------------------------------------------------------------------------------------------------------------------
	void DmcServer::loadDefaultConfig() {
		mPlcPortName = "/sys/ttyS0";
	}

	//------------------------------------------------------------------------------------------------------------------
	void DmcServer::initHardware() {
		// 666 TODO: Buttons, Leds and pins
		PLCDriver::init(mPlcPortName.c_str());
	}

	//------------------------------------------------------------------------------------------------------------------
	void DmcServer::loadDatabase() {
		DeviceMgr::get()->loadDatabase();
	}

	//------------------------------------------------------------------------------------------------------------------
	void DmcServer::launchService() {
		mService = LANService::get();
	}
}