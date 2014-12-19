////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Dec/19
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PLC Driver through serial port
#ifndef _DMCSERVER_PERIPHERALS_PLC_PLCDRIVERSERIAL_H_
#define _DMCSERVER_PERIPHERALS_PLC_PLCDRIVERSERIAL_H_

#include "plcDriver.h"

namespace dmc {

	class PLCDriverSerial : public PLCDriver{
	public:
		PLCDriverSerial(const char* _port);

		void sendCommand		(unsigned _devId, const std::string& _payload) override;
		void receiveCommand	(unsigned _devId, std::string& _payload) override;

		bool isOpen() const { return mCom.isOpen(); }

	private:
		Serial	mCom;
		static const unsigned			cBaudRate = 9600;
	};

}	// namespace dmc

#endif // _DMCSERVER_PERIPHERALS_PLC_PLCDRIVER_H_