/*
* RadioManager.h
* 
* Created on:2016.1.22
*		Author: leo liu
*/

#ifndef MCU_SERVICE_NATIVE_H
#define MCU_SERVICE_NATIVE_H

#include <utils/RefBase.h>

#include "IMCUService.h"

sp<IMCUService> gMcuService;
sp<IMCUService> getMcuService();

#endif



