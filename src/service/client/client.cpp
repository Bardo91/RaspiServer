////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Sep/12
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <cassert>
#include "client.h"
#include <service/command.h>
#include <iostream>
#include <service/message.h>
#include <service/socket/socketMgr.h>

namespace dmc {

	//------------------------------------------------------------------------------------------------------------------
	Client::Client(unsigned _connectionId)
		:mId(_connectionId)
	{
		std::cout << "New Client listening on port " << _connectionId << "\n";
		SocketMgr::get()->ownConnection(_connectionId);
	}

	//------------------------------------------------------------------------------------------------------------------
	Client::~Client() {
		SocketMgr::get()->releaseConnection(mId);
	}

	//------------------------------------------------------------------------------------------------------------------
	bool Client::update() {
		// Check connection
		if(!SocketMgr::get()->isConnectionAlive(mId)) {
			std::cout << "Client " << mId << " lost connection\n";
			return false;
		}
		readMessage();
		return true;
	}

	//------------------------------------------------------------------------------------------------------------------
	void Client::registerCommands() {
		// 666 TODO Register command factories
	}

	//------------------------------------------------------------------------------------------------------------------
	void Client::readMessage() {
		// Read message
		std::string message;
		if(SocketMgr::get()->readFrom(mId, message)) { // There are messages to process
			// Create a formatted message from the string
			Message formatedMessage(message);
			std::cout << "Client " << mId << " sent a message of type " << formatedMessage.type() << "\n";
			if(!formatedMessage.isOk()) {
				std::cout << "Error: Invalid message from client " << mId << "\nMessage dump:\n-";
				formatedMessage.dump();
				return;
			}
			// Create a command using the message
			Command * requestedCommand = Command::createCommand(mId, formatedMessage);
			assert(requestedCommand);
			// run the command
			requestedCommand->run();
			delete requestedCommand;
		}
	}

}	// namespace dmc