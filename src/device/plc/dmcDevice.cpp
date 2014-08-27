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
	DmcDevice::DmcDevice(unsigned _id)
		:Device(_id)
	{
		DmcCommand::registerFactory(unsigned(Message::On));
		DmcCommand::registerFactory(unsigned(Message::Off));
		DmcCommand::registerFactory(unsigned(Message::Dimmer));
	}

	//---------------------------------------------------------------------------------------------------------------------
	void DmcDevice::turnOn() {
		// Send on message
		PLCDriver::get()->sendCommand(id(), std::string()+char(Message::On));
	}

	//---------------------------------------------------------------------------------------------------------------------
	void DmcDevice::turnOff() {
		// Send off message
		PLCDriver::get()->sendCommand(id(), std::string()+char(Message::Off));
	}

	//---------------------------------------------------------------------------------------------------------------------
	void DmcDevice::dimm(unsigned) {
		// Send dimm message
		PLCDriver::get()->sendCommand(id(), std::string()+char(Message::Dimmer));
	}

}	// namespace dmc