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
#include <core/time.h>
#include <service/scan/deviceScanner.h>
#include <service/client/commands/scanCommand.h>
#include <service/lanService.h>

namespace dmc {

	//------------------------------------------------------------------------------------------------------------------
	BackButton::BackButton(std::string _Pin) : ButtonPin(_Pin){
		
		ButtonPin.input();
		cout << "button set as input" << endl;
		mThread = std::thread([this](){
			cout << "button thread is running" << endl;
			double measuredTime = Time::get()->getTime();
			bool lastState = false;

			while (!mMustClose){
				if (ButtonPin.read() == true && lastState == false){				
					measuredTime = Time::get()->getTime();
					cout << "on High edge" << endl;
					lastState = true;
				}
				else if (ButtonPin.read() == false && lastState == true){					
					cout << "on low edge" << endl;
					mPulseDuration = Time::get()->getTime() - measuredTime;
					cout << "pulse duration " << mPulseDuration << endl;
					lastState = false;
					if (mPulseDuration > mThresHold){
						cout << "it is a long pulse" << endl;
						onLongPulse();
					}
					else{
						onShortPulse();
						cout << "it is a short pulse" << endl;
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

		DeviceScanner::get()->startScan([this](Device*){
			DeviceScanner::get()->stopScan(); // Done scanning, just one device at a time
			Message notification(Message::NewDevice, std::string() + char(1)); // 1 device found
			LANService::get()->broadCast(notification);
			
		});

		cout << "On long pulse" << endl;
	
	}

	//------------------------------------------------------------------------------------------------------------------
	void BackButton::onShortPulse(){
		cout << "On short pulse" << endl;
	}

	//------------------------------------------------------------------------------------------------------------------
	
} //namespace dmc