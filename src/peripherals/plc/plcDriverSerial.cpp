////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Dec/19
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PLC Driver

#include <cassert>
#include <iostream>
#include "plcDriverSerial.h"
#include <service/message.h>

using namespace std;

namespace dmc {

	//------------------------------------------------------------------------------------------------------------------
	PLCDriverSerial::PLCDriverSerial(const char* _port)
		:mCom(_port, cBaudRate)
	{
		// Intentionally blank
	}

	//------------------------------------------------------------------------------------------------------------------
	void PLCDriverSerial::sendCommand(unsigned, const std::string& _payload) {
		assert(mCom.isOpen());
		if(mCom.write(_payload.c_str(), _payload.size()) < _payload.size())
			cout << "Error: Unable to send message to PLC modem\n";
	}
	//------------------------------------------------------------------------------------------------------------------
	void PLCDriverSerial::receiveCommand(unsigned, std::string& ) {
		mCom.read();
		assert(mCom.isOpen());
	}
}	// namespace dmc