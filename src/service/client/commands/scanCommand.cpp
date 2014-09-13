////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Sep/13
// Author:	Carmelo J. Fdez-Ag�era Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "scanCommand.h"

namespace dmc {

	//------------------------------------------------------------------------------------------------------------------
	ScanCommand::ScanCommand(unsigned, const Message&) {
		// Intentionally blank
	}

	//------------------------------------------------------------------------------------------------------------------
	void ScanCommand::run() {
		std::cout << "Run scan command\n";
	}

}	// namespace dmc