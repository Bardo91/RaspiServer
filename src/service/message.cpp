////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/27
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <cstdint>
#include <iostream>
#include "message.h"

namespace dmc {

	//------------------------------------------------------------------------------------------------------------------
	Message::Message(Client* _sender, const std::string& _rawMessage)
		:mSender(_sender)
		,mRaw(_rawMessage)
	{
		// Discard invalid messages
		if(!checkIntegrity(_rawMessage)) {
			mType = InvalidMsg;
			return;
		}

		mSize = _rawMessage.size();
		mType = Type(uint8_t(_rawMessage[1]));
	}

	//------------------------------------------------------------------------------------------------------------------
	Message::Message(Type _command, const std::string& _payload)
		:mType(_command)
	{
		mSize = 2+_payload.size(); // Make room for size byte and command byte
		mRaw.resize(2);
		assert(mSize < 256);
		// Compose raw
		mRaw[0] = uint8_t(mSize);
		mRaw[1] = uint8_t(_command);
		mRaw.append(_payload);
	}

	//------------------------------------------------------------------------------------------------------------------
	void Message::dump() const {
		// Dump header
		std::cout << "Size = " << mSize << ", Type = 0x"
			<< std::hex << unsigned(mType) << std::dec << ", Payload = [ ";
		// Dump payload
		for(auto byte : payload())
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
			return false;
		}
		// Everything is ok
		return true;
	}

}	// namespace dmc