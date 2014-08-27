////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/25
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PLC Driver
#ifndef _DMCSERVER_SERVICE_SERVICELISTENER_H_
#define _DMCSERVER_SERVICE_SERVICELISTENER_H_

#include <service/message.h>

namespace dmc {

	class ServiceListener {
	public:
		virtual void								operator()			(unsigned _clientId, const Message& _msg)	= 0;
		virtual const std::vector<Message::Type>&	supportedMessages	() const									= 0;
	};

}	// namespace dmc

#endif // _DMCSERVER_PERIPHERALS_PLC_PLCDRIVER_H_