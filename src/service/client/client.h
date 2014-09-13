////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Sep/12
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DMCSERVER_SERVICE_CLIENT_H_
#define _DMCSERVER_SERVICE_CLIENT_H_

namespace dmc {

	class Client {
	public:
		Client(unsigned _connectionId);
		~Client();

		bool update(); // Returns true if the client must be deleted

	private:
		void registerCommands();
		void readMessage();

		unsigned mId;
	};

}	// namespace dmc

#endif // _DMCSERVER_SERVICE_CLIENT_H_