////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/25
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PLC Driver
#ifndef _DMCSERVER_PERIPHERALS_PLC_SERIAL_H_
#define _DMCSERVER_PERIPHERALS_PLC_SERIAL_H_

#include <string>

namespace waveformgen {

	class PLCDriver {
	public:
		void operator()(unsigned _clientId, const std::string& _msg);
	};

}	// namespace waveformgen

#endif // _DMCSERVER_PERIPHERALS_PLC_SERIAL_H_