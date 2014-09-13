////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/22
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include "command.h"
#include <iostream>
#include "lanService.h"
#include "message.h"
#include <string>

using namespace std;

namespace dmc {
	const unsigned int PORT = 5028;

	//------------------------------------------------------------------------------------------------------------------
	LANService::LANService()
	{
		SocketMgr::init(PORT);
		mComServer = SocketMgr::get();
	}

	//------------------------------------------------------------------------------------------------------------------
	void LANService::update() {
		// Request received messages
		std::string message;
		unsigned client;
		if(mComServer->readAny(client, message)) { // There are messages to process
			assert(message.size() > 1);
			// Debug message
			cout << "LAN Service received message a message\n";
			// Create a formatted message from the string
			Message formatedMessage(message);
			// Create a command using the message
			Command * requestedCommand = Command::createCommand(formatedMessage);
			assert(requestedCommand);
			// run the command
			requestedCommand->run();
			delete requestedCommand;
		}
	}
}
