/*
 * BTReader.h
 *
 *  Created on: 2016-02-20
 *      Author: liujg
 */


#ifndef BT_READER_H
#define BT_READER_H

#include "utils/threads.h"
 
#include "IncludeAll.h"
#include "mcu_uart/CMCUUart.h" 
#include "BTProvider.h"
#include "UartProxy.h"

using namespace android;

class BTReader : public BTProvider, public Thread, public UartProxy
{
public:
	BTReader(CMCUUart* uart);
	virtual ~BTReader();
	void start_read_bt_data_loop();
	
private:
	virtual bool threadLoop();
	void start_parse_data(const u_c ptr[], int len);
	int parse_data_inner(parse_state& state);
	void parse_single_cmd(const u_c[], int);
};

#endif

