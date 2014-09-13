////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Sep/12
// Author:	Jose Enrique Corchado Miralles
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DMCSERVER_PERIPHERALS_GPIO_PINCONTROLLER_H_
#define _DMCSERVER_PERIPHERALS_GPIO_PINCONTROLLER_H_

#include <string>
#include "PinControllerWin32.h"
#include "PinControllerRaspi.h"

using namespace std;

namespace dmc {

	class PinController : public PinControllerBase {
	public:	
		PinController(string _Pin) : PinControllerBase(_Pin){}
		

		
	};

	//Led and BackButton

}	// namespace dmc

#endif // _DMCSERVER_PERIPHERALS_PLC_SERIAL_H_