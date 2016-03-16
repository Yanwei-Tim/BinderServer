/*
 * McuReader.h
 *
 *  Created on: 2016-02-19
 *      Author: liujg
 */


#ifndef MCU_READER_H
#define MCU_READER_H

#include "utils/threads.h"

//#include "McuService.h"
#include "mcu_uart/CMCUUart.h"
#include "IncludeAll.h"
#include "McuProvider.h"

using namespace android;

class McuReader : public Thread, public McuProvider, public UartProxy
{
public:
	McuReader(CMCUUart* uart);
	virtual ~McuReader();
	virtual void start_read_mcu_data_loop();
private:
	virtual bool threadLoop();
	void start_parse_data(const u_c ptr[], int len);
	int parse_data_inner(parse_state& state);
	void parse_single_cmd(const u_c[], int);
	void parse_sysinfo(const u_c[], int);
	void parse_setupinfo(const u_c[], int);
};

#endif

