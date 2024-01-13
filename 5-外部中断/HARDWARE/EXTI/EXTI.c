#include "exti.h"
#include "key.h"
#include "sys.h"
#include "delay.h"
#include "led.h"
#include "SEG_8.h"

void EXTI0_IRQHandler(void)	// WK_UP���� �жϷ������
{

	delay_ms(20);	//����
	if(KEY_UP==0)
	{
		//����KEY0-2���ж�Դ
		EXTI->IMR |= EXTI_Line11; //ʹ���ⲿ�ж�11 ��ӦKEY0
		EXTI->IMR |= EXTI_Line12; //ʹ���ⲿ�ж�12 ��ӦKEY1
		EXTI->IMR |= EXTI_Line13; //ʹ���ⲿ�ж�13 ��ӦKEY2
		while(1)
		{
			//��ʾon
			SEG_display(17,1);
			SEG_display(16,2);
			delay_ms(10);
			if(KEY0==0|KEY1==0|KEY2==0)	//����������������ѭ��
				break;
		}
	}
	
	 EXTI_ClearITPendingBit(EXTI_Line0); //���LINE0�ϵ��жϱ�־λ 
}	

void EXTI15_10_IRQHandler(void)
{
	delay_ms(20);	//����
	if(KEY0==0)		
	{
		//�������գ�LED1��ת
		SEG_Clear();
		LED1=!LED1;
	}		 
	 EXTI_ClearITPendingBit(EXTI_Line11);  //���LINE3�ϵ��жϱ�־λ  
	if(KEY1==0)	 
	{	
		//�������գ�LED2��ת
		SEG_Clear();
		LED2=!LED2;
	}		 
	 EXTI_ClearITPendingBit(EXTI_Line12);  //���LINE3�ϵ��жϱ�־λ
	if(KEY2==0)	 
	{
		//�ر�KEY0-2���ж�Դǰ�����LINE0�ϵ��жϱ�־λ ��ֹ�޷�����EXTI_Line0�ж���
		EXTI_ClearITPendingBit(EXTI_Line0); 
		//���ҹر�KEY0-2���ж�Դ
		EXTI->IMR &= ~(EXTI_Line11); //�����ⲿ�ж�11
		EXTI->IMR &= ~(EXTI_Line12); //�����ⲿ�ж�12
		EXTI->IMR &= ~(EXTI_Line13); //�����ⲿ�ж�13
		//����������
		SEG_Clear();
		while(1)
		{
			//�������ʾ��OFF��
			SEG_display(17,1);
			SEG_display(15,2);
			SEG_display(15,3);
			delay_ms(10);
			if(KEY0==0|KEY1==0|KEY_UP==0)	//����������������ѭ��
				break;
		}
	}		 
	 EXTI_ClearITPendingBit(EXTI_Line13);  //���LINE3�ϵ��жϱ�־λ
}

void EXTIX_Init(void)
{
	//����NVIC �� EXTI �ṹ��
	NVIC_InitTypeDef   NVIC_InitStructure;
	EXTI_InitTypeDef   EXTI_InitStructure;
	

	KEY_Init(); //������Ӧ��IO�ڳ�ʼ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);//ʹ��SYSCFGʱ��
	
 
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource11);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource12);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource13);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);//PA0 ���ӵ��ж���0
	
  /* ����EXTI_Line0 */
  EXTI_InitStructure.EXTI_Line = EXTI_Line0;//LINE0
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//�ж��¼�
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising; //�����ش��� 
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;//ʹ��LINE0
  EXTI_Init(&EXTI_InitStructure);//����
	
	/* ����EXTI_Line2,3,4 */
	EXTI_InitStructure.EXTI_Line = EXTI_Line11 | EXTI_Line12 | EXTI_Line13;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//�ж��¼�
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //�½��ش���
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;//�ж���ʹ��
  EXTI_Init(&EXTI_InitStructure);//����
 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;//�ⲿ�ж�0
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;//��ռ���ȼ�Ϊ0
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;//��Ӧ���ȼ�Ϊ3
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//ʹ���ⲿ�ж�ͨ��
  NVIC_Init(&NVIC_InitStructure);//����
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;//�ⲿ�ж�2
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//ʹ���ⲿ�ж�ͨ��
  NVIC_Init(&NVIC_InitStructure);//����

}
