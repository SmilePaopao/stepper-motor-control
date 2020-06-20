#ifndef _LCD_H
#define _LCD_H
//以下为演示程序的函数定义
#include <reg52.h>
#include"moto.h"
#include <intrins.h>
#include<stdio.h>
#include"absacc.h" 
#include"chuankou.h"
void lcdmain();//显示主程序
void exdelay(void);                     //演示延时子程序
void ptchar(unsigned int c);           //定位写字符子程序
void putstr(unsigned char  *s);     //显示字符串子程序,字符码为0时退出
void putstrxy(unsigned char cx,unsigned char cy,unsigned char  *s);
void charcursornext(void);              //置字符位置为下一个有效位置子程序
void charlcdfill(unsigned int c);       //整屏显示c代表的字符数据子程序
void charlcdpos(void);                  //设置(CXPOS,CYPOS)内部DDRAM地址的子程序
void lcdreset(void);                    //液晶显示控制器初始化子程序
void delay3ms(void);                    //延时3MS子程序
void lcdwd(unsigned char d);            //送图形数据子程序
void lcdwc(unsigned char c);            //送指令子程序
void lcdwaitidle(void);                 //控制器延时等待程序
char* itostr(char *str, float i) ;
void lcdinitial();
//-------------------------------------------------------------------------------
//SMG12864G2-ZK产品引脚说明及演示连线
//PIN1: VSS  [电源地]-------------------VSS
//PIN2: VDD  [电源正极]-----------------VDD(+5V)
//PIN3: NC   [空脚]
//PIN4: CS   [片选信号输入]-------------P3.0
//PIN5: STD  [串行数据输入]-------------P3.1
//PIN6: SCLK [串行移位脉冲输入]---------P3.2
//PIN7: D0   [Data I/O]-----------------PB0
//PIN8: D1   [Data I/O]-----------------PB1
//PIN9: D2   [Data I/O]-----------------PB2
//PIN10:D3   [Data I/O]-----------------PB3
//PIN11:D4   [Data I/O]-----------------PB4
//PIN12:D5   [Data I/O]-----------------PB5
//PIN13:D6   [Data I/O]-----------------PB6
//PIN14:D7   [Data I/O]-----------------PB7
//PIN15:PSB  [模块内部已选择,悬空]
//PIN16:NC   [空脚]
//PIN17:RST  [复位端,低电平有效]--------VDD
//PIN18:NC   [空脚]
//PIN19:BLA  [背光源正极]---------------接20欧电阻到+5V.
//PIN20:BLK  [背光源负极]---------------VSS
#define COM8155 XBYTE[0x7F00]
#define PA8155 XBYTE[0x7F01]
#define PB8155 XBYTE[0x7F02]
#define PC8155 XBYTE[0x7F03]
sbit RSPIN   = P2^3;                    // RS对应单片机引脚
sbit RWPIN   = P2^2;                    // RW对应单片机引脚









#endif //_LCD_