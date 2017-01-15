/*
任务四
2017-1-13 19:55:36
	点亮你们的第一个数码管 
	显示你们的学号最后一位
*/
#include<reg52.h>
#define uchar unsigned char 
#define uint unsigned int
uchar code shu[]={0x3f,0x06,0x5b,0x4f,0x66,
				  0x6d,0x7d,0x07,0x7f,0x6f
				  /*前面是0~9的断选码*/,0x40/*-*/,};
sbit W = P3^6;
sbit D = P3^7;
// 大概延时x ms的函数
void Delay_xms(uint x);
// 数码管显示函数
void Shuma_Display(uchar w,uchar d);
void main(){  
    while(1){		
		// 送位选
		P0 = 0xfe; // 1111 1110
		// 先把数据送到锁存器D口（输入口）
		// 再打开锁存器 
		W = 1;
		W = 0;
		// 送断选
		P0 = shu[0];
		D = 1;
		D = 0;
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