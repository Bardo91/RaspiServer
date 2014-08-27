////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/25
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PLC Driver
#ifndef _DMCSERVER_PERIPHERALS_PLC_PLCDRIVER_H_
#define _DMCSERVER_PERIPHERALS_PLC_PLCDRIVER_H_

#include <string>
#include "serial.h"

namespace dmc {

	class PLCDriver {
	public:
		PLCDriver();
		void operator()(unsigned _clientId, const std::string& _msg);

	private:
		Serial	mCom;

		static const unsigned cBaudRate = 115200;
	};

}	// namespace dmc

#endif // _DMCSERVER_PERIPHERALS_PLC_PLCDRIVER_H_