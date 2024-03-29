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
#include <assert.h>

namespace dmc {
	//------------------------------------------------------------------------------------------------------------------
	DeviceScanner::DeviceScanner() : mLight("18"),mButton("23"), mAvrReset("24"){
		mAvrReset.setLow(); //reset the Avr at loading time
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
		mAvrReset.setHigh(); //make sure Avr is set High
		assert(mThreadScanner.get_id() != std::this_thread::get_id());

		mLight.on();
		mIsScanning = true;
		mMustClose = false;
		mDeviceFoundListener = _listener;
		
		if (mThreadScanner.joinable())
			mThreadScanner.join();
					
		mThreadScanner = std::thread([this]() {
			string message;
			while (!mMustClose){
					PLCDriver::get()->sendCommand(21, "S");
					PLCDriver::get()->recieveCommand(10, message);
				
				onDeviceFound(); // Fake ocurrence*/
			}
			mIsScanning = false;
		
		});
	}

	//------------------------------------------------------------------------------------------------------------------
	void DeviceScanner::stopScan() {
		mLight.off();
		mMustClose = true;
	}
	//------------------------------------------------------------------------------------------------------------------
	DeviceScanner::~DeviceScanner(){
		assert(mThreadScanner.get_id() != std::this_thread::get_id()); // Ensure it's not this thread trying to delete itself
		if (!isScanning()){
			stopScan();
		}
		assert(mThreadScanner.joinable());
		mThreadScanner.join();
	
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