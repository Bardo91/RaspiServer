////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Sep/12
// Author:	Carmelo J. Fdez-Ag�era Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DMCSERVER_SERVICE_SCAN_DEVICESCANNER_H_
#define _DMCSERVER_SERVICE_SCAN_DEVICESCANNER_H_

#include <functional>

namespace dmc {

	class Device;

	class DeviceScanner {
	public:
		static DeviceScanner* get();

		typedef std::function<void(Device*)>	Delegate;

		void startScan	(Delegate _onDeviceFound); // Start scanning the PLC channel
		void stopScan	(); // Stop scanning the PLC channel

		bool isScanning	() { return mIsScanning; }
	private:
		DeviceScanner() = default;

		void onDeviceFound ();
		bool mIsScanning;

		Delegate mDeviceFoundListener;
		static DeviceScanner* sInstance;
	};

}	// namespace dmc

#endif // _DMCSERVER_SERVICE_SCAN_DEVICESCANNER_H_