////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Sep/14
// Author:	Jose Enrique Corchado Miralles
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "BackButton.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

namespace dmc {

	//------------------------------------------------------------------------------------------------------------------
	BackButton::BackButton() : ButtonPin("17"){
	
		ButtonPin.exportPin(ButtonPin.pinNumber);
		ButtonPin.inputPin();

		}

	//------------------------------------------------------------------------------------------------------------------
	void BackButton::onLongPulse(){
	
	}

	//------------------------------------------------------------------------------------------------------------------
	void BackButton::onShortPulse(){

	}

	//------------------------------------------------------------------------------------------------------------------
	void BackButton::setPulseThreshold(){

	}

	//------------------------------------------------------------------------------------------------------------------
	BackButton::~BackButton(){

		ButtonPin.unexportPin(ButtonPin.pinNumber);
	
	}
} //namespace dmc