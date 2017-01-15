/*
�����
2017-1-15 15:05:40
	�õ�Ƭ���Ķ�ʱ���������
	��һ������ʱ����ȷ��100���룩
*/
#include<reg52.h>
#define uchar unsigned char 
#define uint unsigned int
uchar code shu[]={0x3f,0x06,0x5b,0x4f,0x66,
				  0x6d,0x7d,0x07,0x7f,0x6f,
				  /*ǰ����0~9�Ķ�ѡ��*/
				  0x77,0x7c,0x39,0x5e,0x79,0x71,/*A-F*/
				  0x40/*:-*/
				  };
uchar code wei[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
uchar t_50ms = 0;
sbit W = P3^6;
sbit D = P3^7;
// �����ʱx ms�ĺ���
void Delay_xms(uint x);
// �������ʾ����
void Shuma_Display(uchar w,uchar d);

void main ()
{
	uint time = 100;
	TMOD=0X01;			    // ���ö�ʱ��0Ϊ������ʽ1
	TH0=(65536-45872)/256;	// װ��ֵ45872 ��11.0592MHz��Ϊ50ms
	TL0=(65536-45872)%256;
	EA=1;					//�����ж�
	ET0=1;					//����ʱ��0�ж�
	TR0=1;				    //��������ʼ����
	W=0;
	D=0;	 

	while(1){	 				 
		Shuma_Display(wei[7],shu[time%10]);
		Shuma_Display(wei[6],shu[time/10]+0x80);//+0x80���־ʹ�����С����
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
// �����ʱx ms�ĺ���
void Delay_xms(uint x)
{
	uint j;
	uchar i;
	for (j=0;j<x;j++)
		for (i=0;i<110;i++);
}
// �������ʾ����
void Shuma_Display(uchar w,uchar d){
	uchar i=0;
	// ��λѡ
	P0 = w;
	W = 1;
	W = 0;
	// �Ͷ�ѡ
	P0 = d;
	D = 1;
	D = 0;
	for(;i<250;i++);

}