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

namespace dmc {

	class Client;
	class Message;
	class ServiceListener;

	class LANService {
	public:
		static LANService* get();

		// Listeners interface
		void update		();
		void broadCast	(const Message&) const;

	private:
		LANService();

	private:
		std::set<Client*>	mClients;
		static LANService*	sInstance;
	};
}

#endif // _DMCSERVER_SERVICE_LANSERVICE_H_