////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/25
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PLC Driver through serial port
#ifndef _DMCSERVER_PERIPHERALS_PLC_PLCDRIVERDUMMY_H_
#define _DMCSERVER_PERIPHERALS_PLC_PLCDRIVERDUMMY_H_

#include "plcDriver.h"

namespace dmc {

	class PLCDriverDummy : private PLCDriver{
	public:
		PLCDriverDummy(const char* _port);

		void sendCommand		(unsigned _devId, const std::string& _payload) override;
		void recieveCommand	(unsigned _devId, std::string& _payload) override;
	};

}	// namespace dmc

#endif // _DMCSERVER_PERIPHERALS_PLC_PLCDRIVER_H_