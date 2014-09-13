////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Sep/13
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DMCSERVER_SERVICE_CLIENT_COMMANDS_SCANCOMMAND_H_
#define _DMCSERVER_SERVICE_CLIENT_COMMANDS_SCANCOMMAND_H_

#include <service/command.h>

namespace dmc {

	class Client;
	class Message;

	class ScanCommand : public CommandBase<ScanCommand> {
	public:
		ScanCommand(unsigned _client, const Message&);
		void run() override;

	private:
		Client* mRequester;
	};
}	// namespace dmc

#endif // _DMCSERVER_SERVICE_CLIENT_COMMANDS_SCANCOMMAND_H_