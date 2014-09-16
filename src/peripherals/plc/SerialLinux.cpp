////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/27
// Author:	Pablo Ramon Soria
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Simple serial port communications

#ifdef __linux__

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

		openPort(_port);
		setBaudRate(_baudRate);
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

		assert(-1 != readBytes);

		return readBytes;
	
	}

	//------------------------------------------------------------------------------------------------------------------
	uint8_t SerialLinux::read(){
		uint8_t data;
		int readBytes = ::read(mFileDesc, &data , 1);

		assert(-1 != data);

		return data;

	}
	//------------------------------------------------------------------------------------------------------------------
	void SerialLinux::openPort(const char* _port) {
		mFileDesc = open(	_port,			// Port name
					O_RDWR |		// Read and write
					O_NONBLOCK);	// Nonblocking mode

		assert(0 < mFileDesc);
	}

	//------------------------------------------------------------------------------------------------------------------
	void SerialLinux::setBaudRate(unsigned _baudRate)
	{
		struct termios tty;
		memset (&tty, 0, sizeof tty);

		if ( tcgetattr ( mFileDesc, &tty ) != 0 )
		{
			assert(false);
			//cout << "Error " << errno << " from tcgetattr: " << strerror(errno) << endl;
		}

		switch (_baudRate) {
		case 4800:	cfsetospeed (&tty, B4800);		break;
		case 9600:	cfsetospeed (&tty, B9600);		break;
		case 19200:	cfsetospeed (&tty, B19200);		break;
		case 57600:	cfsetospeed (&tty, B57600);		break;
		case 115200:cfsetospeed (&tty, B115200);	break;
		default:
			assert(false); // Unsupported baudrate
			return;
		}
	
		// Configure Attributes
		
		tty.c_cflag &= ~PARENB;    // Set no parity, no stop bits and no data bits. Byte size = 8
		tty.c_cflag &= ~CSTOPB;
		tty.c_cflag &= ~CSIZE;
		tty.c_cflag |= CS8;

		tcflush( mFileDesc, TCIFLUSH );	// Flush port to set atributes

		if ( tcsetattr ( mFileDesc, TCSANOW, &tty ) != 0)	// Set attributes
		{
			assert(false);
			//cout << "Error " << errno << " from tcsetattr" << endl;
		}
	}

}	// namespace dmc

#endif // _linux_
