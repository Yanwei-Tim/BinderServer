/*
 * CUartCtrl.cpp
 *
 *  Created on: 2016-02-23
 *      Author: liujg
 *
 *  proxy for class CMCUUart
 */



#ifndef UART_PROXY_H
#define UART_PROXY_H

#include "mcu_uart/CMCUUart.h" 


class UartProxy
{
public:
	UartProxy(CMCUUart* uart);
	virtual ~UartProxy();
	CMCUUart* getUart();
private:
	CMCUUart* m_pUart;

};




#endif


