/*************************
现象：按下独立按键后（KEY_UP,KEY1,KEY2,KEY3）
对应的LED翻转,如果开发板上没有反应
请检查是否LED灯开关打开
 ***********************/


#include "exti.h"
#include "key.h"
#include "sys.h"
#include "delay.h"
#include "led.h"

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);
	LED_Init();
	EXTIX_Init();
	while(1);
}
