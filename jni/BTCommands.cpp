#define LOG_TAG "bt_commands"
#include <utils/Log.h>


#include "BTCommands.h"



BTCommands::BTCommands(CMCUUart* uart, sp<BTReader>& reader)
	:UartProxy(uart)

{
	m_pBTReader = reader;
}
BTCommands::~BTCommands()
{
	//parent destructor method will be called;
	//~UartProxy();
	if(m_pBTReader != NULL)
	{
		m_pBTReader->~BTReader();
	}
}

//add commands blow it
bool BTCommands::sendStartCommandToBT()
{
	CMCUUart* bt = getUart();
	if(bt != NULL)
	{
		u_c buffSendData[7] = {'A','T','#','C','Y','\r','\n'};
		bt->writeUart(buffSendData,7);
		return true;
	}
	return false;
}





