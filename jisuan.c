


#include"jisuan.h"




char sx[8];
char   sy[8];
char  sz[8];


float   xfloat;
float  yfloat;
float  zfloat;


void jisuandisplay()
{
xfloat=xdat_t;
	xfloat=xfloat/200;
	itostr(sx, xfloat);   
yfloat=ydat_t;
	yfloat=yfloat/200;
	itostr(sy, yfloat);   
zfloat=zdat_t;
	zfloat=zfloat/200;
	itostr(sz, zfloat);
}
char* itostr(char *str, float p) //浮点数转换为字符串
{
    sprintf(str, "%f", p);
    return str;
}
