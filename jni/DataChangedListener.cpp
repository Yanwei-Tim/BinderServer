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

#define LOG_TAG "DataL"
#define LOG_NDEBUG 0
#include <utils/Log.h>


#include <stdint.h>
#include <sys/types.h>

#include <binder/Parcel.h>
#include <binder/IMemory.h>
#include <binder/IServiceManager.h>

#include <utils/Errors.h>  // for status_t
#include <utils/String8.h>

#include "DataChangedListener.h"
#include "IMcuService.h"


namespace android {

DataChangedListener::DataChangedListener()
{
    ALOGI("constructor");
}

DataChangedListener::~DataChangedListener()
{
    ALOGI("destructor");
}

void DataChangedListener::notify(int msg, int ext1, int ext2, const Parcel *obj)
{
	ALOGI("message received msg=%d, ext1=%d, ext2=%d", msg, ext1, ext2);
}

// ----------------------------------------------------------------------------

}; // namespace android


