////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/27
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "message.h"

namespace dmc {

	//------------------------------------------------------------------------------------------------------------------
	Message::Message(const std::string& _rawMessage) {
		// Discard invalid messages
		if(!checkIntegrity(_rawMessage)) {
			mType = InvalidMsg;
			return;
		}

		mSize = _rawMessage.size();
		mType = Type(_rawMessage[1]);
		mPayload = _rawMessage.substr(2);
	}

	//------------------------------------------------------------------------------------------------------------------
	void Message::dump() const {
		// Dump header
		std::cout << "Size = " << mSize << ", Type = 0x"
			<< std::hex << unsigned(mType) << std::dec << ", Payload = [ ";
		// Dump payload
		for(auto byte : mPayload)
			std::cout << byte << "(0x" << std::hex << unsigned(byte) << ") " << std::dec;
		std::cout << "]\n";
	}

	//------------------------------------------------------------------------------------------------------------------
	bool Message::checkIntegrity(const std::string& _rawMsg) {
		// Is message too short?
		unsigned msgSize = _rawMsg.size();
		if(msgSize < 2) {
			std::cout << "Error: Received a message too short (Size = " << msgSize << ")\n";
			return false;
		}
		// Is message the size it says?
		unsigned expectedSize = unsigned(_rawMsg[0]);
		if(msgSize != expectedSize) {
			std::cout << "Error: Message size (" << msgSize <<") doesn't match expexted size (" << expectedSize << ")\n";
		}
		// Everything is ok
		return true;
	}

}	// namespace dmc