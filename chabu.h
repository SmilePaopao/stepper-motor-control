#ifndef _CHABU_H
#define _CHABU_H
#include<reg52.h>

#include"moto.h"
#include"chuankou.h"
void G00(long x0,long y0,long z0);//���ٶ�λ
void G01(long x0,long y0,long z0);//ֱ��
void G02(long x0,long y0,long x1,long y1);//˳԰
void G03(long x0,long y0,long x1,long y1);//��Բ


void linechabumain();//ֱ��
 void ncirclechabumain();//��Բ
	  void scirclechabumain();//˳Բ
		void automotormain();//�Զ�����

void chabuinitial();//�岹��ʼ��
void zxxxchoose();//�ж�ֱ���յ�λ��
void chabumotor() ;//�岹���巢��
signed long labs(signed long z);//����ֵ
extern signed long  totalsteps;//ֱ���ܲ���
extern signed long  F_xy;//xyƽ�����ж�
extern signed long  F_xz;//xzƽ�����ж�
extern signed long  x,y;//Բ����ʼ�������
extern signed long  x0,y0,z0;//�յ�����x
extern signed long  x1,y1;//Բ������
extern unsigned char  Gchoose;//�ж���ѡ���ĸ�����


#endif //_CHABU_