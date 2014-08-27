////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/27
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DMCSERVER_SERVICE_COMMAND_H_
#define _DMCSERVER_SERVICE_COMMAND_H_

#include <functional>
#include <map>
#include "message.h"

namespace dmc {

	//------------------------------------------------------------------------------------------------------------------
	class Command {
	public:
		~Command();
		static Command* createCommand(const Message&);

		void run();

	protected:
		typedef std::function<Command*(const Message&)>	Factory;
		static void registerChildFactory(Factory _childFactory);
		Command() = default;

		static std::map<unsigned, Factory>	sChildFactories;
	};

	//------------------------------------------------------------------------------------------------------------------
	template<typename ChildCommand>
	class CommandBase : public Command {
	public:
		static void registerFactory() {
			registerChildFactory([](const Message& _msg){
				return new ChildCommand(_msg);
			});
		}
	};

}	// namespace dmc

#endif // _DMCSERVER_SERVICE_COMMAND_H_