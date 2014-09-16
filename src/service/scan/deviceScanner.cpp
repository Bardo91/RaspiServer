////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Sep/12
// Author:	Carmelo J. Fdez-Ag�era Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <cassert>
#include "deviceScanner.h"
#include <device/deviceMgr.h>
#include <device/plc/dmcDevice.h>
#include <iostream>
#include <peripherals/plc/plcDriver.h>

namespace dmc {
	//------------------------------------------------------------------------------------------------------------------
	DeviceScanner::DeviceScanner() : mLight("4"),mButton("17"){
	
	}

	//------------------------------------------------------------------------------------------------------------------
	DeviceScanner* DeviceScanner::sInstance = nullptr;

	//------------------------------------------------------------------------------------------------------------------
	DeviceScanner* DeviceScanner::get() {
		if(!sInstance)
			sInstance = new DeviceScanner;
		return sInstance;
	}

	//------------------------------------------------------------------------------------------------------------------
	void DeviceScanner::startScan(Delegate _listener) {
		mThreadScanner = std::thread([this](Delegate _listener) {
			while (!mMustClose){
				/*if (canRead()){
					mLight.on(); //Leds on while looking for
					PLCDriver::get()->sendCommand(21, "fake you Carmelo");
					PLCDriver::get()->recieveCommand(10, "fake you Carmelo from PLc");
				}
				mDeviceFoundListener = _listener;
				onDeviceFound(); // Fake ocurrence*/
			}

		});
	
	}

	//------------------------------------------------------------------------------------------------------------------
	void DeviceScanner::stopScan() {
		mLight.off();
		mMustClose = true;
		mThreadScanner.join();
		mIsScanning = false;
	}
	//------------------------------------------------------------------------------------------------------------------
	DeviceScanner::~DeviceScanner(){
		if (!isScanning){
			stopScan();
		}
	
	}
	//------------------------------------------------------------------------------------------------------------------
	void DeviceScanner::onDeviceFound() {
		// Create the device
		Device* foundDevice = DeviceMgr::get()->getDevice(7);
		if(foundDevice)
			std::cout << "Warning: Trying to register duplicate device 7\n";
		else
			foundDevice = new DmcDevice(7, "Light007");
		// Notify it to whoever is scanning
		mDeviceFoundListener(foundDevice);
	}

}	// namespace dmc