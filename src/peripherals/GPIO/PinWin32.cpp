////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Sep/12
// Author:	Jose Enrique Corchado Miralles
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef _WIN32
#include "PinWin32.h"
#include <iostream>
#include <assert.h>

using namespace std;

namespace dmc{
	//------------------------------------------------------------------------------------------------------------------
	PinWin32::PinWin32(string _Pin){
		pinNumber = _Pin;
		exportPin(pinNumber);
	}

	//------------------------------------------------------------------------------------------------------------------
	PinWin32::~PinWin32(){
		unexportPin(pinNumber);
	}

	//------------------------------------------------------------------------------------------------------------------
	void PinWin32::exportPin(string _Pin){
		cout << "pin exported" << endl;
	}

	//------------------------------------------------------------------------------------------------------------------
	void PinWin32::unexportPin(string _Pin){
		cout << "pin unexported" << endl;
	}

	//------------------------------------------------------------------------------------------------------------------
	bool PinWin32::read(){
		return true;
	}

	//------------------------------------------------------------------------------------------------------------------
	void PinWin32::input(){
		cout << "Set as input" << endl;
	}

	//------------------------------------------------------------------------------------------------------------------
	void PinWin32::outPut(){
		cout << "Set as output" << endl;
	}

	//------------------------------------------------------------------------------------------------------------------
	void PinWin32::setHigh(){
		cout << "Set high" << endl;
	}

	//------------------------------------------------------------------------------------------------------------------
	void PinWin32::setLow(){
		cout << "Set low" << endl;
	}
	//------------------------------------------------------------------------------------------------------------------

}// namespace dmc

#endif // _WIN32