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
		auto iter = mRegisteredDevices.find(_dev->id());
		if(iter == mRegisteredDevices.end()) // Not found, as expected
		{
		}
		else {
			// Nobody should be trying to register a device twice
		}
	}

}	// namespace dmc