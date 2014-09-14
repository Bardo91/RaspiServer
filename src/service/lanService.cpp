////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/22
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "client/client.h"
#include "lanService.h"
#include "socket/socketMgr.h"

using namespace std;

namespace dmc {
	const unsigned int PORT = 5028;

	//------------------------------------------------------------------------------------------------------------------
	LANService::LANService()
	{
		SocketMgr::init(PORT);
		SocketMgr::get()->onNewConnection([this](unsigned _connectionId){
			mClients.insert(new Client(_connectionId));
		});
	}

	//------------------------------------------------------------------------------------------------------------------
	void LANService::update() {
		// Update socket manager
		SocketMgr::get()->update();
		// Request received messages
		for(auto clientIter = mClients.begin(); clientIter != mClients.end();)
		{
			if((*clientIter)->update())
				clientIter++;
			else // Client is finished
				clientIter = mClients.erase(clientIter);
		}
	}
}
