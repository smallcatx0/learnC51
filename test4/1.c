/*
������
2017-1-13 19:55:36
	�������ǵĵ�һ������� 
	��ʾ���ǵ�ѧ�����һλ
*/
#include<reg52.h>
#define uchar unsigned char 
#define uint unsigned int
uchar code shu[]={0x3f,0x06,0x5b,0x4f,0x66,
				  0x6d,0x7d,0x07,0x7f,0x6f
				  /*ǰ����0~9�Ķ�ѡ��*/,0x40/*-*/,};
sbit W = P3^6;
sbit D = P3^7;
// �����ʱx ms�ĺ���
void Delay_xms(uint x);
// �������ʾ����
void Shuma_Display(uchar w,uchar d);
void main(){  
    while(1){		
		// ��λѡ
		P0 = 0xfe; // 1111 1110
		// �Ȱ������͵�������D�ڣ�����ڣ�
		// �ٴ������� 
		W = 1;
		W = 0;
		// �Ͷ�ѡ
		P0 = shu[0];
		D = 1;
		D = 0;
   }

}

// �����ʱx ms�ĺ���
void Delay_xms(uint x)
{
	uint j;
	uchar i;
	for (j=0;j<x;j++)
		for (i=0;i<110;i++);
}