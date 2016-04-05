#define LOG_TAG "McuService"
//#define LOG_NDEBUG 0
#include <utils/Log.h>
#include "McuService.h"

#include "DeathNotifier.h"

namespace android {

void DeathNotifier::binderDied(const wp<IBinder>& who)
{
	mIsDied = true;
	
	sp<McuService> mcuserver = mMcuService.promote();
	if(mcuserver != 0)
	{
		mcuserver->onClientBinderDied(mDomain, who);
	}
}

bool DeathNotifier::isDied()
{
	return mIsDied;
}

DeathNotifier::~DeathNotifier()
{
	ALOGI("DeathNotifier::~DeathNotifier");
}

}


