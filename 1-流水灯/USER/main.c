 #include "stm32f4xx.h"
 #include "misc.h"
 #include "LED.h"
 #include "delay.h"
 int main(void)
 {
	 SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);//用于配置延时函数
	 LED_Init();
	while(1)
	{
		LED_pmd();
	}
 }
 