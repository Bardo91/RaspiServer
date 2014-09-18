////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/27
// Author:	Pablo Ramon Soria
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Simple serial port communications

#ifdef __linux__

#include <iostream>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <cstring>
#include <cassert>

#include "SerialLinux.h"

namespace dmc {

	//------------------------------------------------------------------------------------------------------------------
	SerialLinux::SerialLinux(const char* _port, unsigned _baudRate){
		// Enforce correct data
		assert(nullptr != _port && '\0' != _port[0]);

		openPortFile(_port);
		
		// Gett addess info
		struct termios serialPortInfo;
		memset (&serialPortInfo, 0, sizeof(serialPortInfo)); // Clear memory

		if ( tcgetattr ( mFileDesc, &serialPortInfo ) != 0 ) // Get port address
			std::cout << "Error: Unable to open serial port " << _port << "\n";

		setBaudRate(&serialPortInfo, _baudRate, _port);

		serialPortInfo.c_cflag &= ~PARENB;    // Set no parity, no stop bits. Byte size = 8
		serialPortInfo.c_cflag &= ~CSTOPB;
		serialPortInfo.c_cflag &= ~CSIZE;
		serialPortInfo.c_cflag |= CS8; // 8-bit frame size
		serialPortInfo.c_cflag |= CREAD; // Enable reading
		serialPortInfo.c_cc[VMIN] = 1; // Always read at least one character
		serialPortInfo.c_cc[VTIME] = 0; // Disable time-out?

		cfmakeraw(&serialPortInfo); // Apply configuration;
		tcflush( mFileDesc, TCIFLUSH );	// Flush port to set atributes

		if ( tcsetattr ( mFileDesc, TCSANOW, &serialPortInfo ) != 0)	// Set attributes
			std::cout << "Error: Unable to set serial port attributes\n";
	}

	//------------------------------------------------------------------------------------------------------------------
	unsigned SerialLinux::write(const void* _src, unsigned _nBytes) {
		// Enforce correct input data
		assert(nullptr != _src);
		
		int writtenBytes = ::write( mFileDesc, _src, _nBytes);

		assert(-1 != writtenBytes);

		return writtenBytes;
	}

	//------------------------------------------------------------------------------------------------------------------
	bool SerialLinux::write(uint8_t _data) {
		return -1 != ::write( mFileDesc, &_data, 1);
	}


	//------------------------------------------------------------------------------------------------------------------
	unsigned SerialLinux::read(void * _dst, unsigned _nBytes){
	//Enforce correct output data
		assert(nullptr != _dst);

		int readBytes = ::read(mFileDesc, _dst , _nBytes);

		if(readBytes < 0)
			std::cout << "Error: reading from serial port failed\n";

		return readBytes;
	
	}

	//------------------------------------------------------------------------------------------------------------------
	uint8_t SerialLinux::read(){
		uint8_t data;
		unsigned nBytesRead = ::read(mFileDesc, &data , 1);
		if(nBytesRead < 0)
			std::cout << "Error: reading from serial port failed\n";

		assert(nBytesRead == 1);
		return data;

	}
	//------------------------------------------------------------------------------------------------------------------
	void SerialLinux::openPortFile(const char* _port) {
		mFileDesc = open(	_port,			// Port name
					O_RDWR );		// Read and write

		if(mFileDesc <= 0)
			std::cout << "Error: Unable to access file << " << _port << std::endl;
	}

	//------------------------------------------------------------------------------------------------------------------
	void SerialLinux::setBaudRate(struct termios* _serialPortInfo, unsigned _baudRate, const char* _port)
	{
		// Actually select address
		speed_t commBaudRate;
		switch (_baudRate) {
		case 4800:	
			commBaudRate = (speed_t)B4800;
			break;
		case 9600:	
			commBaudRate = (speed_t)B9600;
			break;
		case 19200:	
			commBaudRate = (speed_t)B19200;
			break;
		case 38400:	
			commBaudRate = (speed_t)B38400;
			break;
		case 57600:	
			commBaudRate = (speed_t)B57600;
			break;
		case 115200:	
			commBaudRate = (speed_t)B115200;
			break;
		default:
			commBaudRate = (speed_t)B115200;
			assert(false); // Unsupported baudrate
			return;
		}

		cfsetospeed (_serialPortInfo, commBaudRate);
		cfsetispeed (_serialPortInfo, commBaudRate);
	}

}	// namespace dmc

#endif // _linux_
