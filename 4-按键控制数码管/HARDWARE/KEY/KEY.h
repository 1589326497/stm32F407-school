#ifndef __KEY_H
#define __KEY_H
#include "sys.h"


#define KEY1 GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_12)
#define KEY_UP GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)

void KEY_Init(void);
u8 KEY_SCAN(void);

#endif
