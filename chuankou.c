#include"chuankou.h"



void initalchuan()           //�����жϳ�ʼ������
{
  SCON=0x50;                 //������� �趨��ʽ1
	TMOD=TMOD|0x20;
	PCON=0x00;                 //�����ʲ��ӱ�
	TH1=0xFD;
	TL1=0xFD;                  //������9600
	TR1=1;
	ES=1;                      //�������ж�
}




void sendone(unsigned char c)//���ڷ����ַ�
{
	                      //���ж�
  SBUF=c;
	TI=0;                      //���㷢�ͱ�־λ׼������
 	while(!TI);                //�ȴ��������
	                      //���ж�
}
void writedat_t()            //���η���xyz��λ����Ϣ
{int i;
	ES=0;
	
	 sendone('x');
	for(i=0;i<8;i++)
	{sendone(sx[i]);}
		sendone('y');
	for(i=0;i<8;i++)
	{sendone(sy[i]);}
	sendone('z');
   for(i=0;i<8;i++)
	{sendone(sz[i]);}
TI=0;
	ES=1;
}
void mainchuan() interrupt 4
{
	if(RI)                  //���ڽ����ж�
   {
		keyresult=SBUF;
		 anjianok=1;
	  RI=0;               //���ڽ����жϱ�־λҪ�ֶ�����
   }
}