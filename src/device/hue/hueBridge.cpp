//----------------------------------------------------------------------------------------------------------------------
// Project: Domocracy, dmcLib
// Author: Carmelo J. Fdez-Agüera Tortosa (a.k.a. Technik)
// Date: 2014-Dec-21
//----------------------------------------------------------------------------------------------------------------------
// Philips Hue bridge
#include <cassert>
#include "hueBridge.h"
#include "hueVar.h"

namespace dmc {
	//------------------------------------------------------------------------------------------------------------------
	HueBridge::HueBridge(int _argc, const char** _argv) {
		mLocalIp = "10.100.2.224";
		for(int i = 0; i < _argc; ++i) {
			std::string argument(_argv[i]);
			if(argument.substr(0,8)=="-bridge=") {
				mLocalIp = argument.substr(8);
			}
		}
		HueVar var(R"([{"id":"001788fffe0af1c8","internalipaddress":"192.168.1.30","macaddress":"00:17:88:0a:f1:c8","name":"Developer Bridge"}])");
		assert(var.isList());
	}
}	// dmc