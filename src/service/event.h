////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/25
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DMCSERVER_SERVICE_EVENT_H_
#define _DMCSERVER_SERVICE_EVENT_H_

#include <functional>
#include <vector>

namespace dmc {

	template<typename ... Arg_>
	class Event {
	public:
		typedef std::function<void (Arg_...)>	Listener;

		void operator()(Arg_ ... _arg) {
			for(auto& listener : mListeners)
				listener(_arg);
		}

		void operator+=(const Listener& _l)	{ mListeners.push_back(_l); }
		void operator+=(Listener&& _l)			{ mListeners.push_back(_l); }

	private:
		std::vector<Listener>	mListeners;
	};
}

#endif // _DMCSERVER_SERVICE_EVENT_H_