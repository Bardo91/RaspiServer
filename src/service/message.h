////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/27
// Author:	Carmelo J. Fdez-Ag�era Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DMCSERVER_SERVICE_MESSAGE_H_
#define _DMCSERVER_SERVICE_MESSAGE_H_

#include <string>

namespace dmc {
	
	class Message {
	public:
		enum Type {
			On = 1,
			Off = 2,
			Dimmer = 3,
			RGB = 4,
			InvalidMsg = 0xff
		};

	public:
		Message(const std::string& _rawMessage);

		const std::string&	payload	() const { return mPayload;	}
		unsigned			type	() const { return mType;	}
		bool				isOk	() const { return mType != InvalidMsg; }

	private:
		bool	checkIntegrity		(const std::string& _rawMsg) const;

	private:
		unsigned	mType;
		std::string mPayload;
	};

}	// namespace dmc

#endif // _DMCSERVER_SERVICE_MESSAGE_H_