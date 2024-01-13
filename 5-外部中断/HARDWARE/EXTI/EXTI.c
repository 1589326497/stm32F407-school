#include "exti.h"
#include "key.h"
#include "sys.h"
#include "delay.h"
#include "led.h"
#include "SEG_8.h"

void EXTI0_IRQHandler(void)	// WK_UP按键 中断服务程序
{

	delay_ms(20);	//消抖
	if(KEY_UP==0)
	{
		//开启KEY0-2的中断源
		EXTI->IMR |= EXTI_Line11; //使能外部中断11 对应KEY0
		EXTI->IMR |= EXTI_Line12; //使能外部中断12 对应KEY1
		EXTI->IMR |= EXTI_Line13; //使能外部中断13 对应KEY2
		while(1)
		{
			//显示on
			SEG_display(17,1);
			SEG_display(16,2);
			delay_ms(10);
			if(KEY0==0|KEY1==0|KEY2==0)	//其他按键按下跳出循环
				break;
		}
	}
	
	 EXTI_ClearITPendingBit(EXTI_Line0); //清除LINE0上的中断标志位 
}	

void EXTI15_10_IRQHandler(void)
{
	delay_ms(20);	//消抖
	if(KEY0==0)		
	{
		//数码管清空，LED1反转
		SEG_Clear();
		LED1=!LED1;
	}		 
	 EXTI_ClearITPendingBit(EXTI_Line11);  //清除LINE3上的中断标志位  
	if(KEY1==0)	 
	{	
		//数码管清空，LED2反转
		SEG_Clear();
		LED2=!LED2;
	}		 
	 EXTI_ClearITPendingBit(EXTI_Line12);  //清除LINE3上的中断标志位
	if(KEY2==0)	 
	{
		//关闭KEY0-2的中断源前先清除LINE0上的中断标志位 防止无法进入EXTI_Line0中断线
		EXTI_ClearITPendingBit(EXTI_Line0); 
		//并且关闭KEY0-2的中断源
		EXTI->IMR &= ~(EXTI_Line11); //屏蔽外部中断11
		EXTI->IMR &= ~(EXTI_Line12); //屏蔽外部中断12
		EXTI->IMR &= ~(EXTI_Line13); //屏蔽外部中断13
		//数码管先清空
		SEG_Clear();
		while(1)
		{
			//数码管显示“OFF”
			SEG_display(17,1);
			SEG_display(15,2);
			SEG_display(15,3);
			delay_ms(10);
			if(KEY0==0|KEY1==0|KEY_UP==0)	//其他按键按下跳出循环
				break;
		}
	}		 
	 EXTI_ClearITPendingBit(EXTI_Line13);  //清除LINE3上的中断标志位
}

void EXTIX_Init(void)
{
	//定义NVIC 和 EXTI 结构体
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
