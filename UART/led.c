#include<LPC21XX.H>
#include"header.h"
#define LED1 (1<<17)
#define LED2 (1<<18)
#define LED3 (1<<19)
int main()
{
IODIR0=LED1|LED2|LED3;

	while(1)
	{
		IOSET0=LED1|LED2|LED3;
		delay_ms(200);
		IOCLR0=LED1|LED2|LED3;
		delay_ms(200);
	}
	
}



	
