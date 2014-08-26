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

namespace dmc {

	enum Command {
		On = 1,
		Off = 2,
		Dimmer = 3,
		RGB = 4
	};

	//------------------------------------------------------------------------------------------------------------------
	DmcServer::DmcServer(int , const char**)
		:mService(nullptr)
	{
		// Prerequisites for launching the service
		initHardware();
		loadDatabase();
		// Actually start the service
		launchService();
		// Register client processes to respond to service events
		registerListeners();
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
	void DmcServer::initHardware() {
		// 666 TODO: Buttons, Leds and pins
		mPlc = new PLCDriver;
	}

	//------------------------------------------------------------------------------------------------------------------
	void DmcServer::loadDatabase() {
		// 666 TODO
	}

	//------------------------------------------------------------------------------------------------------------------
	void DmcServer::launchService() {
		mService = new LANService;
	}

	//------------------------------------------------------------------------------------------------------------------
	void DmcServer::registerListeners() {
		auto plcListener = [this](unsigned _client, const std::string& _msg) { (*mPlc)(_client, _msg); };
		mService->registerListener(Command::On, plcListener);
		mService->registerListener(Command::Off, plcListener);
		mService->registerListener(Command::Dimmer, plcListener);
		mService->registerListener(Command::RGB, plcListener);
	}

}