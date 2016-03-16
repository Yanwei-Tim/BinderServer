
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include <utils/Mutex.h>


#include "IMcuService.h"



// client singleton for binder interface to services
static Mutex sServiceLock;

sp<IMCUService> getMcuService()
{
	Mutex::Autolock lock(sServiceLock);
	if (gMcuService == 0) {
        sp<IServiceManager> sm = defaultServiceManager();
        sp<IBinder> binder;
        do {
            binder = sm->getService(String16(MCU_SERVIVE));
            if (binder != 0) {
                break;
            }
            ALOGW("zhonghong mcu service not published, waiting...");
            usleep(500000); // 0.5 s
        } while (true);

        if (sDeathNotifier == NULL) {
            sDeathNotifier = new DeathNotifier();
        }
        //binder->linkToDeath(sDeathNotifier);
        gMcuService = interface_cast<IMcuService>(binder);
    }
    ALOGE_IF(gMcuService == 0, "no zhonghong mcu service!?");
    return gMcuService;
}




