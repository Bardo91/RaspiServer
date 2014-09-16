////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Sep/12
// Author:	Jose Enrique Corchado Miralles
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef __Raspi__
#include "PinRaspi.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <assert.h>

using namespace std;

namespace dmc{

	//------------------------------------------------------------------------------------------------------------------
	PinRaspi::PinRaspi(string _Pin){
		
		pinNumber = _Pin; 
		assert(_Pin != "18"); //PWM pin
		exportPin(pinNumber);
		
	}
	
	//------------------------------------------------------------------------------------------------------------------
	PinRaspi::~PinRaspi(){

		unexportPin(pinNumber);
	}

	//------------------------------------------------------------------------------------------------------------------
	void PinRaspi::exportPin(string _Pin){
	
		string export_str = "/sys/class/gpio/export";
		ofstream exportgpio(export_str.c_str()); // Open "export" file. Convert C++ string to C string. Required for all Linux pathnames
		if (!exportgpio){
			cout << " OPERATION FAILED: Unable to export GPIO"<< _Pin <<" ."<< endl;
		}

		exportgpio << _Pin; //write GPIO number to export
		exportgpio.close(); //close export file
		
	}

	//------------------------------------------------------------------------------------------------------------------
	void PinRaspi::unexportPin(string _Pin){

		string export_str = "/sys/class/gpio/unexport";
		ofstream exportgpio(export_str.c_str()); // Open "export" file. Convert C++ string to C string. Required for all Linux pathnames
		if (!exportgpio){
			cout << " OPERATION FAILED: Unable to export GPIO" << _Pin << " ." << endl;
		}

		exportgpio << _Pin; //write GPIO number to export
		exportgpio.close(); //close export file

	}
	
	//------------------------------------------------------------------------------------------------------------------
	bool PinRaspi::read(){

		string val;
		string getval_str = "/sys/class/gpio/gpio" + pinNumber + "/value";
		ifstream getvalgpio(getval_str.c_str());// open value file for gpio
		if (!getvalgpio){
			cout << " OPERATION FAILED: Unable to get value of GPIO"<< pinNumber <<" ."<< endl;
		}

		getvalgpio >> val ;  //read gpio value

		if (val != "0"){
			getvalgpio.close();
			return true;
			//val = "1";
		}
		else{
			//val = "0";
			return false;
			getvalgpio.close(); //close the value file
		}
	}

	//------------------------------------------------------------------------------------------------------------------
	void PinRaspi::input(){
	
		string setdir_str ="/sys/class/gpio/gpio" + pinNumber + "/direction";
		ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
		if (!setdirgpio){
			cout << " OPERATION FAILED: Unable to set direction of GPIO"<< pinNumber <<" ."<< endl;
		}

		setdirgpio << "in"; //write direction to direction file
		setdirgpio.close(); // close direction file
				
	}

	//------------------------------------------------------------------------------------------------------------------
	void PinRaspi::outPut(){

		string setdir_str ="/sys/class/gpio/gpio" + pinNumber + "/direction";
		ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
		if (!setdirgpio){
			cout << " OPERATION FAILED: Unable to set direction of GPIO"<< pinNumber <<" ."<< endl;
		}

		setdirgpio << "out"; 
		setdirgpio.close(); // close direction file
		
	}

	//------------------------------------------------------------------------------------------------------------------
	void PinRaspi::setHigh(){

		string setval_str = "/sys/class/gpio/gpio" + pinNumber + "/value";
		ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
		if (!setvalgpio){
			cout << " OPERATION FAILED: Unable to set the value of GPIO" << pinNumber << " ." << endl;
		}

		setvalgpio << "1";//write value to value file
		setvalgpio.close();// close value file 

	}

	//------------------------------------------------------------------------------------------------------------------
	void PinRaspi::setLow(){

		string setval_str = "/sys/class/gpio/gpio" + pinNumber + "/value";
		ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
		if (!setvalgpio){
			cout << " OPERATION FAILED: Unable to set the value of GPIO" << pinNumber << " ." << endl;
		}

		setvalgpio << "0";//write value to value file
		setvalgpio.close();// close value file 

	}
	//------------------------------------------------------------------------------------------------------------------

} //namespace dmc

#endif // __linux__
