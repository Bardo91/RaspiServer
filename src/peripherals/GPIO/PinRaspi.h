////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Sep/12
// Author:	Jose Enrique Corchado Miralles
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _DMCSERVER_PERIPHERALS_GPIO_PINRASPI_H_ 
#define _DMCSERVER_PERIPHERALS_GPIO_PINRASPI_H_

#ifdef __Raspi__

#include <string>

namespace dmc{

	class PinRaspi{
	public:
		PinRaspi(std::string _Pin); // _PinNumber is passed by the constructor, it also export the pin number. 
		~PinRaspi();
		
		
		bool		read		();					//TODO 666 Check if this function works ok.
		void		input		();
		void		outPut		();
		void		setHigh		();
		void		setLow		();

	private:
		string		pinNumber; 
		void		export		(string _Pin);
		void		unexport	(string _Pin);

	};

	typedef PinRaspi PinBase;

}//namespace dmc


#endif // __Raspi__
#endif // _DMCSERVER_PERIPHERALS_GPIO_PINRASPI_H_