#ifndef _LCD_H
#define _LCD_H
//����Ϊ��ʾ����ĺ�������
#include <reg52.h>
#include"moto.h"
#include <intrins.h>
#include<stdio.h>
#include"absacc.h" 
#include"chuankou.h"
void lcdmain();//��ʾ������
void exdelay(void);                     //��ʾ��ʱ�ӳ���
void ptchar(unsigned int c);           //��λд�ַ��ӳ���
void putstr(unsigned char  *s);     //��ʾ�ַ����ӳ���,�ַ���Ϊ0ʱ�˳�
void putstrxy(unsigned char cx,unsigned char cy,unsigned char  *s);
void charcursornext(void);              //���ַ�λ��Ϊ��һ����Чλ���ӳ���
void charlcdfill(unsigned int c);       //������ʾc������ַ������ӳ���
void charlcdpos(void);                  //����(CXPOS,CYPOS)�ڲ�DDRAM��ַ���ӳ���
void lcdreset(void);                    //Һ����ʾ��������ʼ���ӳ���
void delay3ms(void);                    //��ʱ3MS�ӳ���
void lcdwd(unsigned char d);            //��ͼ�������ӳ���
void lcdwc(unsigned char c);            //��ָ���ӳ���
void lcdwaitidle(void);                 //��������ʱ�ȴ�����
char* itostr(char *str, float i) ;
void lcdinitial();
//-------------------------------------------------------------------------------
//SMG12864G2-ZK��Ʒ����˵������ʾ����
//PIN1: VSS  [��Դ��]-------------------VSS
//PIN2: VDD  [��Դ����]-----------------VDD(+5V)
//PIN3: NC   [�ս�]
//PIN4: CS   [Ƭѡ�ź�����]-------------P3.0
//PIN5: STD  [������������]-------------P3.1
//PIN6: SCLK [������λ��������]---------P3.2
//PIN7: D0   [Data I/O]-----------------PB0
//PIN8: D1   [Data I/O]-----------------PB1
//PIN9: D2   [Data I/O]-----------------PB2
//PIN10:D3   [Data I/O]-----------------PB3
//PIN11:D4   [Data I/O]-----------------PB4
//PIN12:D5   [Data I/O]-----------------PB5
//PIN13:D6   [Data I/O]-----------------PB6
//PIN14:D7   [Data I/O]-----------------PB7
//PIN15:PSB  [ģ���ڲ���ѡ��,����]
//PIN16:NC   [�ս�]
//PIN17:RST  [��λ��,�͵�ƽ��Ч]--------VDD
//PIN18:NC   [�ս�]
//PIN19:BLA  [����Դ����]---------------��20ŷ���赽+5V.
//PIN20:BLK  [����Դ����]---------------VSS
#define COM8155 XBYTE[0x7F00]
#define PA8155 XBYTE[0x7F01]
#define PB8155 XBYTE[0x7F02]
#define PC8155 XBYTE[0x7F03]
sbit RSPIN   = P2^3;                    // RS��Ӧ��Ƭ������
sbit RWPIN   = P2^2;                    // RW��Ӧ��Ƭ������









#endif //_LCD_