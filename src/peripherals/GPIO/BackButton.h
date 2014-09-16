////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Sep/14
// Author:	Jose Enrique Corchado Miralles
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DMCSERVER_PERIPHERALS_BACKBUTTON_H_
#define _DMCSERVER_PERIPHERALS_BACKBUTTON_H_

#include "Pin.h"
#include <thread>

namespace dmc{

	class BackButton {
	public:

		BackButton			(std::string _Pin); 
		~BackButton			();
		
		void onShortPulse	();											// TODO 666 implement these functions
		void onLongPulse	();											// TODO 666 implement these functions

	private: 
		Pin			ButtonPin;
		std::thread mThread;
		bool		mMustClose		= false;
		double		mPulseDuration;
		double		mThresHold		= 2;
	};

} //namespace dmc


#endif // _DMCSERVER_PERIPHERALS_BACKBUTTON_H_