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
 

#include "McuService.h"
#include "McuWriter.h"
#include "McuReader.h"
 
//====================================================== 



namespace android {

static bool checkPermission(const char* permissionString) {
#ifndef HAVE_ANDROID_OS
    return true;
#endif
    if (getpid() == IPCThreadState::self()->getCallingPid()) return true;
    bool ok = checkCallingPermission(String16(permissionString));
    if (!ok) ALOGE("Request requires %s", permissionString);
    return ok;
}

void McuService::instantiate(McuService* ms) {
    defaultServiceManager()->addService(
            String16("zhonghong.mcu"), ms);
}

McuService::McuService()
{
    ALOGI("McuService created");
    mTest = 100;
}

McuService::~McuService()
{
	ALOGI("mcu service is destoryed");
	if(m_pMcuWriter != NULL)
	{
		m_pMcuWriter->~McuWriter();
	}
	if(m_pMcuReader != NULL)
	{
		m_pMcuReader->~McuReader();
	}
}

void McuService::setMcuWriter(sp<McuWriter>& writer)
{
	m_pMcuWriter = writer;
}
void McuService::setMcuReader(sp<McuReader>& reader)
{
	m_pMcuReader = reader;
}

int McuService::getTest()
{
    pid_t pid = IPCThreadState::self()->getCallingPid();
    ALOGD_IF(true,"getTest pid=%d", pid);
    return mTest;
}
bool McuService::obtainInfo(int domain, int cmd, Parcel& out)
{
	ALOGI("obtainInfo domain[%d], cmd[%d]", domain, cmd);
	switch(domain)
	{
		case DOMAIN_RADIO: {
			if(cmd == DOMAIN_RADIO)
			{
				return m_pMcuReader->get_radio_info(out);
			}
			else if(cmd == CMD_RADIO_LOC)
			{
				out.writeInt32(m_pMcuReader->get_radio_loc());
				return true;
			}
			else if(cmd == CMD_RADIO_ST)
			{
				out.writeInt32(m_pMcuReader->get_radio_st());
				return true;
			}
			else if(cmd == CMD_RADIO_FREQ)
			{
				out.writeInt32(m_pMcuReader->get_radio_freq());
				return true;
			}
			else if(cmd == CMD_RADIO_SEARCH)
			{
				out.writeInt32(m_pMcuReader->get_radio_search());
				return true;
			}
			else if(cmd == CMD_RADIO_STIND)
			{
				out.writeInt32(m_pMcuReader->get_radio_stind());
				return true;
			}
			else if(cmd == CMD_RADIO_SCAN)
			{
				out.writeInt32(m_pMcuReader->get_radio_scan());
				return true;
			}
			else if(cmd == CMD_RADIO_AREA)
			{
				out.writeInt32(m_pMcuReader->get_radio_area());
				return true;
			}
			else
			{
				ALOGE("error:obtainInfo domain[%d], cmd[%d] was untreated", domain, cmd);
			}
		} break;
		case DOMAIN_BT: {
			if(cmd == DOMAIN_BT)
			{
				//return convertBTIntoParcel(gBTInfo, out);
			}
			else if(cmd == CMD_BT_STATUS)
			{
				//out.writeInt32(gBTInfo.bt_status);
				return true;
			}
			else if(cmd == CMD_BT_NAME)
			{
				//out.writeInt32(gBTInfo.name?1:0);
				return true;
			}
			else if(cmd == CMD_BT_NUMBER)
			{
				//out.writeInt32(gBTInfo.number);
				return true;
			}
			else
			{
				ALOGE("error:obtainInfo domain[%d], cmd[%d] was untreated", domain, cmd);
			}
		} break;
		case DOMAIN_SETTINGS: {
			if(cmd == DOMAIN_SETTINGS)
			{
				return m_pMcuReader->get_settings_info(out);
			}
			else if(cmd == CMD_SETTINGS_BRIGHTNESS)
			{
				//out.writeInt32(gSettingsInfo.brightness);
				return true;
			}
			else if(cmd == CMD_SETTINGS_KEY_SOUND)
			{
				//out.writeInt32(gSettingsInfo.key_sound?1:0);
				return true;
			}
			else if(cmd == CMD_SETTINGS_NAVI_MAX)
			{
				//out.writeInt32(gSettingsInfo.navi_max);
				return true;
			}
			else
			{
				ALOGE("error:obtainInfo domain[%d], cmd[%d] was untreated", domain, cmd);
			}
		} break;
		case CMD_SYSTEM_SOURCE: {
			if(cmd == CMD_SYSTEM_SOURCE)
			{
				out.writeInt32(m_pMcuReader->get_system_source());
				return true;
			}
			else if(cmd == CMD_SYSTEM_STATE)
			{
				out.writeInt32(m_pMcuReader->get_system_state());
				return true;
			}
		} break;
		default: {
			ALOGE("error:obtainInfo domain[%d], cmd[%d] was untreated", domain, cmd);
		} break;
	}
	return false;
}
bool McuService::sendInfo(int domain, int cmd, Parcel& in)
{
	ALOGI("sendInfo domain[%d], cmd[%d]", domain, cmd);
	switch(domain)
	{
		case DOMAIN_RADIO: {

			if(cmd == CMD_RADIO_LOC)
			{
				m_pMcuWriter->sendRadioLocToMcu();
				return true;
			}
			else if(cmd == CMD_RADIO_ST)
			{
				m_pMcuWriter->sendRadioSTToMcu();
				return true;
			}
			else if(cmd == CMD_RADIO_FREQ)
			{
				if(&in && in.dataSize() >0)
				{
					int freq = (in.readInt32());
					m_pMcuWriter->sendSourceToMcu(0);
					m_pMcuReader->set_radio_freq(freq&0x3FFF);
					m_pMcuWriter->sendFreqToMcu(freq);
					return true;
				}
			}
			else if(cmd == CMD_RADIO_SEARCH)
			{
				m_pMcuWriter->sendRadioSearchToMcu();
				return true;
			}
			else if(cmd == CMD_RADIO_SCAN)
			{
				m_pMcuWriter->sendRadioScanToMcu();
				return true;
			}
			else if(cmd == CMD_RADIO_SEARCH_PREV)
			{
				m_pMcuWriter->sendSearchPrevToMcu();
				return true;
			}
			else if(cmd == CMD_RADIO_SEARCH_NEXT)
			{
				m_pMcuWriter->sendSearchNextToMcu();
				return true;
			}
			else if(cmd == CMD_RADIO_AREA)
			{
				if(&in && in.dataSize() >0)
				{
					int area= (in.readInt32());
					m_pMcuWriter->sendRadioAreaToMcu(area);
					return true;
				}
			}
			else
			{
				ALOGE("error:sendInfo domain[%d], cmd[%d] was untreated", domain, cmd);
			}
		} break;
		case DOMAIN_BT: {
			if(cmd == DOMAIN_BT)
			{
				//return convertBTIntoParcel(gBTInfo, out);
			}
			else if(cmd == CMD_BT_STATUS)
			{
				if(&in && in.dataSize() >0)
				{
					//gBTInfo.bt_status = (in.readInt32());
					return true;
				}
			}
			else if(cmd == CMD_BT_NAME)
			{
				if(&in && in.dataSize() > 0)
				{
					//gBTInfo.name = (in.readInt32() == 1);
					return true;
				}
			}
			else if(cmd == CMD_BT_NUMBER)
			{
				if(&in && in.dataSize() >0)
				{
					//gBTInfo.number = (in.readInt32() == 1);
					return true;
				}
			}
			else
			{
				ALOGE("error:sendInfo domain[%d], cmd[%d] was untreated", domain, cmd);
			}
		} break;
		case DOMAIN_SETTINGS: {
			if(cmd == CMD_SETTINGS_BRIGHTNESS)
			{
				if(&in && in.dataSize() >0)
				{
					int bright = (in.readInt32());
					//implements in android
					return true;
				}
			}
			else if(cmd == CMD_SETTINGS_KEY_SOUND)
			{
				if(&in && in.dataSize() >0)
				{
					int val = in.readInt32();
					m_pMcuReader->set_settings_key_sound(val);
					m_pMcuWriter->sendBeepToMcu(val);
					return true;
				}
			}
			else if(cmd == CMD_SETTINGS_NAVI_MAX)
			{
				if(&in && in.dataSize() >0)
				{
					return true;
				}
			}
			else if(cmd == CMD_SETTINGS_VOL)
			{
				if(&in && in.dataSize() >0)
				{
					int val = in.readInt32();
					m_pMcuReader->set_settings_volume(val);
					m_pMcuWriter->sendVolToMcu(val);
					return true;
				}
			}
			else if(cmd == CMD_SETTINGS_TRED)
			{
				if(&in && in.dataSize() >0)
				{
					int val = in.readInt32();
					m_pMcuReader->set_settings_treb(val);
					m_pMcuWriter->sendTrebToMcu(val);
					return true;
				}
			}
			else if(cmd == CMD_SETTINGS_MID)
			{
				if(&in && in.dataSize() >0)
				{
					int val = in.readInt32();
					m_pMcuReader->set_settings_mid(val);
					m_pMcuWriter->sendMidToMcu(val);
					return true;
				}
			}
			else if(cmd == CMD_SETTINGS_BASS)
			{
				if(&in && in.dataSize() >0)
				{
					int val = in.readInt32();
					m_pMcuReader->set_settings_bass(val);
					m_pMcuWriter->sendBassToMcu(val);
					return true;
				}
			}
			else if(cmd == CMD_SETTINGS_FADE)
			{
				if(&in && in.dataSize() >0)
				{
					int val = in.readInt32();
					m_pMcuReader->set_settings_fade(val);
					m_pMcuWriter->sendFadeToMcu(val);
					return true;
				}
			}
			else if(cmd == CMD_SETTINGS_BAL)
			{
				if(&in && in.dataSize() >0)
				{
					int val = in.readInt32();
					m_pMcuReader->set_settings_bal(val);
					m_pMcuWriter->sendBalToMcu(val);
					return true;
				}
			}
			else if(cmd == CMD_SETTINGS_MUTE)
			{
				if(&in && in.dataSize() >0)
				{
					int val = in.readInt32();
					m_pMcuReader->set_settings_mute(val);
					m_pMcuWriter->sendMuteToMcu(val);
					return true;
				}
			}
			else if(cmd == CMD_SETTINGS_BTVOL)
			{
				if(&in && in.dataSize() >0)
				{
					int val = in.readInt32();
					m_pMcuReader->set_settings_btvol(val);
					m_pMcuWriter->sendBtVolToMcu(val);
					return true;
				}
			}
			else if(cmd == CMD_SETTINGS_GPSVOL)
			{
				if(&in && in.dataSize() >0)
				{
					int val = in.readInt32();
					m_pMcuReader->set_settings_gpsvol(val);
					m_pMcuWriter->sendGpsVolToMcu(val);
					return true;
				}
			}
			else if(cmd == CMD_SETTINGS_DEFVOL)
			{
				if(&in && in.dataSize() >0)
				{
					int val = in.readInt32();
					m_pMcuReader->set_settings_defvol(val);
					m_pMcuWriter->sendDefVolToMcu(val);
					return true;
				}
			}
			else if(cmd == CMD_SETTINGS_AUDIO_MODE)
			{
				if(&in && in.dataSize() >0)
				{
					int val = in.readInt32();
					m_pMcuReader->set_settings_audio_mode(val);
					m_pMcuWriter->sendAudioModeToMcu(val);
					return true;
				}
			}
			else
			{
				ALOGE("error:sendInfo domain[%d], cmd[%d] was untreated", domain, cmd);
			}
		} break;
		case CMD_SYSTEM_SOURCE: {
			if(cmd == CMD_SYSTEM_SOURCE)
			{
				if(&in && in.dataSize() >0)
				{
					int source = (in.readInt32());
					//implements in android
					m_pMcuReader->set_system_source(source);
					m_pMcuWriter->sendSourceToMcu(source);
					return true;
				}
			}
			else if(cmd == CMD_SYSTEM_STATE)
			{
				if(&in && in.dataSize() >0)
				{
					int val = in.readInt32();
					m_pMcuReader->set_system_state(val);
					m_pMcuWriter->sendMCUState(val);
					return true;
				}
			}
		} break;
		default: {
			ALOGE("error:sendInfo domain[%d], cmd[%d] was untreated", domain, cmd);
		} break;
	}
	return false;
}
bool McuService::registDataChanagedListener(int domain, const sp<IDataChangedListener>& dataChangedListener)
{
	ALOGI("registDataChanagedListener domain[%d] listener[%p]", domain, dataChangedListener->asBinder().get());

	registClientBinderDied(domain, dataChangedListener);

	if(domain == DOMAIN_RADIO)
	{
		if(&mRadioLists)
		{
			mRadioLists.push_back(dataChangedListener);	
		}
	}
	else if(domain == DOMAIN_BT)
	{
		if(&mBTLists)
		{
			mBTLists.push_back(dataChangedListener);
		}
	}
	else if(domain == DOMAIN_SETTINGS)
	{
		if(&mSettingsLists)
		{
			mSettingsLists.push_back(dataChangedListener);
		}
	}
	else if(domain == DOMAIN_SYSTEM)
	{
		if(&mSystemLists)
		{
			mSystemLists.push_back(dataChangedListener);
		}
	}
	else if(domain == DOMAIN_MCUKEY)
	{
		if(&mMcuKeyLists)
		{
			mMcuKeyLists.push_back(dataChangedListener);
		}
	}
	else if(domain == DOMAIN_CANINFO)
	{
		if(&mCanInfoLists)
		{
			mCanInfoLists.push_back(dataChangedListener);
		}
	}
	
	
	return true;
}

bool McuService::unregistDataChanagedListener(int domain, const sp<IDataChangedListener>& dataChangedListener)
{
	ALOGI("unregistDataChanagedListener domain[%d] listener[%p]", domain, dataChangedListener->asBinder().get());
	return unregistBinder(domain, dataChangedListener->asBinder());
	
}

void McuService::onClientBinderDied(int domain, const wp<IBinder>& who)
{
	ALOGI("a binder client is dead, so clean up it");
	sp<IBinder> deathclient = who.promote();
	if(deathclient != 0)
	{
		unregistBinder(domain, deathclient);

		//delete dead notifier client
		List<sp<DeathNotifier> >::iterator ite;
		for(ite = mDeathNotifiers.begin(); (*ite).get() != NULL && ite != mDeathNotifiers.end(); )
		{
			if((*ite)->isDied())
			{
				ALOGI("clean up the dead notifier[%p]", (*ite).get());
				ite = mDeathNotifiers.erase(ite);
			}
			else
			{
				ite++;
			}
		}
	}
}
void McuService::registClientBinderDied(int domain, const sp<IDataChangedListener>& dataChangedListener)
{
	sp<DeathNotifier> deathNotifier = new DeathNotifier(domain, this);
	ALOGI("regist a client binder[%p]", deathNotifier.get());
	mDeathNotifiers.push_back(deathNotifier);
	dataChangedListener->asBinder()->linkToDeath(deathNotifier, this);
	
}

bool McuService::unregistBinder(int domain, const sp<IBinder>& binder)
{
	ALOGI("unregistBinder domain[%d] listener[%p]", domain, binder.get());
	if(domain == DOMAIN_RADIO)
	{
		if(&mRadioLists && !mRadioLists.empty())
		{
			List<sp<IDataChangedListener> >::iterator ite;
			for(ite = mRadioLists.begin(); ite != mRadioLists.end(); ite++)
			{
				if((*ite)->asBinder() == binder)
				{
					mRadioLists.erase(ite);
					return true;
				}
			}
		}
	}
	else if(domain == DOMAIN_BT)
	{
		if(&mBTLists && !mBTLists.empty())
		{
			List<sp<IDataChangedListener> >::iterator ite;
			for(ite = mBTLists.begin(); ite != mBTLists.end(); ite++)
			{
				if((*ite)->asBinder() == binder)
				{
					mBTLists.erase(ite);
					return true;
				}
			}
		}
	}
	else if(domain == DOMAIN_SETTINGS)
	{
		if(&mSettingsLists && !mSettingsLists.empty())
		{
			List<sp<IDataChangedListener> >::iterator ite;
			for(ite = mSettingsLists.begin(); ite != mSettingsLists.end(); ite++)
			{
				if((*ite)->asBinder() == binder)
				{
					mSettingsLists.erase(ite);
					return true;
				}
			}
		}
		
	}
	else if(domain == DOMAIN_SYSTEM)
	{
		if(&mSystemLists && !mSystemLists.empty())
		{
			List<sp<IDataChangedListener> >::iterator ite;
			for(ite = mSystemLists.begin(); ite != mSystemLists.end(); ite++)
			{
				if((*ite)->asBinder() == binder)
				{
					mSystemLists.erase(ite);
					return true;
				}
			}
		}
	}
	else if(domain == DOMAIN_MCUKEY)
	{
		if(&mMcuKeyLists && !mMcuKeyLists.empty())
		{
			List<sp<IDataChangedListener> >::iterator ite;
			for(ite = mMcuKeyLists.begin(); ite != mMcuKeyLists.end(); ite++)
			{
				if((*ite)->asBinder() == binder)
				{
					mMcuKeyLists.erase(ite);
					return true;
				}
			}
		}
	}
	else if(domain == DOMAIN_CANINFO)
	{
		if(&mCanInfoLists && !mCanInfoLists.empty())
		{
			List<sp<IDataChangedListener> >::iterator ite;
			for(ite = mCanInfoLists.begin(); ite != mCanInfoLists.end(); ite++)
			{
				if((*ite)->asBinder() == binder)
				{
					mCanInfoLists.erase(ite);
					return true;
				}
			}
		}
	}
	return false;
}

bool McuService::notifyHardKey(int key)
{
	Parcel to;
	to.setDataPosition(0);
	to.writeInt32(key);
	to.writeInt32(0);
	notifyDataChanagedListener(DOMAIN_MCUKEY, to);
	return true;
}

bool McuService::notifyCanInfo(const u_c* buff, int len)
{
	Parcel to;
	to.setDataPosition(0);
	to.writeInt32(len);
	to.writeByteArray(len, buff);
	notifyDataChanagedListener(DOMAIN_CANINFO, to);
	return true;
}

bool McuService::notifyDataChanagedListener(int domain, Parcel& data)
{
	if(domain == DOMAIN_RADIO)
	{
		ALOGI("radio info has changed, so dispatcher it");
		if(!mRadioLists.empty())
		{
			List<sp<IDataChangedListener> >::iterator ite;
			for(ite = mRadioLists.begin(); ite != mRadioLists.end(); ite++)
			{
				(*ite)->notify(DOMAIN_RADIO, 3, 4, &data);
			}
		}
		return true;
	}
	else if(domain == DOMAIN_SETTINGS)
	{
		ALOGI("settings info has changed, so dispatcher it");
		if(!mSettingsLists.empty())
		{
			List<sp<IDataChangedListener> >::iterator ite;
			for(ite = mSettingsLists.begin(); ite != mSettingsLists.end(); ite++)
			{
				(*ite)->notify(DOMAIN_SETTINGS, 5, 6, &data);
			}
		}
		return true;
	}
	else if(domain == DOMAIN_BT)
	{
		ALOGI("bt info has changed, so dispatcher it");
		if(!mBTLists.empty())
		{
			List<sp<IDataChangedListener> >::iterator ite;
			for(ite = mBTLists.begin(); ite != mBTLists.end(); ite++)
			{
				(*ite)->notify(DOMAIN_BT, 5, 6, &data);
			}
		}
		return true;
	}
	else if(domain == DOMAIN_SYSTEM)
	{
		ALOGI("system info has changed, so dispatcher it");
		if(!mSystemLists.empty())
		{
			List<sp<IDataChangedListener> >::iterator ite;
			for(ite = mSystemLists.begin(); ite != mSystemLists.end(); ite++)
			{
				(*ite)->notify(DOMAIN_SYSTEM, 5, 6, &data);
			}
		}
		return true;
	}
	else if(domain == DOMAIN_MCUKEY)
	{
		ALOGI("mcu key info has changed, so dispatcher it");
		if(!mMcuKeyLists.empty())
		{
			List<sp<IDataChangedListener> >::iterator ite;
			for(ite = mMcuKeyLists.begin(); ite != mMcuKeyLists.end(); ite++)
			{
				(*ite)->notify(DOMAIN_MCUKEY, 5, 6, &data);
			}
		}
		return true;
	}
	else if(domain == DOMAIN_CANINFO)
	{
		ALOGI("can info has changed, so dispatcher it");
		if(!mCanInfoLists.empty())
		{
			List<sp<IDataChangedListener> >::iterator ite;
			for(ite = mCanInfoLists.begin(); ite != mCanInfoLists.end(); ite++)
			{
				(*ite)->notify(DOMAIN_MCUKEY, 5, 6, &data);
			}
		}
		return true;
	}
	return false;
} 


}// namespace android

