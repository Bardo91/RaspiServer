////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Sep/14
// Author:	Jose Enrique Corchado Miralles
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DMCSERVER_PERIPHERALS_BACKBUTTON_H_
#define _DMCSERVER_PERIPHERALS_BACKBUTTON_H_

#include "PinController.h"

namespace dmc{

	class BackButton {
	public:

		BackButton();

		void onShortPulse();
		void onLongPulse();
		void setPulseThreshold();
	
		~BackButton();

	private:
		PinController ButtonPin;


	};

} //namespace dmc


#endif // _DMCSERVER_PERIPHERALS_BACKBUTTON_H_