#ifndef __LED_H
#define __LED_H
#include "sys.h"

#define LED1 PEout(8)
#define LED2 PEout(9)
#define LED3 PEout(10)
#define LED4 PEout(11)
#define LED5 PEout(12)
#define LED6 PEout(13)
#define LED7 PEout(14)
#define LED8 PEout(15)

void LED_Init(void);
void LED_pmd(void);
#endif
