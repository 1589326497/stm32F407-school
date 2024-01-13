/*
外部中断控制数码管和LED的反转 项目完成时间2023/12/6

KEY0 			数码管清空，LED1反转
KEY1 			数码管清空，LED2反转
KEY2 			数码管显示“OFF”，并且关闭KEY0-2的中断源
KEY-UP 			数码管显示“ON”，同时开启KEY0-2的中断源
 */


#include "exti.h"
#include "key.h"
#include "sys.h"
#include "delay.h"
#include "led.h"

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2 两位抢占两位响应
	
	delay_init(168);
	LED_Init();
	EXTIX_Init();
	while(1);
}
