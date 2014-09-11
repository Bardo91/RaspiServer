////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/27
// Author:	Carmelo J. Fdez-Agüera Tortosa
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
		// Note that factory overriding should not be an issue
		sChildFactories[_command] = _childFactory;
	}

}	// namespace dmc