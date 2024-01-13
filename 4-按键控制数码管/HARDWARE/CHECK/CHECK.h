#ifndef __CHECK_H
#define __CHECK_H
#include "sys.h"

#define KEY1 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1)
#define KEY2 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_2)
#define KEY3 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_3)
#define KEY4 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4)
#define KEY5 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)
#define KEY6 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)
#define KEY7 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7)
#define KEY0 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)

#define KEY_Data_Write(num) PAout(0)=(num&0x01);PAout(1)=(num>>1)&0x01;PAout(2)=(num>>2)&0x01;PAout(3)=(num>>3)&0x01;PAout(4)=(num>>4)&0x01;PAout(5)=(num>>5)&0x01;PAout(6)=(num>>6)&0x01;PAout(7)=(num>>7)&0x01;
#define KEY_Data_Read       KEY0|(KEY1<<1)|(KEY2<<2)|(KEY3<<3)|(KEY4<<4)|(KEY5<<5)|(KEY6<<6)|(KEY7<<7)

void CHECK_Init(void);
u8 CHECK_Scan(void);

#endif
