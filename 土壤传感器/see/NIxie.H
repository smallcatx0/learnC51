/*
	数码管显示头文件
	数码管段选P3^6 位选P3^7 数据P0口
	此文件包含数码管 段选(shu[]) 位选(wei[])码
	带小数点的段选码为(shu[]|0x80)
	数码管显示函数：Shuma_Display(wei[],shu[]);
	2017-1-14 17:47:49
*/

#ifndef NIxie
#define NIxie
sbit D = P3^7;
sbit W = P3^6; 
#define uchar unsigned char 
#define uint unsigned int
uchar code shu[]={0x3f,0x06,0x5b,0x4f,0x66,
				  0x6d,0x7d,0x07,0x7f,0x6f
				  /*前面是0~9的断选码*/,0x40/*-*/,};
uchar code wei[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
//--------数码管显示函数-------	 
void Shuma_Display(uchar a,uchar b){
	uchar i=0;
	// 送位选
	P0 = a;
	W = 1;
	W = 0;
	// 送断选
	P0 = b;
	D = 1;
	D = 0;
	for(;i<250;i++);
}
#endif
