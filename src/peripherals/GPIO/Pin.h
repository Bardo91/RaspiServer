////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Sep/12
// Author:	Jose Enrique Corchado Miralles
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DMCSERVER_PERIPHERALS_GPIO_PIN_H_
#define _DMCSERVER_PERIPHERALS_GPIO_PIN_H_

#include <string>
#include "PinWin32.h"
#include "PinRaspi.h"

using namespace std;

namespace dmc {

	class Pin : public PinBase {
	public:	
		Pin(string _Pin) : PinBase(_Pin) {}
		~Pin();

	};


}	// namespace dmc

#endif //_DMCSERVER_PERIPHERALS_GPIO_PIN_H_