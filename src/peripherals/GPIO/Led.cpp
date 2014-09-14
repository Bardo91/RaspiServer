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
	Led::Led() : ledPin("4"){	//pin 4 is gonna be the pin where leds are going to be connected
		
		ledPin.exportPin(ledPin.pinNumber); //export the pin
		ledPin.outPutPin(); //Set has output
	}

	//------------------------------------------------------------------------------------------------------------------
	void Led::on(){
		
		
		string setval_str = "/sys/class/gpio/gpio" + ledPin.pinNumber + "/value";
		ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
		if (!setvalgpio){
			cout << " OPERATION FAILED: Unable to set the value of GPIO" << ledPin.pinNumber << " ." << endl;
		}

		setvalgpio << "1";//write value to value file
		setvalgpio.close();// close value file 
	
	
	}

	//------------------------------------------------------------------------------------------------------------------
	void Led::off(){
	
		string setval_str = "/sys/class/gpio/gpio" + ledPin.pinNumber + "/value";
		ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
		if (!setvalgpio){
			cout << " OPERATION FAILED: Unable to set the value of GPIO" << ledPin.pinNumber << " ." << endl;
		}

		setvalgpio << "0";//write value to value file
		setvalgpio.close();// close value file 
	
	}

	//------------------------------------------------------------------------------------------------------------------
	void dimmer();

	//------------------------------------------------------------------------------------------------------------------
	void sineWaveForm();

	//------------------------------------------------------------------------------------------------------------------
	Led::~Led(){

		ledPin.unexportPin(ledPin.pinNumber); //delete the pin from the sespecific file

	}

} //namespace dmc



