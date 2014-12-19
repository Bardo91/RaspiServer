////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Dec/19
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PLC Driver through serial port
#ifndef _DMCSERVER_PERIPHERALS_PLC_PLCDRIVERDUMMY_H_
#define _DMCSERVER_PERIPHERALS_PLC_PLCDRIVERDUMMY_H_

#include "plcDriver.h"

namespace dmc {

	class PLCDriverDummy : public PLCDriver{
	public:
		PLCDriverDummy();

		void sendCommand		(unsigned _devId, const std::string& _payload) override;
		void receiveCommand	(unsigned _devId, std::string& _payload) override;
	};

}	// namespace dmc

#endif // _DMCSERVER_PERIPHERALS_PLC_PLCDRIVER_H_