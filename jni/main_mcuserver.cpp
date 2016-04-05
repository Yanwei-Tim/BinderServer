/*
**
** Copyright 2008, The Android Open Source Project
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#define LOG_TAG "mcuserver"
#define LOG_NDEBUG 0

#include <fcntl.h>
#include <sys/prctl.h>
#include <sys/wait.h>
#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <cutils/properties.h>
#include <utils/Log.h>
#include "RegisterExtensions.h"


#include "McuService.h"
#include "mcu_uart/CMCUUart.h"
#include "McuReader.h"
#include "McuWriter.h"
#include "NotifyDispatcher.h"
#include "BTReader.h"
#include "BTWriter.h"


using namespace android;

int main(int argc, char** argv)
{
	
    sp<ProcessState> proc(ProcessState::self());
    sp<IServiceManager> sm = defaultServiceManager();
    ALOGI("ServiceManager: %p", sm.get());
    McuService* ms = new McuService();
    ms->instantiate(ms);
	
    registerExtensions();

	//mcu 
	//here can not use '{}', 
	//otherwise mcuserver will call ~McuService method as well as McuReader and McuWriter
	CMCUUart* mcu_uart = new CMCUUart();
	sp<McuReader> mcu_reader = new McuReader(mcu_uart, ms);
	sp<McuWriter> mcu_writer = new McuWriter(mcu_uart, mcu_reader);
	
	ms->setMcuWriter(mcu_writer);
	ms->setMcuReader(mcu_reader);

	sp<NotifyDispatcher> dispatcher = new NotifyDispatcher(ms, mcu_reader);
	
	char mcu_path[PROP_VALUE_MAX+5] = {0};
	memcpy(mcu_path, "/dev/", 5);
	property_get("ro.kernel.android.mcu", &mcu_path[5], "ttyS1");
	ALOGI("mcu_path: %s", mcu_path);
	
	if(mcu_uart->openUartDev(mcu_path,B115200))
	{
		mcu_writer->start_write_mcu_data_loop();
		mcu_reader->start_read_mcu_data_loop();
		dispatcher->start_dispatch_mcu_data_loop();
	}

	/*
	//bt
	CMCUUart* bt_uart = new CMCUUart();
	bt_uart->enabledDebug(true);
	sp<BTReader> bt_reader = new BTReader(bt_uart);
	sp<BTWriter> bt_writer = new BTWriter(bt_uart, bt_reader);

	char bt_path[PROP_VALUE_MAX+5] = {0};
	memcpy(bt_path, "/dev/", 5);
	property_get("ro.kernel.android.bt", &bt_path[5], "ttyS3");
	ALOGI("bt_path: %s", bt_path);
	
	if(bt_uart->openUartDev(bt_path,B9600))
	{
		bt_reader->start_read_bt_data_loop();
		bt_writer->start_write_bt_data_loop();
	}
	*/
	
    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();
}

