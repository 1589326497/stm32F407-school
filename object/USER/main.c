/*************************
���󣺰��¶���������KEY_UP,KEY1,KEY2,KEY3��
��Ӧ��LED��ת,�����������û�з�Ӧ
�����Ƿ�LED�ƿ��ش�
 ***********************/


#include "exti.h"
#include "key.h"
#include "sys.h"
#include "delay.h"
#include "led.h"

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);
	LED_Init();
	EXTIX_Init();
	while(1);
}
