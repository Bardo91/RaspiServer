////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/27
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DMCSERVER_DEVICE_PLC_DMCCOMMAND_H_
#define _DMCSERVER_DEVICE_PLC_DMCCOMMAND_H_

#include <service/command.h>
#include <service/message.h>

namespace dmc {

	class DmcCommand : public CommandBase<DmcCommand> {
	public:
		DmcCommand(const Message&);
		void run() override;
	};

}	// namespace dmc

#endif // _DMCSERVER_DEVICE_PLC_DMCCOMMAND_H_