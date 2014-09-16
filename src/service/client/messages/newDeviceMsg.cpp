////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Sep/14
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "newDeviceMsg.h"
#include <device/device.h>

namespace dmc {

	//------------------------------------------------------------------------------------------------------------------
	NewDeviceMsg::NewDeviceMsg(const Device& _dev)
		:Message(Type::DeviceInfo, "")
	{
		mRaw += char(_dev.type());
		mRaw += char(_dev.id()); 
		mRaw += _dev.name();
		mSize = mRaw.size();
		mRaw[0] = char(mRaw.size()+2); // Update information about my size
	}

}