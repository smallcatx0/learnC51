#include<reg52.h>
sbit Sd = P1^0;
void main(){
	while(1){
		if(Sd == 0)	P0 = 0x7e;
		else 	    P0 = 0xfe;

	}
}