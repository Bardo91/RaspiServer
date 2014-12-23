//----------------------------------------------------------------------------------------------------------------------
// Project: Domocracy, dmcLib
// Author: Carmelo J. Fdez-Agüera Tortosa (a.k.a. Technik)
// Date: 2014-Dec-21
//----------------------------------------------------------------------------------------------------------------------
// Philips Hue bridge
#include "hueBridge.h"

namespace dmc {
	//------------------------------------------------------------------------------------------------------------------
	HueBridge::HueBridge(int _argc, const char** _argv) {
		mLocalIp = "10.100.2.224";
		for(int i = 0; i < _argc; ++i) {
			std::string argument(_argv[i]);
			if(argument.substr(0,8)=="-bridge=") {
				bridgeIp = argument.substr(8);
			}
		}
	}
}	// dmc