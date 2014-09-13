////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Sep/12
// Author:	Jose Enrique Corchado Miralles
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef __linux__
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
		unexportPin(_Pin);
		pinNumber = _Pin
	}

	//------------------------------------------------------------------------------------------------------------------
	PinControllerRaspi::exportPin(string _Pin){
	
		string export_str = "/sys/class/gpio/export";
		ofstream exportgpio(export_str.c_str()); // Open "export" file. Convert C++ string to C string. Required for all Linux pathnames
		if (exportgpio < 0){
			cout << " OPERATION FAILED: Unable to export GPIO"<< _Pin <<" ."<< endl;
			return -1;
		}

		exportgpio << _Pin; //write GPIO number to export
		exportgpio.close(); //close export file
		return 0;
	
	
	}
	
	//------------------------------------------------------------------------------------------------------------------
	
	string PinControllerRaspi::readPin(){
		string val;
		string getval_str = "/sys/class/gpio/gpio" + pinNumber + "/value";
		ifstream getvalgpio(getval_str.c_str());// open value file for gpio
		if (getvalgpio < 0){
			cout << " OPERATION FAILED: Unable to get value of GPIO"<< pinNumber <<" ."<< endl;
			return -1;
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

	int PinControllerRaspi::inputPin(){
	
		string setdir_str ="/sys/class/gpio/gpio" + pinNumber + "/direction";
		ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
		if (setdirgpio < 0){
			cout << " OPERATION FAILED: Unable to set direction of GPIO"<< pinNumber <<" ."<< endl;
			return -1;
		}

		setdirgpio << "in"; //write direction to direction file
		setdirgpio.close(); // close direction file
		return 0;
			
		
		
	}

	//------------------------------------------------------------------------------------------------------------------

	int PinControllerRaspi::outPutPin(){

		string setdir_str ="/sys/class/gpio/gpio" + pinNumber + "/direction";
		ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
		if (setdirgpio < 0){
			cout << " OPERATION FAILED: Unable to set direction of GPIO"<< pinNumber <<" ."<< endl;
			return -1;
		}

		setdirgpio << "out"; 
		setdirgpio.close(); // close direction file
		return 0;
		

	}

	//------------------------------------------------------------------------------------------------------------------

	int PinControllerRaspi::on(){

		string setval_str = "/sys/class/gpio/gpio" + pinNumber + "/value";
		ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
		if (setvalgpio < 0){
			cout << " OPERATION FAILED: Unable to set the value of GPIO"<< pinNumber <<" ."<< endl;
			return -1;
		}

		setvalgpio << "1" ;//write value to value file
		setvalgpio.close();// close value file 
		return 0;


	}

	//------------------------------------------------------------------------------------------------------------------

	int PinControllerRaspi::off(){

		string setval_str = "/sys/class/gpio/gpio" + pinNumber + "/value";
		ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
		if (setvalgpio < 0){
			cout << " OPERATION FAILED: Unable to set the value of GPIO"<< pinNumber <<" ."<< endl;
			return -1;
		}

		setvalgpio << "0" ;//write value to value file
		setvalgpio.close();// close value file 
		

		
		return 0;



	}

	//------------------------------------------------------------------------------------------------------------------
}

#endif // __linux__
