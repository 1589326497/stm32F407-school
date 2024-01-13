 #include "stm32f4xx.h"
 #include "misc.h"
 #include "LED.h"
 #include "delay.h"
 #include "SEG_8.h"
 int main(void)
 {
	 SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);//用于配置延时函数
	
	while(1)
	{
		for(int i=0;i<9;i++)
		{
			SEG_display(1,i);
			SEG_display(2,i);
			SEG_display(3,i);
			SEG_display(4,i);
			delay_ms(500);
			GPIO_SetBits(GPIOE,GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);
			GPIO_SetBits(GPIOE,GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
			
		}
	}
	
 }
 