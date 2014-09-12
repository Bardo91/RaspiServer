////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Sep/12
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "deviceScanner.h"

namespace dmc {

	//------------------------------------------------------------------------------------------------------------------
	void DeviceScanner::startScan() {
		// 666 TODO: This is a fake. Scan should ocur in a separate thread
		mIsScanning = true;
		onDeviceFound();
	}

	//------------------------------------------------------------------------------------------------------------------
	void DeviceScanner::stopScan() {
		mIsScanning = false;
	}

	//------------------------------------------------------------------------------------------------------------------
	void DeviceScanner::onDeviceFound() {
		// Create the device
		// Add it to the manager
		// Notify it
	}

}	// namespace dmc