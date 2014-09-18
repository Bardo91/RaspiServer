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
#include <service/scan/deviceScanner.h>

namespace dmc {

	//------------------------------------------------------------------------------------------------------------------
	DmcServer::DmcServer(int _argc, const char** _argv)
		:mTopPin("8")
		,mService(nullptr)
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
		mPlcPortName = "/dev/ttyAMA0";
		
		/*In order to disable serial port login, we need to log in via ssh into the raspi, and then look for the file
		/etc/inititab. There we need to comment the line T0:23:respawn:/sbin/getty -L ttyAMA0 115200 vt100.
		After that, we can disable the bootup info, it's optional because maybe you'll like to know what is happening there.
		Whatever you decide, you need to edit the file /boot/cmdline.txt and remove all the references to the serial port.*/
	}

	//------------------------------------------------------------------------------------------------------------------
	void DmcServer::initHardware() {
		
		PLCDriver::init(mPlcPortName.c_str());
		DeviceScanner::get(); //lazy initialization
	}

	//------------------------------------------------------------------------------------------------------------------
	void DmcServer::loadDatabase() {
		DeviceMgr::get()->loadDatabase();
	}

	//------------------------------------------------------------------------------------------------------------------
	void DmcServer::launchService() {
		mTopPin.outPut();
		mTopPin.setHigh();
		mService = LANService::get();
	}
}