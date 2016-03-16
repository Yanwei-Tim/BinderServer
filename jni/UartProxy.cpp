//============================================================================
// Name        : UartProxy.h
// Author      : liujg
// Description : uart proxy
//============================================================================


#define LOG_TAG "uart_proxy"
#include <utils/Log.h>


#include "UartProxy.h"


UartProxy::UartProxy(CMCUUart* uart)
{
	m_pUart = uart;
}
UartProxy::~UartProxy()
{
	if(m_pUart != NULL)
	{
		m_pUart->~CMCUUart();
		m_pUart = NULL;
	}
}

CMCUUart* UartProxy::getUart()
{
	if(m_pUart == NULL)
	{
		ALOGE("error: m_pUart is a null point");
	}
	return m_pUart;
}

