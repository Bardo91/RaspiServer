////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/27
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "dmcCommand.h"

#include <cassert>
#include <cstdint>
#include <device/deviceMgr.h>
#include <device/plc/dmcDevice.h>
#include <iostream>
#include <service/command.h>
#include <service/message.h>

namespace dmc {

	//------------------------------------------------------------------------------------------------------------------
	DmcCommand::DmcCommand(unsigned, const Message& _msg)
		:mSrcCommand(_msg)
	{
		assert(mSrcCommand.payload().size()); // Should contain at least target device id
	}

	//------------------------------------------------------------------------------------------------------------------
	void DmcCommand::run() {
		// Find device
		unsigned targetId = mSrcCommand.payload()[0];
		DmcDevice* targetDev = static_cast<DmcDevice*>(DeviceMgr::get()->getDevice(targetId));
		if(!targetDev) {
			std::cout << "Error: Trying to run command on inexisting device (devId = " << targetId << ")\n";
			return;
		}
		// Run command
		targetDev->runCommand(mSrcCommand.payload());
	}

}	// namespace dmc