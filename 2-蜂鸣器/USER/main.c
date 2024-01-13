 #include "stm32f4xx.h"
 #include "misc.h"
 #include "LED.h"
 #include "delay.h"
 #include "beep.h"
 int main(void)
 {
	 SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);//用于配置延时函数
	 BEEP_Init();         	//初始化蜂鸣器端口
	while(1)
	{
		GPIO_ResetBits(GPIOB,GPIO_Pin_8); //BEEP引脚拉低， 等同BEEP=0;
		delay_ms(BEEP_DELAY);                    
		GPIO_SetBits(GPIOB,GPIO_Pin_8);   //BEEP引脚拉高， 等同BEEP=1;
		delay_ms(BEEP_DELAY); 
	}
 }
 