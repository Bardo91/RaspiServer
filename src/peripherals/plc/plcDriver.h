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
#include <vector>
#include <string>

namespace dmc {

	class PLCDriver {
	public:
		static void			init			(const char* _port);
		static PLCDriver*	get				();

		virtual void		sendCommand		(unsigned _devId, const std::string& _payload);
		virtual void		recieveCommand	(unsigned _devId, std::string& _payload);

	private:
		PLCDriver(const char* _port);

		Serial	mCom;
		static const unsigned			cBaudRate = 9600;

		// Singleton
		static PLCDriver* sInstance;
	};

}	// namespace dmc

#endif // _DMCSERVER_PERIPHERALS_PLC_PLCDRIVER_H_