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

namespace dmc{

	class PinControllerWin32{
	public:

		/*void sentOut();
		void sentIn();
		onPulse;
		dimmer;
		on;
		off;
		*/


	};

	typedef PinControllerWin32 PinControllerBase;
	
}//namespace dmc


#endif // _WIN32
#endif // _DMCSERVER_PERIPHERALS_PLC_SERIALWIN32_H_