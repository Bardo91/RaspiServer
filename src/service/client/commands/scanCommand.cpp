////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Sep/13
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "scanCommand.h"
#include <service/client/client.h>
#include <service/scan/deviceScanner.h>

namespace dmc {

	//------------------------------------------------------------------------------------------------------------------
	ScanCommand::ScanCommand(unsigned, const Message&) {
		// Intentionally blank
	}

	//------------------------------------------------------------------------------------------------------------------
	void ScanCommand::run() {
		std::cout << "Run scan command\n";
		DeviceScanner::get()->startScan([this](Device* _foundDev) {
			mRequester->notifyFoundDevice(_foundDev);
		});

	}

}	// namespace dmc