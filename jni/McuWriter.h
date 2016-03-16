/*
 * 	McuWriter.h
 *
 *  Created on: 2016-02-19
 *      Author: liujg
 */


#ifndef MCU_WRITER_H
#define MCU_WRITER_H

#include <utils/threads.h>

#include "mcu_uart/CMCUUart.h"
#include "McuReader.h"
#include "McuCommands.h"

using namespace android;

class McuWriter : public Thread, public McuCommands
{
public:
	McuWriter(CMCUUart* mcuuart, sp<McuReader>& reader);
	virtual ~McuWriter();
	void start_write_mcu_data_loop();
private:
	virtual bool threadLoop();
};

#endif

