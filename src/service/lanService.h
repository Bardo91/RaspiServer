////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/22
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DMCSERVER_SERVICE_LANSERVICE_H_
#define _DMCSERVER_SERVICE_LANSERVICE_H_

#include "socket/socketMgr.h"

namespace dmc {

	class LANService {
	public:
		LANService();
		~LANService();

		/// 666 TODO: Protocol for listener registration

	private:
		SocketMgr	mComServer;
	};
}

#endif // _DMCSERVER_SERVICE_LANSERVICE_H_