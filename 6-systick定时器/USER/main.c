/*
利用systick定时器实现延时实现 1秒数码管一三位和二四位交替亮

*/


#include "stm32f4xx.h"
#include "led.h"
#include "delay.h"
#include "SEG_8.h"
#include "led.h"
#include "timer.h"
extern mark;
int main(void)
{ 	 
	delay_init(168);
	SEG_Init();
	TIM3_init(1000-1,72-1);//定时1秒  在中断中修改mark
	while(1)
	{
		if(mark)
		{
			SEG_display(0,1);
			SEG_display(0,3);
		}
		else
		{
			SEG_display(0,2);
			SEG_display(0,4);
		}
		
		
	}
}
