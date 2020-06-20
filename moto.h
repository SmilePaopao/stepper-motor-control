#ifndef _MOTO_H
#define _MOTO_H
#include<reg52.h>
#include"jianpan.h"
sbit xspeed=P1^0;//x轴频率
sbit xdir=P1^1;  //x轴方向
sbit yspeed=P1^2;//y轴频率
sbit ydir=P1^3;  //y轴方向
sbit zspeed=P1^4;//z轴频率
sbit zdir=P1^5;  //z轴方向
sbit xleft=P2^1; //x左限位
sbit xright=P2^4;//x右限位
sbit yleft=P2^5; //y左限位
sbit yright=P2^6;//y右限位
sbit zleft=P1^6; //z左限位
sbit zright=P1^7;//z右限位
void motorinitial();//设置中断
void motor();//t0发出频率函数
void inital();//回原点

extern bit xon;
extern bit yon;
extern bit zon;
extern bit kuaisu;

extern signed long idata  xdat_t;
extern signed long idata ydat_t;
extern signed long idata zdat_t;
#endif //_MOTO_
