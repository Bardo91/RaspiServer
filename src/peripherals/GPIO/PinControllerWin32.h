////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Sep/12
// Author:	Jose Enrique Corchado Miralles
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GPIO controller
#ifndef _DMCSERVER_PERIPHERALS_GPIO_PINCONTROLLERWIN32_H_
#define _DMCSERVER_PERIPHERALS_GPIO_PINCONTROLLERWIN32_H_

#ifdef _WIN32
#include <Windows.h>
#include <string>

using namespace std;

namespace dmc{

	class PinControllerWin32{
	public:
		PinControllerWin32(string _Pin);
		
		int on();
		int off();

		/*void sentOut();
		void sentIn();
		onPulse;
		dimmer;
		onShortPulse;
		onLongPulse;
		setPulseThreshold(unsgined);
		sinWaveDimmer;
		*/
	//private:
		int		exportPin(string _Pin);
		int		unexportPin(string _Pin);
		string	readPin();
		int		inputPin();
		int		outPutPin();

		string	pinNumber;

	};

	typedef PinControllerWin32 PinControllerBase;
	
}//namespace dmc


#endif // _WIN32
#endif // _DMCSERVER_PERIPHERALS_PLC_SERIALWIN32_H_