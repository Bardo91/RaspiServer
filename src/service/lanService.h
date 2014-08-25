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

		// Listener type
		typedef Event<unsigned, const std::string&> MEvent;
		typedef MEvent::Listener Listener;

		// Listeners interface
		void registerListener		(uint8_t _command, Listener _listener);
		void update					();

	private:
		std::map<uint8_t, MEvent>	mEvents;
		SocketMgr							mComServer;
	};
}

#endif // _DMCSERVER_SERVICE_LANSERVICE_H_