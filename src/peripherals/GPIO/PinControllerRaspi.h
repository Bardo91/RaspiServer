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

#ifdef __Raspi__

#include <string>

namespace dmc{

	class PinControllerRaspi{
	public:
		PinControllerRaspi(std::string _Pin); // _PinNumber is passed by the constructor, it also export the pin number.
		
		void on		(std::string _pinNumber);
		void off	(std::string _pinNumber);

		/*
		void sentIn();
		onPulse;
		dimmer;
		on;
		off;
		onShortPulse;
		onLongPulse;
		setPulseThreshold(unsgined);
		sinWaveDimmer;
		*/
	//private:
		void		exportPin	(std::string _Pin);
		//void		unexportPin	(std::string _Pin);
		std::string	readPin		();
		void		inputPin	();
		void		outPutPin	();

		std::string	pinNumber;
		


	};

	typedef PinControllerRaspi PinControllerBase;

}//namespace dmc


#endif // __Raspi__
#endif // _DMCSERVER_PERIPHERALS_GPIO_PINCONTROLLERRASPI_H_