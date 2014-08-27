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
#include <service/serviceListener.h>

namespace dmc {

	class PLCDriver : public ServiceListener {
	public:
		PLCDriver(const char* _port);

		void								operator()			(unsigned _clientId, const Message& _msg) override;
		const std::vector<Message::Type>&	supportedMessages	() const override
				{ return mSupportedMessages; }

	private:
		Serial	mCom;
		std::vector<Message::Type>		mSupportedMessages;
		static const unsigned			cBaudRate = 115200;
	};

}	// namespace dmc

#endif // _DMCSERVER_PERIPHERALS_PLC_PLCDRIVER_H_