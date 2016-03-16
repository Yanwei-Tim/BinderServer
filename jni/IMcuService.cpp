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

#define LOG_TAG "McuService"
//#define LOG_NDEBUG 0
#include <utils/Log.h>


#include <stdint.h>
#include <sys/types.h>
#include <binder/Parcel.h>
#include <binder/IMemory.h>
#include <utils/Errors.h>  // for status_t
#include <utils/String8.h>

#include "IMcuService.h"


namespace android {

enum {
    CREATE = IBinder::FIRST_CALL_TRANSACTION,
    GET_TEST,
    obtain_info,
    send_info,
    regist_data_changed_listener, 
    unregist_data_changed_listener,
};

class BpMcuService: public BpInterface<IMcuService>
{
public:
    BpMcuService(const sp<IBinder>& impl)
        : BpInterface<IMcuService>(impl)
    {
    }
    int getTest()
    {
		//done in java client
        Parcel data, reply;
        data.writeInterfaceToken(IMcuService::getInterfaceDescriptor());
        remote()->transact(GET_TEST, data, &reply);
        return reply.readInt32();
    }

	bool obtainInfo(int domain, int cmd, Parcel& info)
	{
		//done in java client
		Parcel data, reply;
        data.writeInterfaceToken(IMcuService::getInterfaceDescriptor());
		data.writeInt32(domain);
		data.writeInt32(cmd);
        remote()->transact(obtain_info, data, &reply);
		info.appendFrom(&reply, 0, reply.dataSize()-4);
		info.setDataPosition(0);
        return (reply.readInt32()==1);
	}
	bool sendInfo(int domain, int cmd, Parcel& info)
	{
		//done in java client
		Parcel data, reply;
        data.writeInterfaceToken(IMcuService::getInterfaceDescriptor());
		data.writeInt32(domain);
		data.writeInt32(cmd);
		data.appendFrom(&info, 0, info.dataSize());
        remote()->transact(send_info, data, &reply);
        return (reply.readInt32() == 1);
	}
	bool registDataChanagedListener(int domain, const sp<IDataChangedListener>& dataChangedListener)
	{
		//done in java client
		Parcel data, reply;
        data.writeInterfaceToken(IMcuService::getInterfaceDescriptor());
		data.writeInt32(domain);
        data.writeStrongBinder(dataChangedListener->asBinder());
        remote()->transact(regist_data_changed_listener, data, &reply);
    	return (reply.readInt32() == 1?true:false);
	} 
	bool unregistDataChanagedListener(int domain, const sp<IDataChangedListener>& dataChangedListener)
	{
		//done in java client
		Parcel data, reply;
        data.writeInterfaceToken(IMcuService::getInterfaceDescriptor());
		data.writeInt32(domain);
        data.writeStrongBinder(dataChangedListener->asBinder());
        remote()->transact(unregist_data_changed_listener, data, &reply);
    	return (reply.readInt32() == 1?true:false);
	} 
};

IMPLEMENT_META_INTERFACE(McuService, "android.zhonghong.IMcuService");

// ----------------------------------------------------------------------

status_t BnMcuService::onTransact(
    uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
	ALOGI("BnMcuService::onTransact, code[%d]", code);
    switch (code) {
        case GET_TEST: {
            CHECK_INTERFACE(IMcuService, data, reply);
            int result = getTest();
            reply->writeInt32(result);
            return NO_ERROR;
        } break;
		case obtain_info: {
            CHECK_INTERFACE(IMcuService, data, reply);
			int domain = data.readInt32();
			int cmd = data.readInt32();
			Parcel out;
            bool res = obtainInfo(domain, cmd, out);
			reply->appendFrom(&out, 0, out.dataSize());
			reply->writeInt32(res?1:0);
			out.freeData();
            return NO_ERROR;
        } break;
		case send_info: {
            CHECK_INTERFACE(IMcuService, data, reply);
			int domain = data.readInt32();
			int cmd = data.readInt32();
			Parcel in;
			if(data.dataAvail() >0)
			{
				in.appendFrom(&data, data.dataPosition(), data.dataSize()-data.dataPosition());
				in.setDataPosition(0);
			}
			bool res = sendInfo(domain, cmd, in);
			reply->writeInt32(res?1:0);
			in.freeData();
            return NO_ERROR;
        } break;
		case regist_data_changed_listener: {
            CHECK_INTERFACE(IMcuService, data, reply);
			int domain = data.readInt32();
           	sp<IDataChangedListener> client = interface_cast<IDataChangedListener>(data.readStrongBinder());
            bool res = registDataChanagedListener(domain, client);
            reply->writeInt32((res?1:0));
            return NO_ERROR;
        } break; 
		case unregist_data_changed_listener: {
            CHECK_INTERFACE(IMcuService, data, reply);
			int domain = data.readInt32();
           	sp<IDataChangedListener> client = interface_cast<IDataChangedListener>(data.readStrongBinder());
            bool res = unregistDataChanagedListener(domain, client);
            reply->writeInt32((res?1:0));
            return NO_ERROR;
        } break;
        default:
            return BBinder::onTransact(code, data, reply, flags);
    }
}

// ----------------------------------------------------------------------------

}; // namespace android

