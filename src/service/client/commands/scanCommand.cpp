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
	ScanCommand::ScanCommand(const Message& _msg)
		:mRequester(_msg.sender())
	{
		// Intentionally blank
	}

	//------------------------------------------------------------------------------------------------------------------
	void ScanCommand::run() {
		std::cout << "Run scan command\n";
		DeviceScanner::get()->startScan([this](Device* _foundDev) {
			mRequester->notifyNewDevice(_foundDev);
		});

	}

}	// namespace dmc