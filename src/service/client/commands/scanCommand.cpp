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
#include <service/client/messages/newDeviceMsg.h>
#include <service/message.h>
#include <service/scan/deviceScanner.h>
#include <service/lanService.h>

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
		DeviceScanner::get()->startScan([this](Device* _dev) {
			DeviceScanner::get()->stopScan(); // Done scanning, just one device at a time
			Message notification(Message::NewDevice, std::string()+char(1)); // 1 device found
			LANService::get()->broadCast(notification);
			NewDeviceMsg deviceInfo(*_dev);
			LANService::get()->broadCast(deviceInfo);
		});

	}

}	// namespace dmc