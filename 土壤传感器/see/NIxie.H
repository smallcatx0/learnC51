/*
	数码管显示头文件
	数码管段选P3^6 位选P3^7 数据口 N_IO
	此文件包含数码管 段选(shu[]) 位选(wei[])码
	带小数点的段选码为(shu[]|0x80)
	数码管显示函数：Shuma_Display(wei[],shu[]);
	2017-1-14 17:47:49
*/

#ifndef NIxie
#define NIxie
#ifndef uchar
#define uchar unsigned char
#endif
#ifndef uint 
#define uint unsigned int
#endif
/*------------ 数码管参数设置 ------------------*/
#define N_IO P1
sbit D = P2^7;
sbit W = P2^6; 
uchar code shu[]={0x3f,0x06,0x5b,0x4f,0x66,
				  0x6d,0x7d,0x07,0x7f,0x6f,
				  /*前面是0~9的断选码*/
				  0x77,0x7c,0x39,0x5e,0x79,0x71,/*A-F*/
				  0x40,/*-*/};
uchar code wei[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
//--------数码管显示函数-------	 
void Shuma_Display(uchar w,uchar d){
	uchar i;
	// 送位选
	N_IO = w;
	W = 1;
	W = 0;
	// 送断选
	N_IO = d;
	D = 1;
	D = 0;
	for(i=0;i<250;i++);

}
#endif
