/*
任务七
2017-1-14 16:34:20
	用数码管显示LOVE YOU
*/
#include<reg52.h>
#define uchar unsigned char 
#define uint unsigned int
uchar code wei[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
sbit W = P3^6;
sbit D = P3^7;
// 大概延时
void Delay_xms(uint x);
// 数码管显示函数
void Shuma_Display(uchar w,uchar d);
void main(){  
    while(1){	
    	Shuma_Display(wei[7],0x3e); // U
		Shuma_Display(wei[6],0xbf); // O
		Shuma_Display(wei[5],0x6f); // Y
		Shuma_Display(wei[3],0x79); // E
		Shuma_Display(wei[2],0x3e); // V
		Shuma_Display(wei[1],0x3f); // O
		Shuma_Display(wei[0],0x38); // L
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