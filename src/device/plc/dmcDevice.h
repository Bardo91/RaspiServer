////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/27
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DMCSERVER_DEVICE_PLC_DMCDEVICE_H_
#define _DMCSERVER_DEVICE_PLC_DMCDEVICE_H_

#include <device/device.h>

namespace dmc {

	class DmcDevice : public Device {
	public:
		DmcDevice(unsigned _id);

		void turnOn		();
		void turnOff	();
		void dimm		(unsigned _value);
	};

}	// namespace dmc

#endif // _DMCSERVER_DEVICE_PLC_DMCDEVICE_H_