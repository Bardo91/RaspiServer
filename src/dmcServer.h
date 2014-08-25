////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/22
// Author:	Carmelo J. Fdez-Ag�era Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DMCSERVER_DMCSERVER_H_
#define _DMCSERVER_DMCSERVER_H_

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
		void initHardware		();
		void loadDatabase		();
		void launchService		();
		void registerListeners	();

	private:
		LANService* mService;
		PLCDriver*	mPlc;
	};

}

#endif // _DMCSERVER_DMCSERVER_H_