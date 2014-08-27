////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/25
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PLC Driver

#include <cassert>
#include <iostream>
#include "plcDriver.h"
#include <service/message.h>

using namespace std;

namespace dmc {

	//------------------------------------------------------------------------------------------------------------------
	PLCDriver::PLCDriver(const char* _port)
		:mCom(_port, cBaudRate)
	{
		mSupportedMessages = {
			Message::On,
			Message::Off,
			Message::Dimmer
		};
	}

	//------------------------------------------------------------------------------------------------------------------
	void PLCDriver::operator()(unsigned _clientId, const Message& _msg) {
		cout << "PLCDriver received command \"" << _msg.type() << "\" from client" << _clientId << "\n";
		switch(_msg.type()) {
		case Message::On:
			cout << "On command\n";
			mCom.write("RBW", 3);
			break;
		case Message::Off:
			cout << "Off command\n";
			mCom.write("0", 1);
			break;
		case Message::Dimmer: {
			unsigned intensity = unsigned(_msg.payload()[1]);
			cout << "Dimmer command to " << intensity << "%\n";
			if(intensity > 50)
				mCom.write("RBG", 3);
			else
				mCom.write("0", 1);
			break;
		}
		default:
			std::cout << "Unknown command";
			assert(false);
			break;
		}
	}

}	// namespace dmc