////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Sep/14
// Author:	Jose Enrique Corchado Miralles
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "BackButton.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include "core/time.h"

namespace dmc {

	//------------------------------------------------------------------------------------------------------------------
	BackButton::BackButton(std::string _Pin) : ButtonPin(_Pin){
		
		ButtonPin.input(); 
		mThread = std::thread([this](){
			double measuredTime = getTime();
			bool lastState = false;

			while (!mMustClose){
				if (ButtonPin.read() == true && lastState == false){				
					measuredTime = getTime();
					lastState = true;
				}
				else if (ButtonPin.read() == false && lastState == true){					
					mPulseDuration = getTime() - measuredTime;
					lastState = false;
					if (mPulseDuration > mThresHold){
						onLongPulse();
					}
					else{
						onShortPulse();
					}

				}
			}
		
		});

	}

	//------------------------------------------------------------------------------------------------------------------
	BackButton::~BackButton(){
	
		mMustClose = true;
		mThread.join();
	
	}
	
	//------------------------------------------------------------------------------------------------------------------
	void BackButton::onLongPulse(){
	
	}

	//------------------------------------------------------------------------------------------------------------------
	void BackButton::onShortPulse(){

	}

	//------------------------------------------------------------------------------------------------------------------
	
} //namespace dmc