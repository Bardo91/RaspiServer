////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/22
// Author:	Carmelo J. Fdez-Ag�era Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <iostream>
#include "lanService.h"
#include <string>

using namespace std;

namespace dmc {
	const unsigned int PORT = 5028;

	//------------------------------------------------------------------------------------------------------------------
	LANService::LANService()
		:mComServer(PORT)
	{
		// Intentionally blank
	}

	//------------------------------------------------------------------------------------------------------------------
	void LANService::update() {
		// Request received messages
		std::string message;
		unsigned client;
		if(mComServer.readAny(client, message)) { // There are messages to process
			assert(message.size() > 1);
			// Debug message
			cout << "LAN Service received message a message\n";
			// Alert everyone who is listening to this command
			uint8_t msgType = message[1];
			mEvents[msgType](client, message);
		}
	}
}
