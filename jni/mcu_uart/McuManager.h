#ifndef MCU_MANAGER_H_
#define MCU_MANAGER_H_


#include "../McuService.h"

//app call this method start read data from mcu
//app do not use cmcuuart class dirctory
void start_loop_mcu_data(McuService* service);


#endif
