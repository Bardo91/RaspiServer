////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Sep/14
// Author:	Jose Enrique Corchado Miralles
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Led.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

namespace dmc{

	//------------------------------------------------------------------------------------------------------------------
	Led::Led(std::string _Pin) : ledPin(_Pin){	//pin 4 is gonna be the pin where leds are going to be connected
		ledPin.outPut();
	}

	//------------------------------------------------------------------------------------------------------------------
	void Led::on(){
		ledPin.setHigh();
	}

	//------------------------------------------------------------------------------------------------------------------
	void Led::off(){
		ledPin.setLow();
	}

	//------------------------------------------------------------------------------------------------------------------
	void dimmer(){

	}

	//------------------------------------------------------------------------------------------------------------------
	void sineWaveForm(){

	}



} //namespace dmc


