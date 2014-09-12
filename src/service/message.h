////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/27
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DMCSERVER_SERVICE_MESSAGE_H_
#define _DMCSERVER_SERVICE_MESSAGE_H_

#include <string>

namespace dmc {
	
	class Message {
	public:
		enum Type {
			// --- Device commands ---
			On = 1,
			Off = 2,
			Dimmer = 3,
			RGB = 4,
			// --- System commands ---
			Scan = 0x80,
			RequestListUpdate = 0x81,
			ListInfo = 0x82,
			newDevice = 0x83,
			updateState = 0x84,
			roomInfo = 0x85,
			deviceInfo = 0x86,
			pairDevToRoom = 0x87,
			HandShake = 0x90,
			RequestClientId = 0x91,
			SubmitClientId = 0x92,
			InvalidMsg = 0xff
		};

	public:
		Message(const std::string& _rawMessage);

		const std::string&	payload	() const { return mPayload;	}
		Type				type	() const { return mType;	}
		bool				isOk	() const { return mType != InvalidMsg; }
		unsigned			size	() const { return mSize; };

	private:
		static bool			checkIntegrity	(const std::string& _rawMsg);

	private:
		Type		mType;
		unsigned	mSize;
		std::string mPayload;
	};

}	// namespace dmc

#endif // _DMCSERVER_SERVICE_MESSAGE_H_