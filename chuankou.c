#include"chuankou.h"



void initalchuan()           //串口中断初始化程序
{
  SCON=0x50;                 //允许接受 设定方式1
	TMOD=TMOD|0x20;
	PCON=0x00;                 //波特率不加倍
	TH1=0xFD;
	TL1=0xFD;                  //波特率9600
	TR1=1;
	ES=1;                      //开串口中断
}




void sendone(unsigned char c)//串口发送字符
{
	                      //关中断
  SBUF=c;
	TI=0;                      //清零发送标志位准备发送
 	while(!TI);                //等待发送完成
	                      //开中断
}
void writedat_t()            //依次发送xyz的位置信息
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
	if(RI)                  //串口接收中断
   {
		keyresult=SBUF;
		 anjianok=1;
	  RI=0;               //串口接收中断标志位要手动清零
   }
}