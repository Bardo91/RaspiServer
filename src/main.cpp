////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/22
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <peripherals/GPIO/Pin.h>
#include <peripherals/GPIO/Led.h>
#include <peripherals/GPIO/BackButton.h>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace dmc;

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	Led light("4");
	BackButton button("17");

	std::chrono::milliseconds ms(2000);
	for (;;){

		button.onLongPulse();
			cout << "El boton se ha pulsado" << endl;
			for (unsigned i = 0; i < 4; i++){
				light.on();
				std::this_thread::sleep_for(ms);
				light.off();
				std::this_thread::sleep_for(ms);
			}
		
		//cout << "Now is on" << endl;
		//std::this_thread::sleep_for(ms);
		//light.off();
		//cout << "Now is off" << endl;
		//std::this_thread::sleep_for(ms);
	}
	

	return 0;
}