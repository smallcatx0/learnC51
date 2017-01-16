/*-------LCD1602��ʾ��������---------
	��ͷ�ļ�������
	  ��ʱ��ԼXms�ĺ��� : void Delay_xms(uint x)
	  1602д�����    : void Write_com(uchar com)
	  1602���ݺ���      : void Write_data(uchar dat)
	  1602��ʼ������    : void _1602init()
*/
#ifndef	LDC1602
#define LDC1602
#ifndef uint
#define uint unsigned int
#endif
#ifndef uchar
#define uchar unsigned char
#endif
/*---- 1602��������------*/
#define LCD1602_IO P0	
sbit RS=P2^1;
sbit RW=P2^2;
sbit EN=P2^3;
//----��ʱ��ԼXms�ĺ���----- 
void Delay_xms(uint x){
	uchar i;
	uint j;
	for(j=0;j<x;j++)
		for (i=0;i<110;i++);
}	
//-------1602д�����---------
void Write_com(uchar com){
	RS=0;
	RW=0;
	LCD1602_IO=com;
	Delay_xms(5);
	EN=1;
	Delay_xms(5);
	EN=0;	
}
//-------1602���ݺ���---------
void Write_data(uchar dat){
	RS=1;
	RW=0;
	LCD1602_IO=dat;
	Delay_xms(1);
	EN=1;
	Delay_xms(1);
	EN=0;
		
}
//--------1602��ʼ������------
void _1602init(){
	EN=0;				 //ʹ�ܳ�ʼ��
	Write_com(0x83);	 //������ʾģʽ
	Write_com(0x01);	 //����
	Write_com(0x0c);     //����ʾ���ù�꣬����ʾ���
	Write_com(0x06);     //����ָ�룬��дһ���ַ����ַָ���һ
}
#endif