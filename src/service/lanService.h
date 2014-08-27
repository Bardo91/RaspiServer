////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/22
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DMCSERVER_SERVICE_LANSERVICE_H_
#define _DMCSERVER_SERVICE_LANSERVICE_H_

#include "event.h"
#include <map>
#include "socket/socketMgr.h"

namespace dmc {

	class ServiceListener;

	class LANService {
	public:
		LANService();

		// Listeners interface
		void registerListener		(ServiceListener* _listener);
		void update					();

	private:
		typedef Event<unsigned, const std::string&> MEvent;

		std::map<uint8_t, MEvent>	mEvents;
		SocketMgr					mComServer;
	};
}

#endif // _DMCSERVER_SERVICE_LANSERVICE_H_