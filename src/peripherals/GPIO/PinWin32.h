////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Sep/12
// Author:	Jose Enrique Corchado Miralles
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GPIO controller
#ifndef _DMCSERVER_PERIPHERALS_GPIO_PINWIN32_H_
#define _DMCSERVER_PERIPHERALS_GPIO_PINWIN32_H_

#ifdef _WIN32
#include <Windows.h>
#include <string>

using namespace std;

namespace dmc{

	class PinWin32{
	public:
		PinWin32(string _Pin); // _PinNumber is passed by the constructor, it also export the pin number. //assert para el pin18
		~PinWin32();


		bool		read		();					//TODO 666 Check if this function works ok.
		void		input		();
		void		outPut		();
		void		setHigh		();
		void		setLow		();
	private:
		std::string	pinNumber;
		void		exportPin		(std::string _Pin);
		void		unexportPin		(std::string _Pin);

		//export y unexport constructor y destructor
	};

	typedef PinWin32 PinBase;
	
}//namespace dmc


#endif // _WIN32
#endif // _DMCSERVER_PERIPHERALS_GPIO_PINWIN32_H_