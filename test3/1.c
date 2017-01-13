/*
任务三
2017-1-13 19:00:59
    写一个流水灯 
    从左向右流，再从右向左流
    在从两边向中间流 *3
*/
#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char

//延时函数
void delay(int t){
	uchar i;
	int j;
	for(j=0;j<t;j++)
		for(i=0;i<125;i++)
			;
}
void main(){
/*思路分析：
	从右向左				 
    0111 1111 >> 1 =》0011 1111 +1000 0000
    1011 1111
	1101 1111
	... 
	从左向右
	1111 1110 << 1 =》1111 1100 +1
	1111 1101
	1111 1011
	...
	从两边往中间
	0111 1110 	: 0x7e
	1011 1101	: 0xbd
	1101 1011	: 0xdb
	1110 0111	: 0xe7
*/
	uchar i;
	uchar led; //保存8位亮灯的数据
	while(1){
		led = 0xfe; 
		for(i=0;i<8;i++){
	   		P0 = led;
			led = (led << 1)+1;
	    	delay(1000);
		}
		// 从右向左
		led = 0x7f;
	   	for(i=0;i<8;i++){
	   		P0 = led;
			led = (led >> 1)+0x80;
	    	delay(1000);
		}
		for(i=0;i<3;i++){
			P0 = 0x7e;delay(1000);
			P0 = 0xbd;delay(1000);
			P0 = 0xdb;delay(1000);
			P0 = 0xe7;delay(1000);
		}
	
	}

}