////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/27
// Author:	Carmelo J. Fdez-Ag�era Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <cassert>
#include <iostream>
#include "message.h"
#include "command.h"

namespace dmc {

	//------------------------------------------------------------------------------------------------------------------
	// Static data
	std::map<unsigned, Command::Factory> Command::sChildFactories;

	//------------------------------------------------------------------------------------------------------------------
	Command* Command::createCommand(const Message& _msg) {
		unsigned index = unsigned(_msg.type());
		auto factoryIter = sChildFactories.find(index);
		if(factoryIter == sChildFactories.end()) {
			std::cout << "Error: Coudln't locate command factory for message type " << index << "\n";
			return nullptr;
		}
		return factoryIter->second(_msg);
	}

	//------------------------------------------------------------------------------------------------------------------
	void Command::registerChildFactory(unsigned _command, Factory _childFactory) {
		assert(sChildFactories.find(_command) == sChildFactories.end()); // Avoid factory duplication
		sChildFactories[_command] = _childFactory;
	}

}	// namespace dmc