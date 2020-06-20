#ifndef _CHABU_H
#define _CHABU_H
#include<reg52.h>

#include"moto.h"
#include"chuankou.h"
void G00(long x0,long y0,long z0);//快速定位
void G01(long x0,long y0,long z0);//直线
void G02(long x0,long y0,long x1,long y1);//顺园
void G03(long x0,long y0,long x1,long y1);//逆圆


void linechabumain();//直线
 void ncirclechabumain();//逆圆
	  void scirclechabumain();//顺圆
		void automotormain();//自动程序

void chabuinitial();//插补初始化
void zxxxchoose();//判断直线终点位置
void chabumotor() ;//插补脉冲发出
signed long labs(signed long z);//绝对值
extern signed long  totalsteps;//直线总步数
extern signed long  F_xy;//xy平面内判断
extern signed long  F_xz;//xz平面内判断
extern signed long  x,y;//圆弧初始相对坐标
extern signed long  x0,y0,z0;//终点坐标x
extern signed long  x1,y1;//圆心坐标
extern unsigned char  Gchoose;//中断里选择哪个函数


#endif //_CHABU_