


#define LOG_TAG "mcu_dispatch"
//#define LOG_NDEBUG 0
#include <utils/Log.h>

#include "NotifyDispatcher.h"
 
NotifyDispatcher::NotifyDispatcher(McuService* service, sp<McuReader> reader)
{
	m_pMcuService = service;
	m_pMcuReader = reader;
}
NotifyDispatcher:: ~NotifyDispatcher()
{
	if(m_pMcuService != NULL)
	{
		m_pMcuService->~McuService();
	}
	if(m_pMcuReader != NULL)
	{
		m_pMcuReader->~McuReader();
	}
	ALOGI("NotifyDispatcher:: ~NotifyDispatcher()");
}

void NotifyDispatcher::start_dispatch_mcu_data_loop()
{
	this->run("mcu_dispatch");
}

bool NotifyDispatcher::threadLoop()
{
	if(m_pMcuReader != NULL && m_pMcuService != NULL)
	{
		if(m_pMcuReader->checkRadioInfoChanged())
		{
			Parcel data;
			m_pMcuReader->get_radio_info(data);
			m_pMcuService->notifyDataChanagedListener(DOMAIN_RADIO, data);
		}

		if(m_pMcuReader->checkSettingsInfoChanged())
		{
			Parcel data;
			m_pMcuReader->get_settings_info(data);
			m_pMcuService->notifyDataChanagedListener(DOMAIN_SETTINGS, data);
		}
	}
	else
	{
		ALOGE("error: m_pMcuReader is null point or m_pMcuService is null point");
	}
	usleep(1000*50);
	return true;
}



