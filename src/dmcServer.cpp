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
#include <device/plc/dmcDevice.h>

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
				assert(!mPlcPortName.empty());
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
		mPlcPortName = "COM4";
	}

	//------------------------------------------------------------------------------------------------------------------
	void DmcServer::initHardware() {
		// 666 TODO: Buttons, Leds and pins
		mPlc = new PLCDriver(mPlcPortName.c_str());
	}

	//------------------------------------------------------------------------------------------------------------------
	void DmcServer::loadDatabase() {
		// 666 TODO: Load devices from a real database
		DeviceMgr::get()->registerDevice(new DmcDevice(4)); // 4 is a random number
	}

	//------------------------------------------------------------------------------------------------------------------
	void DmcServer::launchService() {
		mService = new LANService;
	}
}