////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Sep/12
// Author:	Jose Enrique Corchado Miralles
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GPIO controller
#ifndef _DMCSERVER_PERIPHERALS_GPIO_PINCONTROLLERRASPI_H_
#define _DMCSERVER_PERIPHERALS_GPIO_PINCONTROLLERRASPI_H_

#ifdef _RASPI


namespace dmc{

	class PinControllerRaspi{
	public:

		/*void sentOut();
		void sentIn();
		onPulse;
		dimmer;
		on;
		off;
		*/

	};

	typedef PinControllerRaspi PinControllerBase;

}//namespace dmc


#endif // _RASPI
#endif // _DMCSERVER_PERIPHERALS_GPIO_PINCONTROLLERRASPI_H_