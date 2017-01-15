#include<reg52.h>
#include "Nixie.h"
sbit Sd = P1^0;
void main(){
	while(1){
		if(Sd == 0)	Shuma_Display(wei[7],shu[0]);
		else 	    Shuma_Display(wei[7],shu[1]);

	}
}