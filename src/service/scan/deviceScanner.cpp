////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Sep/12
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <cassert>
#include "deviceScanner.h"
#include <device/deviceMgr.h>
#include <device/plc/dmcDevice.h>

namespace dmc {

	//------------------------------------------------------------------------------------------------------------------
	void DeviceScanner::startScan(Delegate _listener) {
		// 666 TODO: This is a fake. Scan should ocur in a separate thread
		assert(!mIsScanning); // Already scanning
		mDeviceFoundListener = _listener;
		mIsScanning = true;
		onDeviceFound(); // Fake ocurrence
	}

	//------------------------------------------------------------------------------------------------------------------
	void DeviceScanner::stopScan() {
		mIsScanning = false;
	}

	//------------------------------------------------------------------------------------------------------------------
	void DeviceScanner::onDeviceFound() {
		// Create the device
		Device* foundDevice = new DmcDevice(7, "Light007");
		// Notify it to whoever is scanning
		mDeviceFoundListener(foundDevice);
	}

}	// namespace dmc