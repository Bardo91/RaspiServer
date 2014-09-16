////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2013/Apr/08
// Author:	Pablo Ramón Soria
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _DMCSERVER_CORE_TIME_H_
#define _DMCSERVER_CORE_TIME_H_

#if defined(__linux__)
	#include <sys/time.h>
#elif defined(_WIN32)
	#include <Windows.h>
#endif

#include <iostream>

namespace dmc {
	class Time {
	public:
		// --- Singleton life cycle ---
		static Time* get();        // Returns the singleton instance

	public: // --- Public interface ---
		double getTime();			//getTime in seconds

	private:
		Time();
		~Time() = delete;
	private:
		// Singleton instance
		static Time* sInstance; // Static data definition
		// members
		#if defined(__linux__)
			timeval mInitTime;
		#elif defined (_WIN32)
			LARGE_INTEGER mInitTime;
		#endif
	};

}        // namespace dmc

#endif // _DMCSERVER_CORE_TIME_H_