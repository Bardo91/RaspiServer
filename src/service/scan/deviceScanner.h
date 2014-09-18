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
#include <peripherals/GPIO/Led.h>
#include <peripherals/GPIO/BackButton.h>
#include <thread>
#include <peripherals/GPIO/Pin.h>

namespace dmc {

	class Device;

	class DeviceScanner {
	public:
		static DeviceScanner* get();

		typedef std::function<void(Device*)>	Delegate;

		void startScan	(Delegate _onDeviceFound); // Start scanning the PLC channel
		void stopScan	(); // Stop scanning the PLC channel

		bool isScanning	() { return mIsScanning; }

		~DeviceScanner();
	private:
		DeviceScanner();

		void onDeviceFound ();
		bool mIsScanning;
		bool mMustClose		= false;

		std::thread mThreadScanner;
		Delegate mDeviceFoundListener;
		static DeviceScanner* sInstance;

		Led	mLight;
		BackButton mButton;
		Pin mAvrReset;
		
	};

}	// namespace dmc

#endif // _DMCSERVER_SERVICE_SCAN_DEVICESCANNER_H_