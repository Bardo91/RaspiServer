////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Sep/12
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DMCSERVER_SERVICE_SCAN_DEVICESCANNER_H_
#define _DMCSERVER_SERVICE_SCAN_DEVICESCANNER_H_

namespace dmc {

	class DeviceScanner {
	public:
		void startScan	(); // Start scanning the PLC channel
		void stopScan	(); // Stop scanning the PLC channel


	};

}	// namespace dmc

#endif // _DMCSERVER_SERVICE_SCAN_DEVICESCANNER_H_