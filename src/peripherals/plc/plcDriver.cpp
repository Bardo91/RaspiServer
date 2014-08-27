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

using namespace std;

namespace dmc {

	//------------------------------------------------------------------------------------------------------------------
	PLCDriver::PLCDriver(const char* _port)
		:mCom(_port, cBaudRate)
	{
	}

	//------------------------------------------------------------------------------------------------------------------
	void PLCDriver::operator()(unsigned _clientId, const std::string& _msg) {
		uint8_t command = uint8_t(_msg[1]);
		cout << "PLCDriver received command \"" << command << "\" from client" << _clientId << "\n";
		unsigned intensity = 0;
		switch(command) {
		case On:
			cout << "On command\n";
			mCom.write("RBW", 3);
			break;
		case Off:
			cout << "Off command\n";
			mCom.write("0", 1);
			break;
		case Dimmer:
			intensity = unsigned(_msg[3]);
			cout << "Dimmer command to " << intensity << "%\n";
			if(intensity > 50)
				mCom.write("RBG", 3);
			else
				mCom.write("0", 1);
			break;
		default:
			std::cout << "Unknown command";
			assert(false);
			break;
		}
	}

}	// namespace dmc