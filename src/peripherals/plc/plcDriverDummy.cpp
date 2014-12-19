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
#include "plcDriverDummy.h"
#include <service/message.h>

using namespace std;

namespace dmc {

	//------------------------------------------------------------------------------------------------------------------
	PLCDriverDummy::PLCDriverDummy()
	{
		// Intentionally blank
		cout << "Warning: No real serial port open, using a dummy serial instead\n";
	}

	//------------------------------------------------------------------------------------------------------------------
	void PLCDriverDummy::sendCommand(unsigned, const std::string& _payload) {
			cout << "PLCDriverDummy sent:" << std::hex;
			for(unsigned i = 0; i < _payload.size(); ++i)
				cout << " " << (unsigned)_payload[i];
			cout << std::dec << "\n";
	}
	//------------------------------------------------------------------------------------------------------------------
	void PLCDriverDummy::receiveCommand(unsigned, std::string& ) {
		 cout << "Warning: Trying to receive messages from a dummy Serial port\n";
		return;
	}
}	// namespace dmc