#include"jianpan.h"
unsigned char temp,key;
bit anjianok;
unsigned char idata keyresult;
void delay(unsigned int i)            //��ʱ�������ڼ��̷���
{
   unsigned int j;
   for(;i>0;i--)
       for(j=0;j<100;j++);
}
void jianpaninitial()                 //���̳����ʼ��
{
	EX0=1;                              //�����ⲿ�ж�0
	IT0=1;                              //���ش����ж�
	PA8155=0xf0;                        //���ź�����
}
void jianpanmain() interrupt 0        //�����ⲿ�ж��ӳ���
{
   
	  delay(1);
		if(!interrupt0)
		{   
			PA8155=0xfe;
			delay(1);
			key=PC8155&0x0f;//��һ��
			if((key&0x01)==0){keyresult='7';}//��һ�е�һ�а�ť������ x��
		  if((key&0x02)==0){keyresult='8';}//��һ�еڶ��а�ť������ y��
			if((key&0x04)==0){keyresult='9';}//��һ�е����а�ť������ z��
			if((key&0x08)==0){keyresult='x';}//��һ�е����а�ť������ xy����ֱ̨��
				
			PA8155=0xfd;
			delay(1);
			key=PC8155&0x0f;//�ڶ���
			if((key&0x01)==0){keyresult='4';}//�ڶ��е�һ�а�ť������ x��
		  if((key&0x02)==0){keyresult='5';}//�ڶ��еڶ��а�ť������ y��
			if((key&0x04)==0){keyresult='6';}//�ڶ��е����а�ť������ z��
			if((key&0x08)==0){keyresult='y';}//�ڶ��е����а�ť������ 
				
			PA8155=0xfb;
			delay(1);
			key=PC8155&0x0f;//������
			if((key&0x01)==0){keyresult='1';}//�����е�һ�а�ť������ xͣ
		  if((key&0x02)==0){keyresult='2';}//�����еڶ��а�ť������ yͣ
			if((key&0x04)==0){keyresult='3';}//�����е����а�ť������ zͣ
			if((key&0x08)==0){keyresult='z';}//�����е����а�ť������ ȫͣ
				
			PA8155=0xf7;
			delay(1);
			key=PC8155&0x0f;//������
			if((key&0x01)==0){keyresult='0';}//�����е�һ�а�ť������ ����
  		if((key&0x02)==0){keyresult='.';}//�����еڶ��а�ť������ ����
			if((key&0x04)==0){keyresult='a';}//�����е����а�ť������ ��ԭ��
			if((key&0x08)==0){keyresult='G';}//�����е����а�ť������ �Զ�
		anjianok=1;
		}
	  PA8155=0xf0;
} 
