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

	class LANService {
	public:
		LANService();
		~LANService();

		typedef std::function<void (const std::string&)> Listener;
		// Listeners interface
		void registerListener(uint8_t _command, Listener _listener);

	private:
		std::map<uint8_t, Event<Listener>>	mEvents;
		SocketMgr							mComServer;
	};
}

#endif // _DMCSERVER_SERVICE_LANSERVICE_H_