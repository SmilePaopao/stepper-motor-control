#include"moto.h"
int time=0;
signed long  idata xdat_t=0;
signed long  idata ydat_t=0;
signed long  idata zdat_t=0;
bit xon=0;
bit yon=0;
bit zon=0;
bit kuaisu=0;



void motorinitial()
{

 TMOD=TMOD|0x01;/*定时器0方式2*/
 TH0=0xfc;//0.1ms
 TL0=0x00;
 ET0=1; /*开定时器0中断*/
 TR0=0; /*启动定时器0*/
	
}

void inital()//将工作台移动到自动化的初始位置
{
	xon=yon=zon=1;
	 xdir=ydir=zdir=0;
		 
   
}


		
void motor() interrupt 1 using 1   
{   	
	  if(kuaisu)
		{TL0+=0x90;
	TH0=0xfe;}//0.4ms}
		else{TL0+=0x66;
	TH0=0xfc;//1ms
		}

	  		 if((!xleft)^(!xright)){xon=0;}//软件和硬件超限保护
		
	   if((!yleft)^(!yright)){yon=0;}

		 if((!zleft)^(!zright)){zon=0;}


 
	     if(xon)
         {xspeed=1;
          if(xdir){++xdat_t;
						   if(xdat_t>=60000){xon=0;}
							}
	        else{--xdat_t;
					   if(xdat_t<=0){xon=0;}
					     }
          }
			 if(yon)
         {yspeed=1;
				 if(ydir){++ydat_t;
				         if(ydat_t>=60000){yon=0;}
				          }
					 
	       else{--ydat_t;
				     if(ydat_t<=0){yon=0;} }
				 }
			 if(zon)
         {zspeed=1;
				 if(zdir){++zdat_t;
					  if(zdat_t>30000){zon=0;}
					       }
	       else{--zdat_t;
				     if(zdat_t<=0){zon=0;}
				      }
				 }			 
xspeed=0;yspeed=0;zspeed=0;
 } 
