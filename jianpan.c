#include"jianpan.h"
unsigned char temp,key;
bit anjianok;
unsigned char idata keyresult;
void delay(unsigned int i)            //延时程序用于键盘防抖
{
   unsigned int j;
   for(;i>0;i--)
       for(j=0;j<100;j++);
}
void jianpaninitial()                 //键盘程序初始化
{
	EX0=1;                              //允许外部中断0
	IT0=1;                              //边沿触发中断
	PA8155=0xf0;                        //行信号置零
}
void jianpanmain() interrupt 0        //键盘外部中断子程序
{
   
	  delay(1);
		if(!interrupt0)
		{   
			PA8155=0xfe;
			delay(1);
			key=PC8155&0x0f;//第一行
			if((key&0x01)==0){keyresult='7';}//第一行第一列按钮被按下 x进
		  if((key&0x02)==0){keyresult='8';}//第一行第二列按钮被按下 y进
			if((key&0x04)==0){keyresult='9';}//第一行第三列按钮被按下 z进
			if((key&0x08)==0){keyresult='x';}//第一行第四列按钮被按下 xy工作台直线
				
			PA8155=0xfd;
			delay(1);
			key=PC8155&0x0f;//第二行
			if((key&0x01)==0){keyresult='4';}//第二行第一列按钮被按下 x退
		  if((key&0x02)==0){keyresult='5';}//第二行第二列按钮被按下 y退
			if((key&0x04)==0){keyresult='6';}//第二行第三列按钮被按下 z退
			if((key&0x08)==0){keyresult='y';}//第二行第四列按钮被按下 
				
			PA8155=0xfb;
			delay(1);
			key=PC8155&0x0f;//第三行
			if((key&0x01)==0){keyresult='1';}//第三行第一列按钮被按下 x停
		  if((key&0x02)==0){keyresult='2';}//第三行第二列按钮被按下 y停
			if((key&0x04)==0){keyresult='3';}//第三行第三列按钮被按下 z停
			if((key&0x08)==0){keyresult='z';}//第三行第四列按钮被按下 全停
				
			PA8155=0xf7;
			delay(1);
			key=PC8155&0x0f;//第四行
			if((key&0x01)==0){keyresult='0';}//第四行第一列按钮被按下 快速
  		if((key&0x02)==0){keyresult='.';}//第四行第二列按钮被按下 慢速
			if((key&0x04)==0){keyresult='a';}//第四行第三列按钮被按下 回原点
			if((key&0x08)==0){keyresult='G';}//第四行第四列按钮被按下 自动
		anjianok=1;
		}
	  PA8155=0xf0;
} 
