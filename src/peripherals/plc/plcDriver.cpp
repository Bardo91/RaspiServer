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

namespace dmc {

	//------------------------------------------------------------------------------------------------------------------
	PLCDriver::PLCDriver()
		:mCom("COM4", 115200)
	{
		mCom.write("RRRRRRRRRRRR", 12);
	}

	//------------------------------------------------------------------------------------------------------------------
	void PLCDriver::operator()(unsigned _clientId, const std::string& _msg) {
		std::cout << "PLCDriver received command \"" << unsigned(_msg[1]) << "\" from client" << _clientId << "\n";
		static bool onOff = true;
		if(onOff)
			mCom.write("00000000000000000", 12);
		else
			mCom.write("RRRRRRRRRRRR", 12);
		onOff = !onOff;
	}

}	// namespace dmc