#ifndef NOTIFY_DISPATCHER_H
#define NOTIFY_DISPATCHER_H

#include <utils/threads.h>

#include "McuService.h"

class McuReader;

using namespace android;

class NotifyDispatcher : public Thread
{
public:
	NotifyDispatcher(McuService* service, sp<McuReader> reader);
    virtual ~NotifyDispatcher();
	void start_dispatch_mcu_data_loop();
private:
	McuService* m_pMcuService;
	sp<McuReader> m_pMcuReader;
	virtual bool threadLoop();
};

#endif
