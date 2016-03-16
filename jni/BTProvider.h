//============================================================================
// Name        : BTProvider.h
// Author      : liujg
// Description : provider virous of methods to get bt info
//============================================================================



#ifndef BT_PROVIDER_H
#define BT_PROVIDER_H

#include "UartProxy.h"
#include "IncludeAll.h"


class BTProvider
{
public:
	BTProvider();
	~BTProvider();
	S_BT_DATA_ALLINFO* getBTDataPtr();

	
	u_c get_bt_status();
	void get_incoming_number(char* number);
private:
	S_BT_DATA_ALLINFO m_pBTData;
};




#endif


