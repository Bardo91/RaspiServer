////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/27
// Author:	Carmelo J. Fdez-Ag�era Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "dmcDevice.h"
#include <peripherals/plc/plcDriver.h>

namespace dmc {

	//---------------------------------------------------------------------------------------------------------------------
	DmcDevice::DmcDevice(unsigned _id)
		:Device(_id)
	{
	}

	//---------------------------------------------------------------------------------------------------------------------
	void DmcDevice::turnOn() {
		// Send on message
		PLCDriver::get()->
	}

}	// namespace dmc

#endif // _DMCSERVER_DEVICE_PLC_DMCDEVICE_H_