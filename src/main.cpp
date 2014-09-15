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
#include <thread>
#include <chrono>

using namespace std;
using namespace dmc;

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	Led light("4");
	std::chrono::milliseconds ms(2000);
	for (;;){

		light.on();
		cout << "Now is on" << endl;
		std::this_thread::sleep_for(ms);
		light.off();
		cout << "Now is off" << endl;
		std::this_thread::sleep_for(ms);
	}
	

	return 0;
}