#ifndef _SEG_8_H_
#define _SEG_8_H_
#include "stm32f4xx.h"                  // Device header

void SEG_Init(void);	//初始化数码管硬件
void SEG_display(int n); //配置数码管位
#endif

