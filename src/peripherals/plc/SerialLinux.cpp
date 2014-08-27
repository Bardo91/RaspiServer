////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project: DMC Server
// Date:	2014/Aug/27
// Author:	Carmelo J. Fdez-Agüera Tortosa
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Simple serial port communications

#ifdef _linux_

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

		return write( mFileDesc, cmd, _nBytes);;
	}

	//------------------------------------------------------------------------------------------------------------------
	bool SerialLinux::write(uint8_t _data) {
		return write( mFileDesc, cmd, 1);
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
		case 128000:cfsetospeed (&tty, B128000);	break;
		case 256000:cfsetospeed (&tty, B256000);	break;
		default:
			assert(false); // Unsupported baudrate
			return;
		}
	
		// Configure Attributes
		tty

		//dcb.ByteSize = 8;
		//dcb.fParity = FALSE;
		//dcb.Parity = 0;
		//dcb.StopBits = 0;

		tcflush( mFileDesc, TCIFLUSH );	// Flush port to set atributes

		if ( tcsetattr ( mFileDesc, TCSANOW, &tty ) != 0)	// Set attributes
		{
			assert(false);
			//cout << "Error " << errno << " from tcsetattr" << endl;
		}
	}

}	// namespace dmc

#endif // _linux_
