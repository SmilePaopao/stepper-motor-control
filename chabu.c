#include"chabu.h"


signed long  totalsteps;
signed long  F_xy,F_xz,x,y;
signed long  x0;
signed long  y0;
signed long  z0;//�յ�����
signed long  x1;
signed long  y1;
unsigned char  Gchoose;
unsigned char  zxchoose;
void chabuinitial()
{

	RCAP2H=0xfc;
	RCAP2L=0x66;//1msһ���ж�
	ET2=1;
	TR2=0;
	

}
void automotormain()//300*300���Զ�ϳ��,xy�ӣ�0��0����ʼ,z��5mm��10mm��ÿ1mmϳһ�� zdat_t��1000��2000
{
 G00(2000,8000,0);
	
	G02(2000,2000,2000,0);
	G03(2000,2000,0,2000);
	G02(2000,2000,2000,0);
	G01(2000,0,0);
	
	G02(2000,-2000,0,-2000);
	G03(2000,-2000,2000,0);	
	G02(2000,-2000,0,-2000);
	G01(0,-2000,0);
	
	G02(-2000,-2000,-2000,0);
  G03(-2000,-2000,0,-2000);
  G02(-2000,-2000,-2000,0);
	G01(-2000,0,0);
	
	G02(-2000,2000,0,2000);
	G03(-2000,2000,-2000,0);
	G02(-2000,2000,0,2000);
	G01(0,2000,0);
 }
		




void G00(long x,long y,long z)
{

TR0=0;TR2=0; RCAP2H=0xfe;
	RCAP2L=0x0c;
	x0=x;y0=y;z0=z;
		          F_xy=F_xz=0;//ֱ�ߵ��ж�ʽ����ʼΪ0
		          totalsteps=labs(x0)+labs(y0)+labs(z0);//��ֱ��Ҫ�ߵĲ���
		          zxxxchoose();Gchoose=1;
			       TR2=1;
			         while(!(totalsteps==0)){jisuandisplay();writedat_t() ;
							                          if(keyresult=='z')break; }
							 delay(10);


}

void G01(long x,long y,long z)//ֱ��   // Բ����ֱ�ߵ��յ����ֱ꣬��������ռ�㣬Բ��ֻ��ƽ���
		         
{
TR0=0; TR2=0;RCAP2H=0xfc;
	RCAP2L=0x66;
	x0=x;y0=y;z0=z;
			     F_xy=F_xz=0;//ֱ�ߵ��ж�ʽ����ʼΪ0
		          totalsteps=labs(x0)+labs(y0)+labs(z0);//��ֱ��Ҫ�ߵĲ���
		          zxxxchoose();Gchoose=1;
			        TR2=1;
			         while(totalsteps!=0){jisuandisplay();writedat_t() ;
							                          if(keyresult=='z')break; }
 delay(10);


}
	void G02(long x00,long y00,long x01,long y01)//˳Բ  //Բ����Բ��//Բ����ֱ�ߵ��յ����ֱ꣬��������ռ�㣬Բ��ֻ��ƽ���
	
	{
TR0=0;TR2=0;RCAP2H=0xfb;
	RCAP2L=0x00;
		x0=x00;y0=y00;x1=x01;y1=y01;
		         F_xy=0;
		          
		          x=-x1;y=-y1;//Բ����Բ��Ϊԭ�����õ���ʼ����
		      x1=x0-x1;y1=y0-y1;
		
		
		          Gchoose=2;
			        TR2=1;
			      while(!((x==x1)&(y==y1))){jisuandisplay();writedat_t() ;
							                          if(keyresult=='z')break; }
         delay(10);




}

	
	
	
		
	
	
		void G03(long x00,long y00,long x01,long y01)//��ʱ��Բ
{
TR0=0;TR2=0;RCAP2H=0xfb;
	RCAP2L=0x00;
			      x0=x00;y0=y00;x1=x01;y1=y01;
		         F_xy=0;
		          
		          x=-x1;y=-y1;//Բ����Բ��Ϊԭ�����õ���ʼ����
		      x1=x0-x1;y1=y0-y1;
		
		
		          Gchoose=3;
			        TR2=1;
while(!((x==x1)&(y==y1))){jisuandisplay();writedat_t() ;
							                          if(keyresult=='z')break; }
        
 delay(10);

}
















signed long labs(signed long z)
{if(z>0){return z;}
else{return -z;}
}
void zxxxchoose()
{
if(z0==0)zxchoose=0;	//��xyƽ���ڶ�
else if((x0==0)&(y0==0)&(z0!=0))zxchoose=1;	//��z�ᶯ

else if((x0>0)&(y0>=0)&(z0>0))zxchoose=11;//xy��һ����xz��һ����
else if((x0>0)&(y0>=0)&(z0<0))zxchoose=14;//xy��һ����xz��������
else if((x0<0)&(y0>0)&(z0>0))zxchoose=22;//xy�ڶ�����xz�ڶ�����
else if((x0<0)&(y0>0)&(z0<0))zxchoose=23;//xy�ڶ�����xz��������
else if((x0<0)&(y0<=0)&(z0>0))zxchoose=32;//xy��������xz�ڶ�����
else if((x0<0)&(y0<=0)&(z0<0))zxchoose=33;//xy��������xz��������
else if((x0>0)&(y0<0)&(z0>0))zxchoose=41;//xy��������xz��һ����
else if((x0>0)&(y0<0)&(z0<0))zxchoose=44;	//xy��������xz��������	
	else zxchoose=2;//yzƽ��
}
void chabuchoose() interrupt 5
{
	
	TF2=0;
switch(Gchoose) 
{
		
	case(1): linechabumain();break;
	case(2): scirclechabumain();break;
	case(3): ncirclechabumain();break;

}
}
void chabumotor() //���庯��
{int i;
	 if((!xleft)^(!xright)){xon=0;}//�����Ӳ�����ޱ���
		
	   if((!yleft)^(!yright)){yon=0;}

		 if((!zleft)^(!zright)){zon=0;}
	   if(xon)
         {xspeed=1;
          if(xdir){++xdat_t;
						   
							}
	        else{--xdat_t;
					   
					     }
          }
			 if(yon)
         {yspeed=1;
				 if(ydir){++ydat_t;
				         
				          }
					 
	       else{--ydat_t;
				      }
				 }
				 if(zon)
         {zspeed=1;
          if(zdir){++zdat_t;
						   
							}
	        else{--zdat_t;
					   
					     }
          }
			
				 for(i=0;i<5;i++){;}
			 xspeed=0;yspeed=0;zspeed=0;

		
 } 
	 











void linechabumain() //ֱ�߲岹
	{

	
	//if((x0>0)&(y0>=0)&(z0>0))	//xy��һ����xz��һ����
switch(zxchoose)
{
	case 11:{
		  if(totalsteps!=0)
		   {
        if((F_xy>=0)&(F_xz>=0)){xon=1;yon=0;zon=0;xdir=1;chabumotor(); F_xy=F_xy-y0;F_xz=F_xz-z0;}//��x
        else if((F_xy<0)&(F_xz>=0)){yon=1;xon=0;zon=0;ydir=1;chabumotor(); F_xy=F_xy+x0;}
				else if((F_xy>=0)&(F_xz<0)){zon=1;xon=0;yon=0;zdir=1;chabumotor(); F_xz=F_xz+x0;}
        else{if(F_xy<F_xz){yon=1;xon=0;zon=0;ydir=1;chabumotor(); F_xy=F_xy+x0;}
				     else{ zon=1;xon=0;yon=0;zdir=1;chabumotor(); F_xz=F_xz+x0;}
				    }
	    	totalsteps--;
			 }
     else{xon=0;yon=0;zon=0;}
		 break;
	   }
		
		//else	if((x0>0)&(y0>=0)&(z0<0))	//xy��һ����xz��������
	case 14:{
		  if(totalsteps!=0)
		   {
        if((F_xy>=0)&(F_xz>0)){xon=1;yon=0;zon=0;xdir=1;chabumotor(); F_xy=F_xy-y0;F_xz=F_xz+z0;}
        else if((F_xy<0)&(F_xz>0)){yon=1;xon=0;zon=0;ydir=1;chabumotor(); F_xy=F_xy+x0;}
				else if((F_xy>=0)&(F_xz<=0)){zon=1;xon=0;yon=0;zdir=0;chabumotor(); F_xz=F_xz+x0;}
        else{if(F_xy<F_xz){yon=1;xon=0;zon=0;ydir=1;chabumotor(); F_xy=F_xy+x0;}
				     else{ zon=1;xon=0;yon=0;zdir=0;chabumotor(); F_xz=F_xz+x0;}
				    }
	    	totalsteps--;
			 }
     else{xon=0;yon=0;zon=0;}
		 break;
	   }

		//else if((x0<0)&(y0>0)&(z0>0))	//xy�ڶ�����xz�ڶ�����
		case 22:{
			if(totalsteps!=0)
		   {if((F_xy>0)&(F_xz>0)){xon=1;yon=0;zon=0;xdir=0;chabumotor(); F_xy=F_xy-y0; F_xz=F_xz-z0;}
        else if((F_xy<=0)&(F_xz>0)){ yon=1;xon=0;zon=0;ydir=1;chabumotor() ;F_xy=F_xy-x0;}
        else if((F_xy>0)&(F_xz<=0)){ zon=1;xon=0;yon=0;zdir=1;chabumotor() ;F_xz=F_xz-x0;}
        else if(F_xy<=F_xz) {yon=1;xon=0;zon=0;ydir=1;chabumotor() ;F_xy=F_xy-x0;}
	    	     else{zon=1;xon=0;yon=0;zdir=1;chabumotor() ;F_xz=F_xz-x0;}
				totalsteps--;
		    }
			 else{xon=0;yon=0;zon=0;}
			 break;
		}
	
		 //else if((x0<0)&(y0>0)&(z0<0))	//xy�ڶ�����xz��������
		case 23:
		{
			if(totalsteps!=0)
		   {if((F_xy>0)&(F_xz>=0)){xon=1;yon=0;zon=0;xdir=0;chabumotor(); F_xy=F_xy-y0; F_xz=F_xz+z0;}
        else if((F_xy<=0)&(F_xz>=0)){ yon=1;xon=0;zon=0;ydir=1;chabumotor() ;F_xy=F_xy-x0;}
        else if((F_xy>0)&(F_xz<0)){ zon=1;xon=0;yon=0;zdir=0;chabumotor() ;F_xz=F_xz-x0;}
        else if(F_xy<=F_xz) {yon=1;xon=0;zon=0;ydir=1;chabumotor() ;F_xy=F_xy-x0;}
	    	     else{zon=1;xon=0;yon=0;zdir=0;chabumotor() ;F_xz=F_xz-x0;}
				totalsteps--;
		    }
			 else{xon=0;yon=0;zon=0;}
			 break;
		}
		 
	//else if((x0<0)&(y0<=0)&(z0>0))	//xy��������xz�ڶ�����
		case 32:{
			if(totalsteps!=0)
		   {if((F_xy>=0)&(F_xz>0)){xon=1;yon=0;zon=0;xdir=0;chabumotor(); F_xy=F_xy+y0; F_xz=F_xz-z0;}
        else if((F_xy<0)&(F_xz>0)){ yon=1;xon=0;zon=0;ydir=0;chabumotor() ;F_xy=F_xy-x0;}
        else if((F_xy>=0)&(F_xz<=0)){ zon=1;xon=0;yon=0;zdir=1;chabumotor() ;F_xz=F_xz-x0;}
        else if(F_xy<F_xz) {yon=1;xon=0;zon=0;ydir=0;chabumotor() ;F_xy=F_xy-x0;}
	    	     else{zon=1;xon=0;yon=0;zdir=1;chabumotor() ;F_xz=F_xz-x0;}
				totalsteps--;
		    }
			 else{xon=0;yon=0;zon=0;}
			 break;
		}
		 
 //else if((x0<0)&(y0<=0)&(z0<0))	//xy��������xz��������
		case 33:
		{
			if(totalsteps!=0)
		   {if((F_xy>=0)&(F_xz>=0)){xon=1;yon=0;zon=0;xdir=0;chabumotor(); F_xy=F_xy+y0; F_xz=F_xz+z0;}
        else if((F_xy<0)&(F_xz>=0)){ yon=1;xon=0;zon=0;ydir=0;chabumotor() ;F_xy=F_xy-x0;}
        else if((F_xy>=0)&(F_xz<0)){ zon=1;xon=0;yon=0;zdir=0;chabumotor() ;F_xz=F_xz-x0;}
        else if(F_xy<F_xz) {yon=1;xon=0;zon=0;ydir=0;chabumotor() ;F_xy=F_xy-x0;}
	    	     else{zon=1;xon=0;yon=0;zdir=0;chabumotor() ;F_xz=F_xz-x0;}
				totalsteps--;
		    }
			 else{xon=0;yon=0;zon=0;}
			 break;
		}

	//else	if((x0>0)&(y0<0)&(z0>0))	//xy��������xz��һ����
		case 41:{
			if(totalsteps!=0)
		   {if((F_xy>0)&(F_xz>=0)){xon=1;yon=0;zon=0;xdir=1;chabumotor(); F_xy=F_xy+y0; F_xz=F_xz-z0;}
        else if((F_xy<=0)&(F_xz>=0)){ yon=1;xon=0;zon=0;ydir=0;chabumotor() ;F_xy=F_xy+x0;}
        else if((F_xy>0)&(F_xz<0)){ zon=1;xon=0;yon=0;zdir=1;chabumotor() ;F_xz=F_xz+x0;}
        else if(F_xy<=F_xz) {yon=1;xon=0;zon=0;ydir=0;chabumotor() ;F_xy=F_xy+x0;}
	    	     else{zon=1;xon=0;yon=0;zdir=1;chabumotor() ;F_xz=F_xz+x0;}
				totalsteps--;
		    }
			 else{xon=0;yon=0;zon=0;}
			 break;
		}
	
//else			if((x0>0)&(y0<0)&(z0<0))	//xy��������xz��������
		case 44:
		{
			if(totalsteps!=0)
		   {if((F_xy>0)&(F_xz>0)){xon=1;yon=0;zon=0;xdir=1;chabumotor(); F_xy=F_xy+y0; F_xz=F_xz+z0;}
        else if((F_xy<=0)&(F_xz>0)){ yon=1;xon=0;zon=0;ydir=0;chabumotor() ;F_xy=F_xy+x0;}
        else if((F_xy>0)&(F_xz<=0)){ zon=1;xon=0;yon=0;zdir=0;chabumotor() ;F_xz=F_xz+x0;}
        else if(F_xy<=F_xz) {yon=1;xon=0;zon=0;ydir=0;chabumotor() ;F_xy=F_xy+x0;}
	    	     else{zon=1;xon=0;yon=0;zdir=0;chabumotor() ;F_xz=F_xz+x0;}
				totalsteps--;
		    }
			 else{xon=0;yon=0;zon=0;}
			 break;
		  }
	


		//else	if(z0==0)//��ƽ���ڶ�
		case 0:
    {
if((x0>0)&(y0>=0))
    {
			if(totalsteps!=0)
		   {if(F_xy>=0){xon=1;yon=0;xdir=1;chabumotor(); F_xy=F_xy-y0;}
        else{ yon=1;xon=0;ydir=1;chabumotor() ;F_xy=F_xy+x0;}
	    	totalsteps--;
		    }
			 else{xon=0;yon=0;}
		}	
if((x0<=0)&(y0>0))//
    {
			if(totalsteps!=0)
		   {if(F_xy>0){xon=1;yon=0;xdir=0;chabumotor(); F_xy=F_xy-y0;}
        else{ yon=1;xon=0;ydir=1;chabumotor() ;F_xy=F_xy-x0;}
	    	totalsteps--;
		    }
			 else{xon=0;yon=0;}
		}	
	if((x0<0)&(y0<=0))//
    {
			if(totalsteps!=0)
		   {if(F_xy>=0){xon=1;yon=0;xdir=0;chabumotor(); F_xy=F_xy+y0;}
        else{ yon=1;xon=0;ydir=0;chabumotor() ;F_xy=F_xy-x0;}
	    	totalsteps--;
		    }
			 else{xon=0;yon=0;}
		}	
	if((x0>=0)&(y0<0))	//
    {
			if(totalsteps!=0)
		   {if(F_xy>0){xon=1;yon=0;xdir=1;chabumotor(); F_xy=F_xy+y0;}
        else{ yon=1;xon=0;ydir=0;chabumotor(); F_xy=F_xy+x0;}
	    	totalsteps--;
		    }
			 else{xon=0;yon=0;}
			 
		}
break;
    }
	
	//else if((x0==0)&(y0==0)&(z0!=0))//��z�ᶯ		else	if(z0==0)//��ƽ���ڶ�
case 1:
	{
	if(totalsteps!=0)
	      {if(z0>0){zon=1;xon=0;yon=0;zdir=1;chabumotor();}
		     else{zon=1;xon=0;yon=0;zdir=0;chabumotor();}
				 totalsteps--;
			 }
				else{zon=0;}
	
	
	break;
	}
			//else	if(z0==0)//��ƽ���ڶ�
		case 2:
    {
if((z0>0)&(y0>0))//zyƽ�� ��С����������Fxy����Fzy
    {
			if(totalsteps!=0)
		   {if(F_xy>=0){zon=1;yon=0;zdir=1;chabumotor(); F_xy=F_xy-y0;}
        else{ yon=1;zon=0;ydir=1;chabumotor() ;F_xy=F_xy+z0;}
	    	totalsteps--;
		    }
			 else{zon=0;yon=0;}
		}	
if((z0<0)&(y0>0))//
    {
			if(totalsteps!=0)
		   {if(F_xy>0){zon=1;yon=0;zdir=0;chabumotor(); F_xy=F_xy-y0;}
        else{ yon=1;zon=0;ydir=1;chabumotor() ;F_xy=F_xy-z0;}
	    	totalsteps--;
		    }
			 else{zon=0;yon=0;}
		}	
	if((z0<0)&(y0<0))//
    {
			if(totalsteps!=0)
		   {if(F_xy>=0){zon=1;yon=0;zdir=0;chabumotor(); F_xy=F_xy+y0;}
        else{ yon=1;zon=0;ydir=0;chabumotor() ;F_xy=F_xy-z0;}
	    	totalsteps--;
		    }
			 else{zon=0;yon=0;}
		}	
	if((z0>0)&(y0<0))	//
    {
			if(totalsteps!=0)
		   {if(F_xy>0){zon=1;yon=0;zdir=1;chabumotor(); F_xy=F_xy+y0;}
        else{ yon=1;zon=0;ydir=0;chabumotor(); F_xy=F_xy+z0;}
	    	totalsteps--;
		    }
			 else{zon=0;yon=0;}
			 
		}
break;
    }
	
	
	
	
	}	
}
	
	
		
 
 
 
 void ncirclechabumain() //��Բinterrupt 5 
	 {
		 
	 if((x>=0)&(y<0))//��������
		{
		  
		   if(F_xy>=0){if(y==y1) {yon=0;}
			             else {xon=0;yon=1;ydir=1;chabumotor(); F_xy=F_xy-2*labs(y)+1;y++;}
			            }
        else{ if(x==x1) {xon=0;}
				      else{yon=0;xon=1;xdir=1;chabumotor(); F_xy=F_xy+2*labs(x)+1;x++;}
				    }    
			
	   }
	if((x>0)&(y>=0))	//��һ����
		{
		
		   if(F_xy>0){if(x==x1) {xon=0;}
			           else{xon=1;yon=0;xdir=0;chabumotor(); F_xy=F_xy-2*labs(x)+1;x--;}
							   }
        else{ if(y==y1) {yon=0;}
				       else{yon=1;xon=0;ydir=1;chabumotor();F_xy=F_xy+2*labs(y)+1;y++;}
						 }
	
		
		}
	if((x<=0)&(y>0))//�ڶ�����
    {
		
		   if(F_xy>=0){if(y==y1) {yon=0;}
			             else{xon=0;yon=1;ydir=0;chabumotor(); F_xy=F_xy-2*labs(y)+1;y--;}
								 }
        else{ if(x==x1) {xon=0;}
				      else{ yon=0;xon=1;xdir=0;chabumotor() ;F_xy=F_xy+2*labs(x)+1;x--;}
						}
	    	
		    
			
		}	
	if((x<0)&(y<=0))	//��������
    {
		
		   if(F_xy>0){if(x==x1) {xon=0;}
			           else{xon=1;yon=0;xdir=1;chabumotor(); F_xy=F_xy-2*labs(x)+1;x++;}
					      	}
        else{ if(y==y1) {yon=0;}
				      else{yon=1;xon=0;ydir=0;chabumotor(); F_xy=F_xy+2*labs(y)+1;y--;}
							 }
	 
	 }
 }
	 
 
 
 
	 void scirclechabumain() //˳Բ
	 {
		 
	
		 
	 if((x<0)&(y>=0))	//�ڶ�����
		{
		   if(F_xy>=0){if(x==x1) {xon=0;}
			             else{xon=1;yon=0;xdir=1;chabumotor(); F_xy=F_xy-2*labs(x)+1;x++;}
								 }
        else{if(y==y1) {yon=0;} 
				           else{yon=1;xon=0;ydir=1;chabumotor(); F_xy=F_xy+2*labs(y)+1;y++;}
								 }
		    
	   }
	if((x<=0)&(y<0))	//��������
		{
		   if(F_xy>0){if(y==y1) {yon=0;}
			             else{xon=0;yon=1;ydir=1;chabumotor(); F_xy=F_xy+2*y+1;y++;}
								 }
        else{ if(x==x1) {xon=0;}
				             else{yon=0;xon=1;xdir=0;chabumotor();F_xy=F_xy-2*x+1;x--;}
									 }
		    
		}
	if((x>0)&(y<=0))//��������
    {
		   if(F_xy>=0){if(x==x1) {xon=0;}
			            else{ xon=1;yon=0;xdir=0;chabumotor(); F_xy=F_xy-2*labs(x)+1;x--;}
								}
        else{if(y==y1) {yon=0;}
				             else{yon=1;xon=0;ydir=0;chabumotor() ;F_xy=F_xy+2*labs(y)+1;y--;}
									 }
		    
		}	
	if((x>=0)&(y>0))	//��һ����
    {
		   if(F_xy>0){if(y==y1) {yon=0;}
			           else{ xon=0;yon=1;ydir=0;chabumotor(); F_xy=F_xy-2*labs(y)+1;y--;}
							 }
        else{ if(x==x1) {xon=0;}
			           else{	yon=0;xon=1;xdir=1;chabumotor(); F_xy=F_xy+2*labs(x)+1;x++;}
							 }
	 
	 }
		
 }
