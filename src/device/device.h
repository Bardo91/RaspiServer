////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/27
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DMCSERVER_DEVICE_DEVICE_H_
#define _DMCSERVER_DEVICE_DEVICE_H_

#include "deviceMgr.h"
#include <string>

namespace dmc {

	class Device;

	class Device {
	public:
		virtual unsigned	id	() const final	{ return mId; }
		const std::string&	name() const		{ return mName; }
			  std::string&	name()				{ return mName; }

	protected:
		Device		(unsigned _id, const std::string& _name)
			: mId(_id) 
			, mName(_name)
		{
			DeviceMgr::get()->registerDevice(this);
		}

	private:
		unsigned	mId;
		std::string mName;
	};

}	// namespace dmc

#endif // _DMCSERVER_DEVICE_DEVICE_H_