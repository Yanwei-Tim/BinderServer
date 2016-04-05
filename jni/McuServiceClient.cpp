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

//#define LOG_NDEBUG 0
#define LOG_TAG "McuService"
#include <utils/Log.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <dirent.h>
#include <unistd.h>

#include <string.h>

#include <cutils/atomic.h>
#include <cutils/properties.h> // for property_get

#include <utils/misc.h>

#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include <binder/MemoryHeapBase.h>
#include <binder/MemoryBase.h>
#include <gui/Surface.h>
#include <utils/Errors.h>  // for status_t
#include <utils/String8.h>
#include <utils/SystemClock.h>
#include <utils/Vector.h>

//add====================================================
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <cutils/sockets.h>
#include <cutils/properties.h>

#include <android/log.h>

#include "IMcuService.h"


#define LOG_TAG "McuService"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
//======================================================

using namespace android;

int test()
{
	sp<IServiceManager> sm = defaultServiceManager();
	sp<IBinder> binder = sm->getService(String16("zhonghong.mcu"));
	if(binder != 0)
	{
		sp<IMcuService> mcuService = interface_cast<IMcuService>(binder);
		LOGI("mcuService getTest = %d", mcuService->getTest());
		
		
		LOGI("---------------------------------");
		
		Parcel radioInfo;
		mcuService->obtainInfo(1, 2, radioInfo);
		radioInfo.setDataPosition(0);
		LOGI("radioinfo  domain[%d], cmd[%d], freq[%d], loc[%d]", radioInfo.readInt32(), radioInfo.readInt32(), radioInfo.readInt32(),radioInfo.readInt32());

		Parcel btInfo;
		mcuService->obtainInfo(2, 3, btInfo);
		btInfo.setDataPosition(0);
		LOGI("btInfo  domain[%d], cmd[%d], freq[%d], loc[%d]", btInfo.readInt32(), btInfo.readInt32(), btInfo.readInt32(),btInfo.readInt32());


//		sp<IRadioProxy> radioProxy = mcuService->getRadioProxy();
//		LOGI("radioProxy = %p", radioProxy.get());
//		char arr[50];
//		int data0, data1, data2;
//		struct RadioInfo radioInfo;
//		radioProxy->getRadioInfo(radioInfo);
//
//		LOGI("st[%d]", radioInfo.st);
//		LOGI("loc[%d]", radioInfo.loc);
//		LOGI("freq[%d]", radioInfo.freq);
//		LOGI("subfreqsize[%d]", radioInfo.subfreqsize);

		
		//bool res = radioProxy->getDataByCommand(2, data0, data1, data2, arr);
		//LOGI("getDataByCommand:data0[%d], data1[%d], data2[%d], arr[%s]", data0, data1, data2, arr);
		//LOGI("getDataByCommand = %d", res);
		
		
//		sp<IRadioInfoChangedListener> listener = new RadioInfoChangedListener();
		
		
		//sleep(1);
		
		
		//sleep(10);
		LOGI("McuServiceClient end ");
	}
	
	return 1;
}

