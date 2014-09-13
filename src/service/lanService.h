////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/22
// Author:	Carmelo J. Fdez-Ag�era Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DMCSERVER_SERVICE_LANSERVICE_H_
#define _DMCSERVER_SERVICE_LANSERVICE_H_

#include <set>

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
	};
}

#endif // _DMCSERVER_SERVICE_LANSERVICE_H_