////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/25
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DMCSERVER_SERVICE_EVENT_H_
#define _DMCSERVER_SERVICE_EVENT_H_

#include <vector>

namespace dmc {

	template<typename Listener_>
	class Event {
	public:
		void operator()(typename Listener_::argument_type _arg) {
			for(auto& listener : mListeners)
				listener(_arg);
		}

		void operator+=(const Listener_& _l)	{ mListeners.push_back(_l); }
		void operator+=(Listener_&& _l)			{ mListeners.push_back(_l); }

	private:
		std::vector<Listner_>	mListeners;
	};
}

#endif // _DMCSERVER_SERVICE_EVENT_H_