////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/27
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DMCSERVER_DEVICE_DEVICE_H_
#define _DMCSERVER_DEVICE_DEVICE_H_

namespace dmc {

	class Device;

	class Device {
	public:
		virtual unsigned id() const final { return mId; }

	protected:
		Device		(unsigned _id) : mId(_id) {}

	private:
		unsigned	mId;
	};

}	// namespace dmc

#endif // _DMCSERVER_DEVICE_DEVICE_H_