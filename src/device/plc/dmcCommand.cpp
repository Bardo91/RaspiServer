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
#include <service/command.h>
#include <service/message.h>

namespace dmc {

	//------------------------------------------------------------------------------------------------------------------
	DmcCommand::DmcCommand(const Message& _msg)
		:mSrcCommand(_msg)
	{
		assert(mSrcCommand.size() > 2); // Should contain at least size, command and id
		// Intentionally blank
	}

	//------------------------------------------------------------------------------------------------------------------
	void DmcCommand::run() {
		// Find device
		unsigned targetId = mSrcCommand.payload()[0];
		DmcDevice* targetDev = static_cast<DmcDevice*>(DeviceMgr::get()->getDevice(targetId));
		// Run command
		targetDev->runCommand(mSrcCommand.payload());
	}

}	// namespace dmc