#ifndef _MOTO_H
#define _MOTO_H
#include<reg52.h>
#include"jianpan.h"
sbit xspeed=P1^0;//x��Ƶ��
sbit xdir=P1^1;  //x�᷽��
sbit yspeed=P1^2;//y��Ƶ��
sbit ydir=P1^3;  //y�᷽��
sbit zspeed=P1^4;//z��Ƶ��
sbit zdir=P1^5;  //z�᷽��
sbit xleft=P2^1; //x����λ
sbit xright=P2^4;//x����λ
sbit yleft=P2^5; //y����λ
sbit yright=P2^6;//y����λ
sbit zleft=P1^6; //z����λ
sbit zright=P1^7;//z����λ
void motorinitial();//�����ж�
void motor();//t0����Ƶ�ʺ���
void inital();//��ԭ��

extern bit xon;
extern bit yon;
extern bit zon;
extern bit kuaisu;

extern signed long idata  xdat_t;
extern signed long idata ydat_t;
extern signed long idata zdat_t;
#endif //_MOTO_
