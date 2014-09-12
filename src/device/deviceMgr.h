////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/27
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DMCSERVER_DEVICE_DEVICEMGR_H_
#define _DMCSERVER_DEVICE_DEVICEMGR_H_

#include <string>
#include <unordered_map>

namespace dmc {

	class Device;

	class DeviceMgr {
	public:
		// Singleton Interface
		static DeviceMgr*				get				();

		void							registerDevice	(Device*);
		Device*							getDevice		(unsigned _devId) const;

		unsigned						nRooms			() const;
		unsigned						getRoomId		(const std::string& _roomName) const;
		void							addRoom			(unsigned _id, const std::string& _roomName);
		void							addDeviceToRoom	(unsigned _devId, unsigned _roomId);
		const std::vector<unsigned>&	devicesByRoom	(unsigned _roomId) const;

	private:
		DeviceMgr() = default;

		typedef std::vector<unsigned>	Room;	// List of device indices
		
		std::unordered_map<unsigned, Device*>		mRegisteredDevices;	// Key: device id, value: Pointer to device
		std::unordered_map<unsigned, Room>			mRooms;	// Key: Roon index, value: Device list
		std::unordered_map<std::string, unsigned>	mRoomIndex; // Key: Room name, Value: Room index

		// Singleton instance
		static DeviceMgr*	sInstance;
	};

}	// namespace dmc

#endif // _DMCSERVER_DEVICE_DEVICEMGR_H_