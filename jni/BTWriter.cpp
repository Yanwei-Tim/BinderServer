#define LOG_TAG "bt_writer"
//#define LOG_NDEBUG 0
#include <utils/Log.h>

#include "BTWriter.h"

BTWriter::BTWriter(CMCUUart* uart, sp<BTReader>& reader):BTCommands(uart, reader)
{

}
BTWriter::~BTWriter()
{
	
}

void BTWriter::start_write_bt_data_loop()
{
	//start a thread to read wirter buff and send data to mcu in a queue
	this->run("bt_writer");
	sendStartCommandToBT();
}

bool BTWriter::threadLoop()
{
	//finish it in the future
	return false;
}



	



