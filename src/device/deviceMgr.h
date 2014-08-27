////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/27
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DMCSERVER_DEVICE_DEVICEMGR_H_
#define _DMCSERVER_DEVICE_DEVICEMGR_H_

namespace dmc {

	class Device;

	class DeviceMgr {
	public:
		// Singleton Interface
		static DeviceMgr* get();

		void		registerDevice	(Device*);
		Device*		getDevice		(unsigned _devId);

	private:
		DeviceMgr();
	};

}	// namespace dmc

#endif // _DMCSERVER_DEVICE_DEVICEMGR_H_