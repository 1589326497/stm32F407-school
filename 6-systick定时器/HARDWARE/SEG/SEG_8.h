#ifndef _SEG_8_H_
#define _SEG_8_H_
#include "sys.h"

#define SEG_Data_Write(num) PEout(8)=(num&0x01);PEout(9)=(num>>1)&0x01;PEout(10)=(num>>2)&0x01;PEout(11)=(num>>3)&0x01;PEout(12)=(num>>4)&0x01;PEout(13)=(num>>5)&0x01;PEout(14)=(num>>6)&0x01;PEout(15)=(num>>7)&0x01;

void SEG_Init(void);	//��ʼ�������Ӳ��
void SEG_display(u8 num,u8 n); //���������λ
void SEG_Clear(void);

#endif

