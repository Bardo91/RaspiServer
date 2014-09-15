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
		static void init();
		static Time* get();        // Returns the singleton instance
		static void end();

	public: // --- Public interface ---
		double getTime();

	private:
		Time();
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

	//------------------------------------------------------------------------------------------------------------------
	inline Time * Time::get() {
		return sInstance;
	}

	//------------------------------------------------------------------------------------------------------------------
	inline double Time::getTime() {
	#if defined (__linux__)
			// Get current time
			timeval currentTime;
			gettimeofday(&currentTime, 0);
			return double(currentTime.tv_sec - mInitTime.tv_sec) + double(currentTime.tv_usec - mInitTime.tv_usec) / 1000000;
	#elif defined (_WIN32)
			// Get current time
			LARGE_INTEGER largeTicks;
			QueryPerformanceCounter(&largeTicks);
			unsigned currTime = largeTicks.LowPart;
			// Convert time difference to seconds
			LARGE_INTEGER frequency;
			QueryPerformanceFrequency(&frequency);
			return (double(currTime) / double(frequency.LowPart)) -
				(double(mInitTime.LowPart) / double(frequency.LowPart));
	#endif 
	}

}        // namespace dmc

#endif // _DMCSERVER_CORE_TIME_H_