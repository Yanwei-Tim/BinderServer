
#define LOG_TAG "mcu_writer"
//#define LOG_NDEBUG 0
#include <utils/Log.h>

#include "McuWriter.h"


McuWriter::McuWriter(CMCUUart* mcuuart, sp<McuReader>& reader)
	:McuCommands(mcuuart, reader)
{
	
}
McuWriter::~McuWriter()
{
	ALOGI("mcu writer  destory...");
}

void McuWriter::start_write_mcu_data_loop()
{
	//start a thread to read wirter buff and send data to mcu in a queue
	this->run("mcu_writer");
	sendMainCtrlInitMSGToMcu();
	sendRevReqToMcu();
}

bool McuWriter::threadLoop()
{
	//finish it in the future
	return false;
}


	




