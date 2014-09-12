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
#include <device/plc/dmcDevice.h>

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
		mRegisteredDevices[_dev->id()] = _dev;
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

	//------------------------------------------------------------------------------------------------------------------
	unsigned DeviceMgr::nRooms() const {
		return mRoomIndex.size();
	}

	//------------------------------------------------------------------------------------------------------------------
	unsigned DeviceMgr::getRoomId(const std::string& _roomName) const {
		auto roomIter = mRoomIndex.find(_roomName);
		assert(roomIter != mRoomIndex.end());
		return roomIter->second;
	}

	//------------------------------------------------------------------------------------------------------------------
	void DeviceMgr::addRoom(unsigned _roomId, const std::string& _roomName) {
		mRoomIndex.insert(std::make_pair(_roomName, _roomId));
		mRooms[_roomId]; // Make "room" for a new list of devices
	}

	//------------------------------------------------------------------------------------------------------------------
	void DeviceMgr::addDeviceToRoom(unsigned _devId, unsigned _roomId) {
		mRooms[_roomId].push_back(_devId);
	}

	//------------------------------------------------------------------------------------------------------------------
	const std::vector<unsigned>& DeviceMgr::devicesByRoom(unsigned _roomId) const {
		auto roomIter = mRooms.find(_roomId);
		assert(roomIter != mRooms.end());
		return roomIter->second;
	}

	//------------------------------------------------------------------------------------------------------------------
	void DeviceMgr::loadDatabase() {
		// 666 TODO: Load devices from a real database
		new DmcDevice(4, "light001"); // 4 is a random number
	}

	//------------------------------------------------------------------------------------------------------------------
	void DeviceMgr::saveDatabase() const {
		// 666 TODO: Actually save something somewhere
	}

}	// namespace dmc