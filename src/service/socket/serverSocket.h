////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/22
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DMCSERVER_SERVICE_SOCKET_SERVERSOCKET_H_
#define _DMCSERVER_SERVICE_SOCKET_SERVERSOCKET_H_

#include <map>
#include <mutex>
#include <string>
#include <thread>

namespace dmc {

	class ServerSocket {
	public:
		ServerSocket(int _socketDescriptor);
		~ServerSocket();
		// Write a message to the specified client
		// Return true on exit, false on fail
		bool write		(const std::string& _msg);
		// Return true if something was read
		bool read	(std::string& _msg);

		bool isOwned	() const { return mOwned; }
		void own		() { assert(!mOwned); mOwned = true; }
		void release	() { assert(mOwned); mOwned = false; }

	private:
		void listen ();

	private:
		int mSocket;
		bool mOwned;
		bool mMustClose;
		std::thread mListenThread;
		std::mutex mReadLock;
		std::string mInBuffer;
	};

}

#endif // _DMCSERVER_SERVICE_SOCKET_SERVERSOCKET_H_