////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Sep/12
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DMCSERVER_SERVICE_SCAN_DEVICESCANNER_H_
#define _DMCSERVER_SERVICE_SCAN_DEVICESCANNER_H_

#include <functional>

namespace dmc {

	class Device;

	class DeviceScanner {
	public:
		typedef std::function<void(Device*)>	Delegate;

		void startScan	(Delegate _onDeviceFound); // Start scanning the PLC channel
		void stopScan	(); // Stop scanning the PLC channel

		bool isScanning	() { return mIsScanning; }
	private:
		void onDeviceFound ();
		bool mIsScanning;

		Delegate mDeviceFoundListener;
	};

}	// namespace dmc

#endif // _DMCSERVER_SERVICE_SCAN_DEVICESCANNER_H_