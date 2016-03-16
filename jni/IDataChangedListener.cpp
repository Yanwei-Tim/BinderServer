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


#include <utils/Errors.h>  // for status_t
#include <utils/String8.h>

#include "IDataChangedListener.h"

namespace android {

enum {
    CREATE = IBinder::FIRST_CALL_TRANSACTION,
    NOTIFY,
};

class BpDataChangedListener: public BpInterface<IDataChangedListener>
{
public:
    BpDataChangedListener(const sp<IBinder>& impl)
        : BpInterface<IDataChangedListener>(impl)
    {
    }
    virtual void notify(int msg, int ext1, int ext2, const Parcel *obj)
    {
    	Parcel data, reply;
        data.writeInterfaceToken(IDataChangedListener::getInterfaceDescriptor());
        data.writeInt32(msg);
        data.writeInt32(ext1);
        data.writeInt32(ext2);
        if (obj && obj->dataSize() > 0) {
            data.appendFrom(const_cast<Parcel *>(obj), 0, obj->dataSize());
        }
        remote()->transact(NOTIFY, data, &reply, IBinder::FLAG_ONEWAY);
    }
};

IMPLEMENT_META_INTERFACE(DataChangedListener, "android.zhonghong.IDataChangedListener");

// ----------------------------------------------------------------------

status_t BnDataChangedListener::onTransact(
    uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
    switch (code) {
        case NOTIFY: {
            CHECK_INTERFACE(IDataChangedListener, data, reply);
            int msg = data.readInt32();
            int ext1 = data.readInt32();
            int ext2 = data.readInt32();
            Parcel obj;
            if (data.dataAvail() > 0) {
                obj.appendFrom(const_cast<Parcel *>(&data), data.dataPosition(), data.dataAvail());
				obj.setDataPosition(0);
			}
            notify(msg, ext1, ext2, &obj);
			obj.freeData();
            return NO_ERROR;
        } break;
        default:
            return BBinder::onTransact(code, data, reply, flags);
    }
}

// ----------------------------------------------------------------------------

}; // namespace android


