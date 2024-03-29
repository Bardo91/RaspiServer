////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/25
// Author:	Carmelo J. Fdez-Ag�era Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Simple serial port communications
#ifndef _DMCSERVER_PERIPHERALS_PLC_SERIAL_H_
#define _DMCSERVER_PERIPHERALS_PLC_SERIAL_H_

#include <cstdint>
#include "serialWin32.h"
#include "SerialLinux.h"

namespace dmc {

	class Serial : public SerialBase {
	public:
		Serial(const char* _port, unsigned _baudRate) : SerialBase(_port,_baudRate) {}
	};

}	// namespace dmc

#endif // _DMCSERVER_PERIPHERALS_PLC_SERIAL_H_