/*-------LCD1602显示器操作库---------
	此头文件包含：
	  延时大约Xms的函数 : void Delay_xms(uint x)
	  1602写命令函数    : void Write_com(uchar com)
	  1602数据函数      : void Write_data(uchar dat)
	  1602初始化函数    : void _1602init()
*/
#ifndef	LDC1602
#define LDC1602
#ifndef uint
#define uint unsigned int
#endif
#ifndef uchar
#define uchar unsigned char
#endif
/*---- 1602参数设置------*/
#define LCD1602_IO P0	
sbit RS=P2^1;
sbit RW=P2^2;
sbit EN=P2^3;
//----延时大约Xms的函数----- 
void Delay_xms(uint x){
	uchar i;
	uint j;
	for(j=0;j<x;j++)
		for (i=0;i<110;i++);
}	
//-------1602写命令函数---------
void Write_com(uchar com){
	RS=0;
	RW=0;
	LCD1602_IO=com;
	Delay_xms(5);
	EN=1;
	Delay_xms(5);
	EN=0;	
}
//-------1602数据函数---------
void Write_data(uchar dat){
	RS=1;
	RW=0;
	LCD1602_IO=dat;
	Delay_xms(1);
	EN=1;
	Delay_xms(1);
	EN=0;
		
}
//--------1602初始化函数------
void _1602init(){
	EN=0;				 //使能初始化
	Write_com(0x83);	 //设置显示模式
	Write_com(0x01);	 //清屏
	Write_com(0x0c);     //开显示设置光标，不显示光标
	Write_com(0x06);     //设置指针，读写一个字符后地址指针加一
}
#endif