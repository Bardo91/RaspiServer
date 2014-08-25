////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/22
// Author:	Carmelo J. Fdez-Agüera Tortosa
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
	void LANService::registerListener(uint8_t _command, Listener _l) {
		mEvents[_command] += _l;
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
			uint8_t commandType = message[1];
			mEvents[commandType](client, message);
		}
	}
}
