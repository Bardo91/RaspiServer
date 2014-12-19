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
		virtual ~PLCDriver() = default;

		virtual void		sendCommand		(unsigned _devId, const std::string& _payload)	= 0;
		virtual void		receiveCommand	(unsigned _devId, std::string& _payload)		= 0;

	private:

		// Singleton
		static PLCDriver* sInstance;
	};

}	// namespace dmc

#endif // _DMCSERVER_PERIPHERALS_PLC_PLCDRIVER_H_