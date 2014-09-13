////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Sep/12
// Author:	Jose Enrique Corchado Miralles
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef __Raspi__
#include "PinControllerRaspi.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

namespace dmc{

	//------------------------------------------------------------------------------------------------------------------
	PinControllerRaspi::PinControllerRaspi(string _Pin){
		exportPin(_Pin);
		//unexportPin(_Pin); //TODO 666 implement this
		pinNumber = _Pin;
	}

	//------------------------------------------------------------------------------------------------------------------
	void PinControllerRaspi::exportPin(string _Pin){
	
		string export_str = "/sys/class/gpio/export";
		ofstream exportgpio(export_str.c_str()); // Open "export" file. Convert C++ string to C string. Required for all Linux pathnames
		if (!exportgpio){
			cout << " OPERATION FAILED: Unable to export GPIO"<< _Pin <<" ."<< endl;
		}

		exportgpio << _Pin; //write GPIO number to export
		exportgpio.close(); //close export file
		
	}
	
	//------------------------------------------------------------------------------------------------------------------
	
	string PinControllerRaspi::readPin(){
		string val;
		string getval_str = "/sys/class/gpio/gpio" + pinNumber + "/value";
		ifstream getvalgpio(getval_str.c_str());// open value file for gpio
		if (!getvalgpio){
			cout << " OPERATION FAILED: Unable to get value of GPIO"<< pinNumber <<" ."<< endl;
		}

		getvalgpio >> val ;  //read gpio value

		if(val != "0")
			val = "1";
		else
			val = "0";

		getvalgpio.close(); //close the value file
		return val;
					
	}

	//------------------------------------------------------------------------------------------------------------------

	void PinControllerRaspi::inputPin(){
	
		string setdir_str ="/sys/class/gpio/gpio" + pinNumber + "/direction";
		ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
		if (!setdirgpio){
			cout << " OPERATION FAILED: Unable to set direction of GPIO"<< pinNumber <<" ."<< endl;
		}

		setdirgpio << "in"; //write direction to direction file
		setdirgpio.close(); // close direction file
				
	}

	//------------------------------------------------------------------------------------------------------------------

	void PinControllerRaspi::outPutPin(){

		string setdir_str ="/sys/class/gpio/gpio" + pinNumber + "/direction";
		ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
		if (!setdirgpio){
			cout << " OPERATION FAILED: Unable to set direction of GPIO"<< pinNumber <<" ."<< endl;
		}

		setdirgpio << "out"; 
		setdirgpio.close(); // close direction file
		
	}

	//------------------------------------------------------------------------------------------------------------------

	void PinControllerRaspi::on(string pinNumber){

		string setval_str = "/sys/class/gpio/gpio" + pinNumber + "/value";
		ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
		if (!setvalgpio){
			cout << " OPERATION FAILED: Unable to set the value of GPIO"<< pinNumber <<" ."<< endl;
		}

		setvalgpio << "1" ;//write value to value file
		setvalgpio.close();// close value file 
		
	}

	//------------------------------------------------------------------------------------------------------------------

	void PinControllerRaspi::off(string _pinNumber){

		string setval_str = "/sys/class/gpio/gpio" + pinNumber + "/value";
		ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
		if (!setvalgpio){
			cout << " OPERATION FAILED: Unable to set the value of GPIO"<< pinNumber <<" ."<< endl;
		}

		setvalgpio << "0" ;//write value to value file
		setvalgpio.close();// close value file 
		
	}

	//------------------------------------------------------------------------------------------------------------------
}

#endif // __linux__
