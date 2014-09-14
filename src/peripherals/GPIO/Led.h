////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Sep/14
// Author:	Jose Enrique Corchado Miralles
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DMCSERVER_PERIPHERALS_LED_H_
#define _DMCSERVER_PERIPHERALS_LED_H_

#include "PinController.h"

namespace dmc{
	
	class Led{
	public:
		Led(); //constructor
		
		void on				();
		void off			();
		void dimmer			();
		void sineWaveForm	();

		~Led(); //Destructor

	private:
		PinController ledPin;


	};

} //namespace dmc

#endif // _DMCSERVER_PERIPHERALS_LED_H_
