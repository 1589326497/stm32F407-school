/*
�ⲿ�жϿ�������ܺ�LED�ķ�ת ��Ŀ���ʱ��2023/12/6

KEY0 			�������գ�LED1��ת
KEY1 			�������գ�LED2��ת
KEY2 			�������ʾ��OFF�������ҹر�KEY0-2���ж�Դ
KEY-UP 			�������ʾ��ON����ͬʱ����KEY0-2���ж�Դ
 */


#include "exti.h"
#include "key.h"
#include "sys.h"
#include "delay.h"
#include "led.h"

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2 ��λ��ռ��λ��Ӧ
	
	delay_init(168);
	LED_Init();
	EXTIX_Init();
	while(1);
}
