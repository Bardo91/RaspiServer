////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/22
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "dmcServer.h"
#include "service/lanService.h"

namespace dmc {

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
		return true;
	}

	//------------------------------------------------------------------------------------------------------------------
	void DmcServer::initHardware() {
		// 666 TODO: Buttons, Leds and pins
		// 666 TODO: PLC Communications
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
		// 666 TODO
	}

}