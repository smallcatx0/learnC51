/*
任务八
2017-1-15 15:05:40
	用单片机的定时器和数码管
	做一个倒计时（精确到100毫秒）
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
uchar t_50ms = 0;
sbit W = P3^6;
sbit D = P3^7;
// 大概延时x ms的函数
void Delay_xms(uint x);
// 数码管显示函数
void Shuma_Display(uchar w,uchar d);

void main ()
{
	uint time = 100;
	TMOD=0X01;			    // 设置定时器0为工作方式1
	TH0=(65536-45872)/256;	// 装初值45872 在11.0592MHz下为50ms
	TL0=(65536-45872)%256;
	EA=1;					//开总中断
	ET0=1;					//开定时器0中断
	TR0=1;				    //计数器开始工作
	W=0;
	D=0;	 

	while(1){	 				 
		Shuma_Display(wei[7],shu[time%10]);
		Shuma_Display(wei[6],shu[time/10]+0x80);//+0x80数字就带上了小数点
		if(t_50ms>=2){
			t_50ms = 0;
			time --;
			if(time<=0){
			    TR0 = 0;
			}
		}
	}
}
void T0_50ms() interrupt 1
{	
	TH0=(65536-45872)/256;
	TL0=(65536-45872)%256;
	t_50ms++;
}
// 大概延时x ms的函数
void Delay_xms(uint x)
{
	uint j;
	uchar i;
	for (j=0;j<x;j++)
		for (i=0;i<110;i++);
}
// 数码管显示函数
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