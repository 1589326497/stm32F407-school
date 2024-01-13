/*
�����ʵ�ּ������� ����λΪ���� ����λΪ�� ����1���� ����2�ر�

*/


#include "stm32f4xx.h"
#include "delay.h"
#include "SEG_8.h"
#include "key.h"
uint16_t name;
u8 key_sign;

void scan_key() {
    if (KEY_SCAN() == 1) {
        key_sign = 1;
    } else if (KEY_SCAN() == 2) {
        key_sign = 2;
    } else {
        key_sign = 0;
    }
}

void display_name() {
    SEG_display(1, name % 10); // ��ʾ��λ
    SEG_display(2, (name % 100) / 10); // ��ʾʮλ
    SEG_display(3, (name % 1000) / 100); // ��ʾ��λ
    SEG_display(4, (name % 10000) / 1000); // ��ʾǧλ
}

int main(void) {
    delay_init(168);
    SEG_Init();
    while (1) 
	{
        scan_key();
        if (key_sign == 1) 
		{
			display_name();
            name++;
			
        } 
		else if (key_sign == 2) 
		{
            name = 0;
        }
        delay_ms(1);
        
    }
}
