////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/25
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PLC Driver

#include <iostream>
#include "plcDriver.h"

namespace waveformgen {

	//------------------------------------------------------------------------------------------------------------------
	void PLCDriver::operator()(unsigned _clientId, const std::string& _msg) {
		std::cout << "PLCDriver received command \"" << unsigned(_msg[1]) << "\" from client" << _clientId << "\n";
	}

}	// namespace waveformgen