#include "exti.h"
#include "key.h"
#include "sys.h"
#include "delay.h"
#include "led.h"

void EXTI0_IRQHandler(void)
{
	delay_ms(20);	//消抖
	if(KEY_UP==1)	 
	{
		LED1=!LED1; 
	}		 
	 EXTI_ClearITPendingBit(EXTI_Line0); //清除LINE0上的中断标志位 
}	

void EXTI15_10_IRQHandler(void)
{
	delay_ms(20);	//消抖
	if(KEY0==0)	 
	{
		LED2=!LED2;
	}		 
	 EXTI_ClearITPendingBit(EXTI_Line11);  //清除LINE3上的中断标志位  
	if(KEY1==0)	 
	{
		LED3=!LED3;
	}		 
	 EXTI_ClearITPendingBit(EXTI_Line12);  //清除LINE3上的中断标志位
	if(KEY2==0)	 
	{
		LED4=!LED4;
	}		 
	 EXTI_ClearITPendingBit(EXTI_Line13);  //清除LINE3上的中断标志位
}

void EXTIX_Init(void)
{
	NVIC_InitTypeDef   NVIC_InitStructure;
	EXTI_InitTypeDef   EXTI_InitStructure;
	

	KEY_Init(); //按键对应的IO口初始化
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);//使能SYSCFG时钟
	
 
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource11);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource12);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource13);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);//PA0 连接到中断线0
	
  /* 配置EXTI_Line0 */
  EXTI_InitStructure.EXTI_Line = EXTI_Line0;//LINE0
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//中断事件
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising; //上升沿触发 
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;//使能LINE0
  EXTI_Init(&EXTI_InitStructure);//配置
	
	/* 配置EXTI_Line2,3,4 */
	EXTI_InitStructure.EXTI_Line = EXTI_Line11 | EXTI_Line12 | EXTI_Line13;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//中断事件
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //下降沿触发
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;//中断线使能
  EXTI_Init(&EXTI_InitStructure);//配置
 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;//外部中断0
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;//抢占优先级为0
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;//响应优先级为3
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//使能外部中断通道
  NVIC_Init(&NVIC_InitStructure);//配置
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;//外部中断2
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//使能外部中断通道
  NVIC_Init(&NVIC_InitStructure);//配置

}
