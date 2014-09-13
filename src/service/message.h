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
	
	class Client;

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
			NewDevice = 0x83,
			UpdateState = 0x84,
			RoomInfo = 0x85,
			DeviceInfo = 0x86,
			PairDevToRoom = 0x87,
			HandShake = 0x90,
			RequestClientId = 0x91,
			SubmitClientId = 0x92,
			InvalidMsg = 0xff
		};

	public:
		Message(Client* _sender, const std::string& _rawMessage);
		Message(Type _command, const std::string& _payload);

		const std::string&	payload	() const { return mRaw.substr(2);	}
		Type				type	() const { return mType;	}
		bool				isOk	() const { return mType != InvalidMsg; }
		unsigned			size	() const { return mSize; };
		
		void				dump	() const;
		const std::string&	raw		() const { return mRaw; }

	private:
		static bool			checkIntegrity	(const std::string& _rawMsg);

	private:
		Client*		mSender;
		Type		mType;
		unsigned	mSize;
		std::string mRaw;
	};

}	// namespace dmc

#endif // _DMCSERVER_SERVICE_MESSAGE_H_