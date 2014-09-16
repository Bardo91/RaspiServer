////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/27
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "dmcDevice.h"
#include <device/plc/dmcCommand.h>
#include <peripherals/plc/plcDriver.h>
#include <string>

namespace dmc {

	//---------------------------------------------------------------------------------------------------------------------
	DmcDevice::DmcDevice(unsigned _id, const std::string& _name)
		:Device(0x01, _id, _name)
	{
		DmcCommand::registerFactory(unsigned(Message::On));
		DmcCommand::registerFactory(unsigned(Message::Off));
		DmcCommand::registerFactory(unsigned(Message::Dimmer));
	}

	//---------------------------------------------------------------------------------------------------------------------
	void DmcDevice::runCommand(const std::string& _plcCommand) {
		PLCDriver::get()->sendCommand(id(), _plcCommand);
	}

}	// namespace dmc