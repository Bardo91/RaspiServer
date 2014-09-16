////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/25
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Simple serial port communications
#ifndef _DMCSERVER_PERIPHERALS_PLC_SERIALLINUX_H_
#define _DMCSERVER_PERIPHERALS_PLC_SERIALLINUX_H_

#ifdef __linux__

#include <cstdint>

namespace dmc {

	class SerialLinux {
	public:
		unsigned	write	(const void* _src, unsigned _nBytes);
		bool		write	(uint8_t);

		unsigned	read (void * _dst, unsigned _nBytes); // Returns the amount of bytes read
		uint8_t		read (); // Reads one byte

	protected:
		SerialLinux			(const char* _port, unsigned _baudRate);

	private:
		void openPort		(const char* _port);
		void setBaudRate	(unsigned _baudRate);
		
	private:
		int		mFileDesc;
	};

	typedef SerialLinux SerialBase;

}	// namespace dmc

#endif // __linux__
#endif // _DMCSERVER_PERIPHERALS_PLC_SERIALLINUX_H_
