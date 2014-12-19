////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/25
// Author:	Carmelo J. Fdez-Ag�era Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PLC Driver

#include <cassert>
#include <iostream>
#include "plcDriver.h"
#include "plcDriverSerial.h"
#include "plcDriverDummy.h"
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
		PLCDriverSerial* defaultPort = new PLCDriverSerial(_port);
		if(!defaultPort->isOpen()) {
			delete defaultPort;
			sInstance = new PLCDriverDummy();
		}
		else
			sInstance = defaultPort;
	}

	//------------------------------------------------------------------------------------------------------------------
	PLCDriver* PLCDriver::get() {
		assert(sInstance); // Should never return an invalid pointer
		return sInstance;
	}

}	// namespace dmc