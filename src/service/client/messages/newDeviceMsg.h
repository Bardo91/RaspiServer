////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Sep/14
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DMCSERVER_SERVICE_CLIENT_MESSAGES_H_
#define _DMCSERVER_SERVICE_CLIENT_MESSAGES_H_

#include <service/message.h>

namespace dmc {

	class Device;

	class NewDeviceMsg : public Message {
	public:
		NewDeviceMsg(const Device& _dev);
	};

}	// namespace dmc

#endif // _DMCSERVER_SERVICE_CLIENT_MESSAGES_H_