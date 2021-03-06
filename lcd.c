//SMG12864G2-ZK标准字符点阵型液晶显示模块的程序[C51编程语言][MCS51并行接口方式]
//应用产品: SMG12864G2-ZK SMG12864ZK SMG12864G3-ZK标准中文字符点阵型液晶显示模块
//本程序适用于SMG12864G2-ZK液晶显示模块与MCS51系列单片机采用MCS51并行接口
//方式的硬件连线方式。
// 本程序包括ST7920兼容芯片的MCS51并行接口方式子程序集,SMG12864系列标准中文
//字符点阵型液晶显示模块的接口子程序集,ST7920兼容芯片的液晶显示控制器的通用子程序
//集,以及SMG12864系列标准中文字符点阵型液晶显示的演示子程序.
//  本文件的内容为显示三个步进电机的状态，包括位移速度，等等。
//-------------------------------------------------------------------------------
#include"lcd.h"
//-------------------------------------------------------------------------------
//以下CXPOS,CYPOS变量用于指示当前操作字符的位置的预定义
unsigned char idata CXPOS;                    //列方向地址指针(用于charlcdpos子程序)
unsigned char idata CYPOS;                    //行方向地址指针(用于charlcdpos子程序)
void lcdinitial()
{
	lcdreset();                           //液晶显示控制器初始化
  charlcdfill(' ');                     //显示清屏
exdelay();   	
  putstrxy(0,0,"位移mm状态显示：");      //在(10,2)位置开始显示字符串
CXPOS=0,CYPOS=1;
	ptchar('x');                          //当前位置显示为x字符
CXPOS=0,CYPOS=2;
	ptchar('y');                          //当前位置显示为y字符
CXPOS=0,CYPOS=3;			
	ptchar('z');                          //当前位置显示为z
putstrxy(10,1,"慢速");                  //在(10,2)位置开始显示字符串
	exdelay();   
}
void lcdmain()
{  
  
  	
putstrxy(2,1,sx);                       //在(0,3)位置开始显示字符串 
putstrxy(2,2,sy);                       //在(0,3)位置开始显示字符串
putstrxy(2,3,sz);                       //在(0,3)位置开始显示字符串
exdelay();    
}
void exdelay(void)                      //演示延时子程序
{ unsigned char i,j,k;                  //延时约30mS
  for(i=0;i<3;i++)
    for(j=0;j<64;j++)
      for(k=0;k<51;k++);
}
//以下putchar为字符对象的基本子程序,putstr为字符对象的扩充子程序,
//-------------------------------------------------------------------------------
//子程序名称:void charlcdfill(unsigned int c).
//功能:整屏显示A代表的ASCII字符.
//-------------------------------------------------------------------------------
void charlcdfill(unsigned int c)        //整屏显示A代表的ASCII字符子程序
{   for(CXPOS=CYPOS=0;1;)
    {   ptchar(c);                      //定位写字符
        if((CXPOS==0) && (CYPOS==0)) break;
    }
}
//-------------------------------------------------------------------------------
//子程序名称:void putchar(unsigned int c).
//功能:在(XPOS,YPOS)位置写单个字符点阵,若c>128 表示为中文字符,否则为西文字符
//-------------------------------------------------------------------------------
void ptchar(unsigned int c)             //定位写字符子程序
{   unsigned char d;
    if(c>128)                           //字符码大于128表示为汉字
    {   if( (CXPOS&0x1)==1 )            //写汉字时,CXPOS字符位置在奇数位置,则
        {   lcdwd(' ');                 //自动补添一个空格对齐后再显示汉字
            charcursornext();           //置字符位置为下一个有效位置
        }
        charlcdpos();
        lcdwd(c/256);                   //写高位字符
        charcursornext();
        lcdwd(c&0xff);                  //写低位字符
        charcursornext();
    }
    else                                //字符码小于128表示为ASCII字符
    {   charlcdpos();
        if( (CXPOS&0x1)==1 )            //写ASCII字符时,CXPOS字符位置在奇数位置,则
        {                     
            charlcdpos();
            lcdwd(d);                   //重新写高位字符
            lcdwd(c);
        }
        else
        {   lcdwd(c);                   //写ASCII字符时,CXPOS字符位置在偶数位置,则
             d=c;
				}
        charcursornext();               //置字符位置为下一个有效位置
    }
}
//-------------------------------------------------------------------------------
//子程序名称:void putstr(unsigned char code *s).
//功能:写字符串点阵,若*s=0 表示字符串结束.
//-------------------------------------------------------------------------------
void putstr(unsigned char  *s)          //显示字符串子程序,字符码为0时退出
{   unsigned int c;
    while(1)
    {   c=*s;
        s++;
        if(c==0) break;
        if(c<128)
            ptchar(c);
        else
        {   ptchar(c*256+*s);
            s++;
        }
    }
}
//-------------------------------------------------------------------------------
//子程序名称:void putstrxy(unsigned char cx,unsigned char cy,unsigned char *s).
//功能:在(cx,cy)字符位置写字符串.
//-------------------------------------------------------------------------------
void putstrxy(unsigned char cx,unsigned char cy,unsigned char  *s)
{                                       //在(cx,cy)字符位置写字符串子程序
    CXPOS=cx;                           //置当前X位置为cx
    CYPOS=cy;                           //置当前Y位置为cy
    putstr(s);
}
//-------------------------------------------------------------------------------
//以下为charlcdpos,charcursornext,lcdreset为ST7920兼容芯片的液晶显示控制器的
//16ASCII字符X4行的SMG12864系列标准中文字符点阵型液晶显示模块的接口程序.
//-------------------------------------------------------------------------------
//子程序名称:void charlcdpos(void).
//功能:设置坐标点(CXPOS,CYPOS)位置对应的内部RAM地址.
//-------------------------------------------------------------------------------
void charlcdpos(void)                   //设置坐标点(CXPOS,CYPOS)内部RAM地址的子程序
{  unsigned char ddaddr;
   CXPOS&=0xf;                          //X位置范围(0到15)
   ddaddr=CXPOS/2;
    if(CYPOS==0)                        //(第一行)X: 第0----15个字符
        lcdwc(ddaddr|0x80);             //    DDRAM:  80----87H
    else if(CYPOS==1)                   //(第二行)X: 第0----19个字符
        lcdwc(ddaddr|0x90);             //    DDRAM:  90----07H
    else if(CYPOS==2)                   //(第三行)X: 第0----19个字符
        lcdwc(ddaddr|0x88);             //    DDRAM:  88----8FH
    else                                //(第四行)X: 第0----19个字符
        lcdwc(ddaddr|0x98);             //    DDRAM:  98----9FH
}
//-------------------------------------------------------------------------------
//子程序名称:void charcursornext(void).
//功能:置字符位置为下一个有效位置.
//-------------------------------------------------------------------------------
void charcursornext(void)               //置字符位置为下一个有效位置子程序
{
    CXPOS++;                            //字符位置加1
    CXPOS&=0x0f;                        //字符位置CXPOS的有效范围为(0到15)
    if(CXPOS==0)                        //字符位置CXPOS=0表示要换行
    {   CYPOS++;                        //行位置加1
        CYPOS&=0X3;                     //字符位置CYPOS的有效范围为(0到3)
    }
}
//-------------------------------------------------------------------------------
//子程序名称:void lcdreset(void)
//功能:液晶显示控制器初始化
//-------------------------------------------------------------------------------
void lcdreset(void)                     //液晶显示控制器初始化子程序
{   lcdwc(0x33);                        //接口模式设置
    delay3ms();                         //延时3MS
    lcdwc(0x30);                        //基本指令集
    delay3ms();                         //延时3MS
    lcdwc(0x30);                        //重复送基本指令集
    delay3ms();                         //延时3MS
    lcdwc(0x01);                        //清屏控制字
    delay3ms();                         //延时3MS
	  lcdwc(0x30);                        //设置为基本指令集,开显示
    lcdwc(0x0c);
}
void delay3ms(void)                     //延时3MS子程序
{ unsigned char i,j,k;
  for(i=0;i<3;i++)
    for(j=0;j<64;j++)
      for(k=0;k<51;k++);
}
//-------------------------------------------------------------------------------
//以下lcdwc,lcdwd为ST7920兼容芯片的MCS51三线式串行接口方式的基本子程序,lcdwaitidle
//为内部子程序.
//-------------------------------------------------------------------------------
//子程序名称:void lcdwd(unsigned char d).
//功能:向液晶显示控制器写数据.
//-------------------------------------------------------------------------------
void lcdwd(unsigned char d)             //向液晶显示控制器写数据
{   lcdwaitidle();                      //ST7920液晶显示控制器忙延时
    PB8155=d;
    RSPIN=1;                            //RS=1 RW=0 E=高脉冲
    RWPIN=0;
    _nop_();
   
}
//-------------------------------------------------------------------------------
//子程序名称:lcdwc(unsigned char c).
//功能:向液晶显示控制器送指令.
//-------------------------------------------------------------------------------
void lcdwc(unsigned char c)             //向液晶显示控制器送指令
{   lcdwaitidle();                      //ST7920液晶显示控制器忙延时
    PB8155=c;
    RSPIN=0;                            //RS=0 RW=0 E=高脉冲
    RWPIN=0;
    _nop_();
  
}
//-------------------------------------------------------------------------------
//子程序名称:void lcdwaitidle(void).
//功能:忙检测,在对液晶显示控制器操作的每一条指令之前,需检测液晶显示器是否空闲.
//-------------------------------------------------------------------------------
void lcdwaitidle(void)                  //控制器延时子程序
{   unsigned int i;
  for(i=0;i<100;i++);
    
}