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
	PC8155=0xff;//Ϊ��ʼ����չI/O����׼��
	COM8155=0x03;//PA���룬PB��PC���
	TMOD=0;//TMOD����ΪTMOD��ʼ����׼��
	
	jianpaninitial();//���̳�ʼ�� �ⲿ�ж�0 ���ش���
	motorinitial();//���巢��������ʼ�� �ж�T0 
//	lcdinitial();//lcd��ʼ������
  chabuinitial();//�岹��ʼ��
initalchuan();//����ͨ�ų�ʼ�� T1��Ϊ�����ʷ�����
	
	
	EA=1;//���ж�
while(1)
{                                               
	 jisuandisplay();		 
	//lcdmain();
writedat_t() ; 
	switch(keyresult)
	{
		
		case '7':xon=1;xdir=1;TR0=1;TR2=0;keyresult='n';break;//��һ�е�һ�а�ť������ x��
    case '8':yon=1;ydir=1;TR0=1;TR2=0;keyresult='n';break;//��һ�еڶ��а�ť������ y��
		case '9':zon=1;zdir=1;TR0=1;TR2=0;keyresult='n';break;//��һ�е����а�ť������ z��
		case 'x':{delay(1);
    TR0=0;TR2=1;anjianok=0;while(!anjianok){if(keyresult=='z')break;}
	while(keyresult!='z')	
	{switch(keyresult)//���ز˵�
			{case'7':G00(x0,y0,z0);anjianok=0;	while(!anjianok){jisuandisplay();writedat_t() ;if(keyresult=='z')break;}break;
			 case'8':G01(x0,y0,z0);anjianok=0;	while(!anjianok){jisuandisplay();writedat_t() ;if(keyresult=='z')break;}break;
			 case '9':G02(x0,y0,x1,y1);anjianok=0;	while(!anjianok){jisuandisplay();writedat_t() ;if(keyresult=='z')break;}break;
			 case 'x':G03(x0,y0,x1,y1);anjianok=0;	while(!anjianok){jisuandisplay();writedat_t() ;if(keyresult=='z')break;}break;
			}
		}			
			keyresult='n';
		  break; 
		          }//��һ�е����а�ť������


		case '4':xon=1;xdir=0;TR0=1;TR2=0;keyresult='n';break;//�ڶ��е�һ�а�ť������ x��
		case '5':yon=1;ydir=0;TR0=1;TR2=0;keyresult='n';break;//�ڶ��еڶ��а�ť������ y��
		case '6':zon=1;zdir=0;TR0=1;TR2=0;keyresult='n';break;//�ڶ��е����а�ť������ z��
		case 'y'://��������
			{
	anjianok=0;
		while(!anjianok){if(keyresult=='z')break;}//�ȴ���������
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
			keyresult='n';break;}//�ڶ��е����а�ť������
		case '1':xon=0;TR0=1;TR2=0;keyresult='n';break;//�����е�һ�а�ť������ xͣ
		case '2':	yon=0;TR0=1;TR2=0;keyresult='n';break; //�����еڶ��а�ť������ yͣ
	  case '3':zon=0;TR0=1;TR2=0;keyresult='n';break; //�����е����а�ť������ zͣ
		case 'z':TR0=1;TR2=0;xon=0;yon=0;zon=0;keyresult='n';break; //�����е����а�ť������ ȫͣ
	  case '0':TR0=1;TR2=0;kuaisu=1;keyresult='n';break;//�����е�һ�а�ť������ ����
	  case '.':TR0=1;TR2=0;kuaisu=0;keyresult='n';break;//�����еڶ��а�ť������ ����
		case 'a':TR0=1;TR2=0;inital();keyresult='n';break;//�����е����а�ť������  ��ԭ��
		case 'G':{	automotormain();keyresult='n';break;  }//�����е����а�ť������  �Զ�
	 }
 
 }
}
	