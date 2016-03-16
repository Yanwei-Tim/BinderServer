

#define LOG_TAG "bt_reader"
//#define LOG_NDEBUG 0
#include <utils/Log.h>

#include "IncludeAll.h"

#include "BTReader.h"


#define PARSE_DEBUG 1
#define BT_READ_MAX 64

BTReader::BTReader(CMCUUart* bt_uart)
	:UartProxy(bt_uart)
{
}

BTReader::~BTReader()
{
	
}

void BTReader::start_read_bt_data_loop()
{
	this->run("bt_reader");
}
bool BTReader::threadLoop()
{
	static u_c read_buff[BT_READ_MAX];
	static u_t read_len;
	
	if(getUart() != NULL && getUart()->isUartOpened())
	{
		getUart()->readUart(read_buff,read_len);
		if(read_len > 0)
		{
			if(PARSE_DEBUG)
			{
				ALOGI("read bt data len[%d] %d %d %d %d %d %d ", read_len, read_buff[0], read_buff[1], read_buff[2], read_buff[3], read_buff[4], read_buff[5]);
			}
			
			start_parse_data(read_buff, read_len);
			
		}
	}
	return true;
}

void BTReader::start_parse_data(const u_c ptr[], int len)
{
	static u_c cache_buff[512];
	static int consumed_size = 0;
	static int size = 0;
	
	if(len <= 512-consumed_size)
	{
		memcpy(&cache_buff[size], ptr, len);
		size += len;
		
		parse_state state;
		state.ptr = cache_buff;
		state.ptr_length = size;
		state.consumed_index = consumed_size;

		// end of \r\n
		if((size-consumed_size) < 3)
		{
			if(PARSE_DEBUG)
			ALOGI("cache buff is less than 3(unconsumed size[%d])", size-consumed_size);
			return;
		}

		while(1)
		{
			state.consumed_index = consumed_size;
			
			int consumed = parse_data_inner(state);
			consumed_size += consumed;

			if(PARSE_DEBUG)
			{
				ALOGI("consumed[%d]", consumed);
				ALOGI("consumed_size[%d]", consumed_size);
				ALOGI("size[%d]", size);
			}
			
			if(consumed == 0)
			{
				break;
			}
		}
		
		if((size-consumed_size) <= 0 && consumed_size >= 256)
		{
			ALOGI("already consume cache buff over, so clean cache buff(size[%d])", size);
			memset(cache_buff, 0, sizeof(cache_buff));
			consumed_size = 0;
			size = 0;
		}
	}
	else
	{
		ALOGE("consumed_size[%d]", consumed_size);
		ALOGE("error:receive buf is bigger than cache buff, you must create bigger catche buff");
	}
}

//return consumed size
int BTReader::parse_data_inner(parse_state& state)
{
	int consumed_index = 0;

	u_c* ptr = &state.ptr[state.consumed_index];

	//seek the tail of frame,recursive
	//find \r\n
	for(int i=0; i< (state.ptr_length-consumed_index-state.consumed_index)-1; i++)
	{
		if(ptr[i] = '\r' && ptr[i+1] == '\n')
		{
			int cmd_len = i+1+1;
			parse_single_cmd(ptr, cmd_len);
			consumed_index += cmd_len; 
			return consumed_index;
		}
	}

	ALOGE("error: can not find the taio of frame(\r, \n), almost do not happen");
	return consumed_index;
}



//0xFF,0xAA,len,data0,data1,...,0x0A
void BTReader::parse_single_cmd(const u_c* pBuff, int num)
{
	ALOGE("receive bt uart data[%s] len[%d]", pBuff, num);
}


