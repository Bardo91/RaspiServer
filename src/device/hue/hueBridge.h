//----------------------------------------------------------------------------------------------------------------------
// Project: Domocracy, dmcLib
// Author: Carmelo J. Fdez-Agüera Tortosa (a.k.a. Technik)
// Date: 2014-Dec-21
//----------------------------------------------------------------------------------------------------------------------
// Philips Hue bridge
#ifndef _DMCSERVER_DEVICE_HUE_HUEBRIDGE_H_
#define _DMCSERVER_DEVICE_HUE_HUEBRIDGE_H_

#include <core/comm/http/httpConnection.h>
#include <string>

namespace dmc {

	class HueBridge {
	public:
		HueBridge(int _argc, const char** _argv);

	private:
		std::string mLocalIp;
		HttpConnection * bridgeConn = nullptr;
	};

}	// namespace dmc

#endif // _DMCSERVER_DEVICE_HUE_HUEBRIDGE_H_