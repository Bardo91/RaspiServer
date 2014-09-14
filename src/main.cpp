////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/22
// Author:	Carmelo J. Fdez-Ag�era Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "peripherals/GPIO/Pin.h"
#include "peripherals/GPIO/Led.h"
#include <iostream>
#include <unistd.h>

using namespace std;
using namespace dmc;

//----------------------------------------------------------------------------------------------------------------------
int main(void)
{
	Led light("4");

	while (1){

			light.on();
			cout << "Now is on" << endl;
			sleep(5);
			
			light.off();
			cout << "Now is off" << endl;
 			sleep(5);

	}

	return 0;
}