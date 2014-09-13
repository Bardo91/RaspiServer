////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/22
// Author:	Carmelo J. Fdez-Ag�era Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "dmcServer.h"
#include "peripherals\GPIO\PinController.h"
#include <iostream>

using namespace std;
using namespace dmc;

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	//Testing GPIO
	//it also call the function to export the pins into the specific file
	PinController pin4("4");
	PinController pin17("17");

	pin4.inputPin;
	pin17.outPutPin;
	
	string pinState;
	while (1){
		pinState = pin17.readPin;
		if (pinState == "0"){
			
			pin4.on;
			while (pinState == "0"){
				pinState = pin17.readPin;
			}
		}
		else{
			pin4.off;
			
		}

	}

	return 0;
}