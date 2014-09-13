////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/22
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DMCSERVER_SERVICE_LANSERVICE_H_
#define _DMCSERVER_SERVICE_LANSERVICE_H_

#include <set>
#include "scan/deviceScanner.h"

namespace dmc {

	class Client;
	class ServiceListener;

	class LANService {
	public:
		LANService();

		// Listeners interface
		void update	();

	private:
		std::set<Client*>	mClients;
		DeviceScanner		mScanner;
	};
}

#endif // _DMCSERVER_SERVICE_LANSERVICE_H_