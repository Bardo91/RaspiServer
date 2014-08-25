////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/22
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "lanService.h"
#include <string>

namespace dmc {
	const unsigned int PORT = 15028;

	//------------------------------------------------------------------------------------------------------------------
	LANService::LANService()
		:mComServer(PORT)
	{
		// Intentionally blank
	}

	//------------------------------------------------------------------------------------------------------------------
	void LANService::registerListener(uint8_t _command, Listener _l) {
		mEvents[_command] += _l;
	}

	//------------------------------------------------------------------------------------------------------------------
	void LANService::update() {
		// Request received messages
		std::string message;
		unsigned client;
		mComServer.readAny(client, message);
	}
}
