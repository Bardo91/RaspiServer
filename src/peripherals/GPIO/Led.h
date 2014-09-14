////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Sep/14
// Author:	Jose Enrique Corchado Miralles
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DMCSERVER_PERIPHERALS_LED_H_
#define _DMCSERVER_PERIPHERALS_LED_H_

#include "Pin.h"

namespace dmc{
	
	class Led{
	public:
		Led(std::string _Pin); //constructor
		//~Led(); //Destructor

		void on				();
		void off			();
		void dimmer			();//TODO 666 implement these functions
		void sineWaveForm	();//TODO 666 implement these functions
		
	private:
		Pin ledPin;


	};

} //namespace dmc

#endif // _DMCSERVER_PERIPHERALS_LED_H_
