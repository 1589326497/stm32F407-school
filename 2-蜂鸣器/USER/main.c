 #include "stm32f4xx.h"
 #include "misc.h"
 #include "LED.h"
 #include "delay.h"
 #include "beep.h"
 int main(void)
 {
	 SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);//����������ʱ����
	 BEEP_Init();         	//��ʼ���������˿�
	while(1)
	{
		GPIO_ResetBits(GPIOB,GPIO_Pin_8); //BEEP�������ͣ� ��ͬBEEP=0;
		delay_ms(BEEP_DELAY);                    
		GPIO_SetBits(GPIOB,GPIO_Pin_8);   //BEEP�������ߣ� ��ͬBEEP=1;
		delay_ms(BEEP_DELAY); 
	}
 }
 