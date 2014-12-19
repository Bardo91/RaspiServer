////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/25
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PLC Driver through serial port
#ifndef _DMCSERVER_PERIPHERALS_PLC_PLCDRIVERSERIAL_H_
#define _DMCSERVER_PERIPHERALS_PLC_PLCDRIVERSERIAL_H_

#include "plcDriver.h"

namespace dmc {

	class PLCDriverSerial : private PLCDriver{
	public:
		PLCDriverSerial(const char* _port);

		void sendCommand		(unsigned _devId, const std::string& _payload) override;
		void recieveCommand	(unsigned _devId, std::string& _payload) override;

	private:
		Serial	mCom;
		static const unsigned			cBaudRate = 9600;
	};

}	// namespace dmc

#endif // _DMCSERVER_PERIPHERALS_PLC_PLCDRIVER_H_