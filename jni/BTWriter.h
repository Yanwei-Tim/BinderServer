/*
 * 	BTWriter.h
 *
 *  Created on: 2016-02-22
 *      Author: liujg
 */


#ifndef BT_WRITER_H
#define BT_WRITER_H

#include <utils/threads.h>

#include "mcu_uart/CMCUUart.h"
#include "BTReader.h"
#include "BTCommands.h"

using namespace android;

class BTWriter : public Thread, public BTCommands
{
public:
	BTWriter(CMCUUart* uart, sp<BTReader>& reader);
	virtual ~BTWriter();
	void start_write_bt_data_loop();
private:
	virtual bool threadLoop();
};

#endif

