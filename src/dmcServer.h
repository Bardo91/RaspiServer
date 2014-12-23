////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/22
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DMCSERVER_DMCSERVER_H_
#define _DMCSERVER_DMCSERVER_H_

#include <device/hue/hueBridge.h>
#include <string>
#include <peripherals/GPIO/Pin.h>

namespace dmc {

	class LANService;
	class PLCDriver;
	
	class DmcServer {
	public:
		DmcServer	(int _argc, const char** _argv);
		~DmcServer();
		// Return false means the application should exit
		bool update	();

	private:
		void processArguments	(int _argc, const char** _argv);
		void loadDefaultConfig	();
		void initHardware		();
		void loadDatabase		();
		void launchService		();

	private:
		Pin			mTopPin;
		LANService* mService;
		PLCDriver*	mPlc;
		std::string	mPlcPortName;
		HueBridge*	mHueBridge;
	};

}

#endif // _DMCSERVER_DMCSERVER_H_