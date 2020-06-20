#include"moto.h"
#include"lcd.h"
#include"jianpan.h"
#include"chuankou.h"
#include "chabu.h"
void main()
{
signed long shuru[5];int i;
	keyresult='z';
	COM8155=0x0f;
  PA8155=0xff;
	PC8155=0xff;//为初始化扩展I/O口做准备
	COM8155=0x03;//PA输入，PB，PC输出
	TMOD=0;//TMOD置零为TMOD初始化做准备
	
	jianpaninitial();//键盘初始化 外部中断0 边沿触发
	motorinitial();//脉冲发出函数初始化 中断T0 
//	lcdinitial();//lcd初始化程序
  chabuinitial();//插补初始化
initalchuan();//串口通信初始化 T1作为波特率发生器
	
	
	EA=1;//开中断
while(1)
{                                               
	 jisuandisplay();		 
	//lcdmain();
writedat_t() ; 
	switch(keyresult)
	{
		
		case '7':xon=1;xdir=1;TR0=1;TR2=0;keyresult='n';break;//第一行第一列按钮被按下 x进
    case '8':yon=1;ydir=1;TR0=1;TR2=0;keyresult='n';break;//第一行第二列按钮被按下 y进
		case '9':zon=1;zdir=1;TR0=1;TR2=0;keyresult='n';break;//第一行第三列按钮被按下 z进
		case 'x':{delay(1);
    TR0=0;TR2=1;anjianok=0;while(!anjianok){if(keyresult=='z')break;}
	while(keyresult!='z')	
	{switch(keyresult)//数控菜单
			{case'7':G00(x0,y0,z0);anjianok=0;	while(!anjianok){jisuandisplay();writedat_t() ;if(keyresult=='z')break;}break;
			 case'8':G01(x0,y0,z0);anjianok=0;	while(!anjianok){jisuandisplay();writedat_t() ;if(keyresult=='z')break;}break;
			 case '9':G02(x0,y0,x1,y1);anjianok=0;	while(!anjianok){jisuandisplay();writedat_t() ;if(keyresult=='z')break;}break;
			 case 'x':G03(x0,y0,x1,y1);anjianok=0;	while(!anjianok){jisuandisplay();writedat_t() ;if(keyresult=='z')break;}break;
			}
		}			
			keyresult='n';
		  break; 
		          }//第一行第四列按钮被按下


		case '4':xon=1;xdir=0;TR0=1;TR2=0;keyresult='n';break;//第二行第一列按钮被按下 x退
		case '5':yon=1;ydir=0;TR0=1;TR2=0;keyresult='n';break;//第二行第二列按钮被按下 y退
		case '6':zon=1;zdir=0;TR0=1;TR2=0;keyresult='n';break;//第二行第三列按钮被按下 z退
		case 'y'://坐标输入
			{
	anjianok=0;
		while(!anjianok){if(keyresult=='z')break;}//等待按键按下
			for(i=4 ;i>=0;i--){ shuru[i]=keyresult-48;delay(1);anjianok=0;while(!anjianok){if(keyresult=='z')break;}  }
			
			while(keyresult!='z')
			{switch(keyresult)
			{
		  case '.':x0=10000*shuru[4]+1000*shuru[3]+100*shuru[2]+10*shuru[1]+shuru[0];sx[0]=sx[1]=sx[2]=32;for(i=4 ;i>=0;i--){ sx[7-i]=shuru[i]+48;}writedat_t();anjianok=0;	while(!anjianok){if(keyresult=='z')break;}break;
			case 'a':y0=10000*shuru[4]+1000*shuru[3]+100*shuru[2]+10*shuru[1]+shuru[0];sy[0]=sy[1]=sy[2]=32;for(i=4 ;i>=0;i--){ sy[7-i]=shuru[i]+48;}writedat_t() ;anjianok=0;	while(!anjianok){if(keyresult=='z')break;}break;
			case 'G':z0=10000*shuru[4]+1000*shuru[3]+100*shuru[2]+10*shuru[1]+shuru[0];sz[0]=sz[1]=sz[2]=32;for(i=4 ;i>=0;i--){ sz[7-i]=shuru[i]+48;}writedat_t() ;anjianok=0;	while(!anjianok){if(keyresult=='z')break;}break;
			case 'x':x1=10000*shuru[4]+1000*shuru[3]+100*shuru[2]+10*shuru[1]+shuru[0];sx[0]=sx[1]=sx[2]=32;for(i=4 ;i>=0;i--){ sx[7-i]=shuru[i]+48;}writedat_t() ;anjianok=0;	while(!anjianok){if(keyresult=='z')break;}break;
			case 'y':y1=10000*shuru[4]+1000*shuru[3]+100*shuru[2]+10*shuru[1]+shuru[0];sy[0]=sy[1]=sy[2]=32;for(i=4 ;i>=0;i--){ sy[7-i]=shuru[i]+48;}writedat_t() ;anjianok=0;	while(!anjianok){if(keyresult=='z')break;}break;
			}
		}
			keyresult='n';break;}//第二行第四列按钮被按下
		case '1':xon=0;TR0=1;TR2=0;keyresult='n';break;//第三行第一列按钮被按下 x停
		case '2':	yon=0;TR0=1;TR2=0;keyresult='n';break; //第三行第二列按钮被按下 y停
	  case '3':zon=0;TR0=1;TR2=0;keyresult='n';break; //第三行第三列按钮被按下 z停
		case 'z':TR0=1;TR2=0;xon=0;yon=0;zon=0;keyresult='n';break; //第三行第四列按钮被按下 全停
	  case '0':TR0=1;TR2=0;kuaisu=1;keyresult='n';break;//第四行第一列按钮被按下 快速
	  case '.':TR0=1;TR2=0;kuaisu=0;keyresult='n';break;//第四行第二列按钮被按下 慢速
		case 'a':TR0=1;TR2=0;inital();keyresult='n';break;//第四行第三列按钮被按下  回原点
		case 'G':{	automotormain();keyresult='n';break;  }//第四行第四列按钮被按下  自动
	 }
 
 }
}
	