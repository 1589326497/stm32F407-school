#include "stm32f4xx.h"
#include "systick.h"

void delay_nms(u32 t)//���ʱ 798ms
{		
	u32 temp;	   
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8); 	
	SysTick->LOAD=t*21000; 				//ʱ�����	  		 
	SysTick->VAL=0x00;        				//��ռ�����
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ; //��ʼ���� 	 
	do
	{
		temp=SysTick->CTRL;
	}while((temp&0x01)&&!(temp&(1<<16)));	//�ȴ�ʱ�䵽��   
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk; //�رռ�����
	SysTick->VAL =0X00;       				//��ռ����� 
}

void delay_ms(u16 nms)//���ʱ 65535ms  ��Ϊnms���õ���u16����
{	 	 
	u8 repeat=nms/540;										
	u16 remain=nms%540;
	while(repeat)
	{
		delay_nms(540);
		repeat--;
	}
	if(remain)delay_nms(remain);
} 

