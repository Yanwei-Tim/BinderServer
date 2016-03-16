/*
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_IMCUSERVICE_H
#define ANDROID_IMCUSERVICE_H

#include <utils/Errors.h>  // for status_t
#include <utils/KeyedVector.h>
#include <utils/RefBase.h>
#include <utils/String8.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
 
#include "IDataChangedListener.h" 


namespace android {

class IMcuService: public IInterface
{
public:
    DECLARE_META_INTERFACE(McuService);

    virtual int getTest(void) = 0;
	virtual bool obtainInfo(int domain, int cmd, Parcel& info) = 0;
	virtual bool sendInfo(int domain, int cmd, Parcel& info) = 0;
	virtual bool registDataChanagedListener(int domain, const sp<IDataChangedListener>& dataChangedListener) = 0;
	virtual bool unregistDataChanagedListener(int domain, const sp<IDataChangedListener>& dataChangedListener) = 0;
 
};

// ----------------------------------------------------------------------------

class BnMcuService: public BnInterface<IMcuService>
{
public:
    virtual status_t    onTransact( uint32_t code,
                                    const Parcel& data,
                                    Parcel* reply,
                                    uint32_t flags = 0);
};

}; // namespace android

#endif // ANDROID_IMCUSERVICE_H

