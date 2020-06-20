#ifndef _JIANPAN_
#define _JIANPAN_
#include"reg52.h"
#include"lcd.h"
sbit interrupt0=P3^2;
void jianpanmain();
void delay(unsigned int i);
void jianpaninitial();
extern unsigned char idata keyresult;
extern bit anjianok;

#endif //_JIANPAN_