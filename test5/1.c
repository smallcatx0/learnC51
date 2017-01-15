/*
任务五
2017-1-13 22:23:23
	点亮你们的所有数码管
	显示从0000 0000到FFFF FFFF(大概一秒变换一次)
*/
#include<reg52.h>
#define uchar unsigned char 
#define uint unsigned int
uchar code shu[]={0x3f,0x06,0x5b,0x4f,0x66,
				  0x6d,0x7d,0x07,0x7f,0x6f
				  /*前面是0~9的断选码*//*,0x40:-*/,
				  0x77,0x7c,0x39,0x5e,0x79,0x71/*A-F*/
				  };
sbit W = P3^6;
sbit D = P3^7;
// 大概延时x ms的函数
void Delay_xms(uint x);
// 数码管显示函数
void Shuma_Display(uchar w,uchar d);
void main(){  
	int i;
    while(1){	
   		for(i=0;i<15;i++){	
	    	Shuma_Display(0x00,shu[i]);
			Delay_xms(1000);
		}    
   }

}

// 大概延时x ms的函数
void Delay_xms(uint x)
{
	uint j;
	uchar i;
	for (j=0;j<x;j++)
		for (i=0;i<110;i++);
}

void Shuma_Display(uchar w,uchar d){
	// 送位选
	P0 = w;
	W = 1;
	W = 0;
	// 送断选
	P0 = d;
	D = 1;
	D = 0;
}