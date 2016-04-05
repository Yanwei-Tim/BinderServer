
#ifndef DEATHNOTIFIER_H
#define DEATHNOTIFIER_H

//#include "McuService.h"

#include "IMcuService.h"


namespace android {

class McuService;

class DeathNotifier : public IBinder::DeathRecipient {
    public:
        DeathNotifier(int domain, McuService* mcuserver) : mMcuService(mcuserver),mDomain(domain),mIsDied(false) { }
		virtual ~DeathNotifier();
		bool isDied();
	protected:
        virtual void binderDied(const wp<IBinder>& who);
    private:
        const wp<McuService> mMcuService;
		const int mDomain;
		bool mIsDied;
};


};

#endif

