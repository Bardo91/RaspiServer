////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/22
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "peripherals/GPIO/Pin.h"
#include "peripherals/GPIO/Led.h"
#include <iostream>
#include <unistd.h>

using namespace std;
using namespace dmc;

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	Led light("4");

	while (1){

			light.on();
			cout << "Now is on" << endl;
			usleep(50000);
			
			light.off();
			cout << "Now is off" << endl;
 			usleep(50000);

	}

	return 0;
}