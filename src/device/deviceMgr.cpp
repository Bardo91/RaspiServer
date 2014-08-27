////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/27
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <cassert>
#include "device.h"
#include "deviceMgr.h"
#include <iostream>

using namespace std;

namespace dmc {

	//------------------------------------------------------------------------------------------------------------------
	DeviceMgr* DeviceMgr::sInstance = nullptr;

	//------------------------------------------------------------------------------------------------------------------
	DeviceMgr* DeviceMgr::get() {
		if(!sInstance)
			sInstance = new DeviceMgr;
		assert(sInstance);
		return sInstance;
	}

	//------------------------------------------------------------------------------------------------------------------
	void DeviceMgr::registerDevice(Device* _dev) {
		// Nobody should be trying to register a device twice
		assert(mRegisteredDevices.find(_dev->id()) == mRegisteredDevices.end());
		// Actually register the device
		mRegisteredDevices[_dev->id()];
	}

	//------------------------------------------------------------------------------------------------------------------
	Device* DeviceMgr::getDevice(unsigned _devId) const {
		auto iter = mRegisteredDevices.find(_devId);
		if(iter == mRegisteredDevices.end()) {
			cout << "Warning: Requesting unregistered device (devId = " << _devId << ")\n";
			return nullptr;
		}
		else
			return iter->second;
	}

}	// namespace dmc