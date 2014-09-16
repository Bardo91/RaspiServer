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
	// Singleton data
	PLCDriver* PLCDriver::sInstance = nullptr;

	//------------------------------------------------------------------------------------------------------------------
	void PLCDriver::init(const char* _port) {
		assert(_port && _port[0] != '\0'); // Port isn't an empty string
		assert(!sInstance); // Init should not be called multiple times
		sInstance = new PLCDriver(_port);
	}

	//------------------------------------------------------------------------------------------------------------------
	PLCDriver* PLCDriver::get() {
		assert(sInstance); // Should never return an invalid pointer
		return sInstance;
	}

	//------------------------------------------------------------------------------------------------------------------
	PLCDriver::PLCDriver(const char* _port)
		:mCom(_port, cBaudRate)
	{
		// Intentionally blank
	}

	//------------------------------------------------------------------------------------------------------------------
	void PLCDriver::sendCommand(unsigned, const std::string& _payload) {
		if(mCom.write(_payload.c_str(), _payload.size()) < _payload.size())
			cout << "Error: Unable to send message to PLC modem\n";
	}
	//------------------------------------------------------------------------------------------------------------------
	void PLCDriver::recieveCommand(unsigned, std::string& ) {
		mCom.read();
	}
}	// namespace dmc