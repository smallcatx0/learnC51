/*
任务六
2017-1-14 16:34:20
	用数码管显示你们的学号最后八位
*/
#include<reg52.h>
#define uchar unsigned char 
#define uint unsigned int
uchar code shu[]={0x3f,0x06,0x5b,0x4f,0x66,
				  0x6d,0x7d,0x07,0x7f,0x6f,
				  /*前面是0~9的断选码*/
				  0x77,0x7c,0x39,0x5e,0x79,0x71,/*A-F*/
				  0x40/*:-*/
				  };
uchar code wei[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
sbit W = P3^6;
sbit D = P3^7;
// 大概延时x ms的函数
void Delay_xms(uint x);
// 数码管显示函数
void Shuma_Display(uchar w,uchar d);
void main(){  
    while(1){	
    	Shuma_Display(wei[7],shu[0]);
		Shuma_Display(wei[6],shu[1]);
		Shuma_Display(wei[5],shu[2]);
		Shuma_Display(wei[4],shu[0]);
		Shuma_Display(wei[3],shu[2]);
		Shuma_Display(wei[2],shu[0]);
		Shuma_Display(wei[1],shu[9]);
		Shuma_Display(wei[0],shu[0]);
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
	uchar i=0;
	// 送位选
	P0 = w;
	W = 1;
	W = 0;
	// 送断选
	P0 = d;
	D = 1;
	D = 0;
	for(;i<250;i++);

}