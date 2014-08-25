////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/25
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Simple serial port communications
#ifndef _DMCSERVER_PERIPHERALS_PLC_SERIAL_H_
#define _DMCSERVER_PERIPHERALS_PLC_SERIAL_H_

#include <cstdint>
#ifdef _WIN32
#include "serialWin32.h"
#endif // _WIN32

namespace waveformgen {

	class Serial : public SerialBase {
	public:
		Serial(const char* _port, unsigned _baudRate) : SerialBase(_port,_baudRate) {}
	};

}	// namespace waveformgen

#endif // _DMCSERVER_PERIPHERALS_PLC_SERIAL_H_