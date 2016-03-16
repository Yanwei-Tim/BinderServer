
#include <string.h>

#include "BTProvider.h"


BTProvider::BTProvider()
{
	memset(&m_pBTData, 0, sizeof(m_pBTData));
}
BTProvider::~BTProvider()
{
	//parent destructor method will be called;
	//~UartProxy();
}

S_BT_DATA_ALLINFO* BTProvider::getBTDataPtr()
{
	return &m_pBTData;
}

u_c BTProvider::get_bt_status()
{
	return getBTDataPtr()->btHfState;
}
void BTProvider::get_incoming_number(char* number)
{
	memcpy(number, getBTDataPtr()->btInComingStr, sizeof(getBTDataPtr()->btInComingStr));
}


