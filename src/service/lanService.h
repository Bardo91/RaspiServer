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
#include "scan/deviceScanner.h"

namespace dmc {

	class ServiceListener;

	class LANService {
	public:
		LANService();

		// Listeners interface
		void update	();

	private:
		DeviceScanner	mScanner;
		SocketMgr*		mComServer;
	};
}

#endif // _DMCSERVER_SERVICE_LANSERVICE_H_