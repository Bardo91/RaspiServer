////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Sep/12
// Author:	Jose Enrique Corchado Miralles
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef _RASPI
#include "PinControllerRaspi.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

namespace dmc{

	//------------------------------------------------------------------------------------------------------------------
	PinControllerRaspi::PinControllerRaspi(string _Pin){
		pinNumber = _Pin;
	}

	//------------------------------------------------------------------------------------------------------------------

	int PinControllerRaspi::sentOut(){
	
		string export_str = "/sys/class/gpio/export";
		ofstream exportgpio(export_str.c_str()); //Open export file declared before, and convert C++ strign into C string
		if(exportgpio < 0){
			cout << "OPERATION FAILED: Unable to export GPIO" << pinNumber << "." endl;
			return -1		
		}
		
	}

	//------------------------------------------------------------------------------------------------------------------


}

#endif // _RASPI
