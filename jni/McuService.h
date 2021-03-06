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

#ifndef ANDROID_MCUSERVICE_H
#define ANDROID_MCUSERVICE_H

#include <utils/threads.h>
#include <utils/Errors.h>
#include <utils/KeyedVector.h>
#include <utils/String8.h>
#include <utils/List.h>

#include "IMcuService.h"
//#include "McuWriter.h"
//#include "McuReader.h"

#include "DeathNotifier.h"
#include "IncludeAll.h"

//typedef List<sp<IDataChangedListener> > LISTENERLIST;

class McuReader;
class McuWriter;

namespace android {

class McuService : public BnMcuService
{
public:
    static void instantiate(McuService* ms);
	McuService();
    virtual ~McuService();
    // IMcuService interface
    virtual int getTest();
	virtual bool obtainInfo(int domain, int cmd, Parcel& out);
	virtual bool sendInfo(int domain, int cmd, Parcel& in);
	
	virtual bool registDataChanagedListener(int domain, const sp<IDataChangedListener>& dataChangedListener);
	virtual bool unregistDataChanagedListener(int domain, const sp<IDataChangedListener>& dataChangedListener);
	virtual bool unregistBinder(int domain, const sp<IBinder>& binder);
	virtual bool notifyDataChanagedListener(int domain, Parcel& data);
	virtual bool notifyHardKey(int key);
	virtual bool notifyCanInfo(const u_c* buff, int len);
	
	virtual void setMcuWriter(sp<McuWriter>& writer);
	virtual void setMcuReader(sp<McuReader>& reader);
	
	virtual void onClientBinderDied(int domain, const wp<IBinder>& who);
	virtual void registClientBinderDied(int domain, const sp<IDataChangedListener>& dataChangedListener);

private:
	int mTest;
	sp<McuWriter> m_pMcuWriter;
	sp<McuReader> m_pMcuReader;
	
	List<sp<IDataChangedListener> > mRadioLists;
	List<sp<IDataChangedListener> > mBTLists;
	List<sp<IDataChangedListener> > mSettingsLists;
	List<sp<IDataChangedListener> > mSystemLists;
	List<sp<IDataChangedListener> > mMcuKeyLists;
	List<sp<IDataChangedListener> > mCanInfoLists;
	
	List<sp<DeathNotifier> > mDeathNotifiers;
	
};

// ----------------------------------------------------------------------------

}; // namespace android

#endif // ANDROID_MCUSERVICE_H

