#ifndef bt_test_h
#define bt_test_h

#include "mcu_uart/CMCUUart.h"
#include "UartProxy.h"
#include "BTReader.h"

using namespace android;


class BTCommands : UartProxy
{
public:
	
	BTCommands(CMCUUart* uart, sp<BTReader>& reader);
	virtual ~BTCommands();

	//add commands blow it
	bool sendStartCommandToBT();
private:
	sp<BTReader> m_pBTReader;

};







#endif

