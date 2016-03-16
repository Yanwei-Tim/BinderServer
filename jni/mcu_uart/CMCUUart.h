//============================================================================
// Name        : CUartCtrl.cpp
// Author      : liujg
// Description : uart read and write tool
//============================================================================


#ifndef CUARTCTRL_H_
#define CUARTCTRL_H_

#include <termios.h>
#include "IncludeAll.h"
 
#define MCU_UART_NAME   ("/dev/ttyS1")
//#define MCU_UART_NAME   ("/dev/ttyMbx3")
//#define MCU_UART_NAME   ("/dev/ttyS2")
#define BT_UART_NAME 	("/dev/ttyS3")

class CMCUUart
{
public:
	CMCUUart();
	~CMCUUart();
	bool openUartDev(const char* uartName, u_t baudRate);
	bool isUartOpened(void);
	bool writeUart(const u_c* buff, u_t len);
	bool readUart(u_c* buff, u_t& len);
	bool closeUartDev(void);
	void enabledDebug(bool enabled);
	
private:
	int m_fd;
	bool debug;
//	handler_signal signal;
	bool m_bUartOpen;
};


#endif /* CUARTCTRL_H_ */

