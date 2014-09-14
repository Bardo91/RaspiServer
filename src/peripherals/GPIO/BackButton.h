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

namespace dmc{

	class BackButton {
	public:

		BackButton(std::string _Pin); //hilo monitoreando el pin

		
		void setPulseThreshold(unsigned _pulseValue);	// TODO 666 implement these functions
	
		~BackButton();

	private: 
		Pin ButtonPin;
		void onShortPulse();							// TODO 666 implement these functions
		void onLongPulse();								// TODO 666 implement these functions

	};

} //namespace dmc


#endif // _DMCSERVER_PERIPHERALS_BACKBUTTON_H_