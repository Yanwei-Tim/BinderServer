/*
 * CUartCtrl.cpp
 *
 *  Created on: 2014-8-8
 *  Edited on: 2016-02-19
 *      Author: liujg
 *
 *  This class providers various to the operation of the serial
 *	like open_uart, write_uart, read_uart.
 */
 
#define LOG_TAG "mcu_uart"
#define LOG_NDEBUG 0
#include <utils/Log.h>


#include "CMCUUart.h"
#include <fcntl.h>
#include <termios.h>
#include <pthread.h>
#include <signal.h>
#include <memory.h>
#include <unistd.h>

#define UART_DEBUG 0

#ifndef null
#define null ((void*)0);
#endif

CMCUUart::CMCUUart()
{
	closeUartDev();
	m_bUartOpen = false;
	m_fd = -1;
	debug = false;
//	signal = 0;
}

CMCUUart::~CMCUUart()
{
	ALOGI("mcu uart destory...");
	closeUartDev();
	m_bUartOpen = false;
	m_fd = -1;
	debug = false;
//	signal = 0;
}
bool CMCUUart::openUartDev(const char* devName, u_t baudRate)
{
	ALOGI("start open uart dev[%s]...", devName);
	//open dev 3 times
	for(int i=0; i<3; i++)
	{
		m_fd = open(devName, O_RDWR|O_NOCTTY);
		if(m_fd < 0)
			usleep(200*1000);
		else
			break;
	}

	if(m_fd < 0)
	{
		ALOGE("open %s error!!!", devName);
		m_bUartOpen = false;
		return false;
	}
	else
	{
		struct termios oldtio, newtio;
		tcgetattr(m_fd, &oldtio); /* save current serial port settings */
		memset(&newtio, 0, sizeof(newtio)); /* clear struct for new port settings */
		/*
		 BAUDRATE: Set bps rate. You could also use cfsetispeed and cfsetospeed.
		 CRTSCTS : output hardware flow control (only used if the cable has
		 all necessary lines. See sect. 7 of Serial-HOWTO)
		 CS8     : 8n1 (8bit,no parity,1 stopbit)
		 CLOCAL  : local connection, no modem contol
		 CREAD   : enable receiving characters
		 */
		newtio.c_cflag = baudRate | CS8 | CLOCAL | CREAD;

		/*
		 IGNPAR  : ignore bytes with parity errors
		 ICRNL   : map CR to NL (otherwise a CR input on the other computer
		 will not terminate input)
		 otherwise make device raw (no other input processing)
		 */
		newtio.c_iflag = 0; //IGNPAR | ICRNL;

		/*
		 Raw output.
		 */
		newtio.c_oflag = 0;

		/*
		 ICANON  : enable canonical input
		 disable all echo functionality, and don't send signals to calling program
		 */
		newtio.c_lflag = 0; //ICANON;

		/*
		 initialize all control characters
		 default values can be found in /usr/include/termios.h, and are given
		 in the comments, but we don't need them here
		 */
		newtio.c_cc[VINTR] = 0; /* Ctrl-c */
		newtio.c_cc[VQUIT] = 0; /* Ctrl-\ */
		newtio.c_cc[VERASE] = 0; /* del */
		newtio.c_cc[VKILL] = 0; /* @ */
		newtio.c_cc[VEOF] = 1; /* Ctrl-d */
		newtio.c_cc[VTIME] = 0; /* inter-character timer unused */
		newtio.c_cc[VMIN] = 1; /* blocking read until 1 character arrives */
		newtio.c_cc[VSWTC] = 0; /* '\0' */
		newtio.c_cc[VSTART] = 0; /* Ctrl-q */
		newtio.c_cc[VSTOP] = 0; /* Ctrl-s */
		newtio.c_cc[VSUSP] = 0; /* Ctrl-z */
		newtio.c_cc[VEOL] = 0; /* '\0' */
		newtio.c_cc[VREPRINT] = 0; /* Ctrl-r */
		newtio.c_cc[VDISCARD] = 0; /* Ctrl-u */
		newtio.c_cc[VWERASE] = 0; /* Ctrl-w */
		newtio.c_cc[VLNEXT] = 0; /* Ctrl-v */
		newtio.c_cc[VEOL2] = 0; /* '\0' */
		/*
		 now clean the modem line and activate the settings for the port
		 */
		tcflush(m_fd, TCIOFLUSH);
		tcsetattr(m_fd, TCSANOW, &newtio);
		fcntl(m_fd, F_SETFL, 0); //set block mode
		ALOGI("open %s successfully!!!", devName);
		m_bUartOpen = true;
		return true;
	}
}

bool CMCUUart::isUartOpened()
{
	return m_bUartOpen && m_fd >=0;
}

bool CMCUUart::writeUart(const u_c* buff, u_t len)
{
	if(!isUartOpened())
	{
		ALOGE("error:uart dev is not opend!!");
	}
	bool result = write(m_fd, buff, len);
	//if(*((BYTE*)buff+2) != 0x9E) //do not print heartbeat
	//{
		//ALOGI("-----------------send mcu data length %x", len);
		ALOGI("-----------------length[%x] data %x,%x,%x,%x,%x,%x,%x,%x,%x\r\n", \
			len,buff[2],buff[3],buff[4],buff[5],buff[6],buff[7],buff[8],buff[9],buff[10]);

		
		//for(int i=0;i<len;i++)
		//{
		//	ALOGI("send mcu data %02x",*((BYTE*)buff+i));
		//}
		//ALOGI("\r\n\r\n");
	//}
	
	if(!result)
		ALOGE("error:write data to mcu faild!",buff);
	return result;
}


//0xFF 0xAA len data0 data1... 0x0A
bool CMCUUart::readUart(u_c* buff, u_t& len)
{
	if(isUartOpened())
	{
		//is block, so do not need sleep
		len = read(m_fd, buff, sizeof(buff));
		if(len > 0)
		{
			return true;
		}
	}
	return false;
}

inline int get_current_time()
{
	struct timespec time;
	clock_gettime(CLOCK_MONOTONIC, &time);
	return (time.tv_sec*1000+(time.tv_nsec/(1000*1000)));
}


/*void CMCUUart::init_read_loop(parse_data _p, handler_signal _signal)
{
	m_parse_data = _p;
	signal = _signal;

	if(m_fd >=0 && isUartOpen() && signal != 0)
	{
		struct sigaction actions;
		memset(&actions, 0, sizeof(actions));
		sigemptyset(&actions.sa_mask);
		actions.sa_flags = 0;
		actions.sa_handler = signal;
		int result = sigaction(SIGTERM, &actions, 0);
		ALOGI("register SIGTERM handler returned: %d",result);
	}
}*/


bool CMCUUart::closeUartDev()
{
	if(isUartOpened())
	{
		close(m_fd);
		m_fd = -1;
		m_bUartOpen = false;
	}
	else
	{
		ALOGI("mcu uart is already closed");
	}
	return true;
}

void CMCUUart::enabledDebug(bool enabled)
{
	debug = enabled;
}





