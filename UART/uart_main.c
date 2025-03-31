#include<lpc21xx.h>
#include"header.h"
#define FAN (1<<17)
#define LED (1<<18)
#define MOTOR (1<<11)
int main()
{
	u8 temp;
	uart_init(9600);
	IODIR0=FAN|LED|MOTOR;
	while(1)
	{
		uart_tx_string("\r\nMenu");
		uart_tx_string("\r\n a.FAN ON");
		uart_tx_string("\r\n b.FAN OFF");
		uart_tx_string("\r\n c.LED ON");
		uart_tx_string("\r\n d.LED OFF");
		uart_tx_string("\r\n e.MOTOR ON");
		uart_tx_string("\r\n f.MOTOR OFF");
		uart_tx_string("\r\n option...");
		uart_tx_string("\r\n----------------------");
		temp=uart_rx();
		switch(temp)
		{
			case 'a': IOCLR0=FAN;
				break;
			case 'b': IOSET0=FAN;
			break;
			case 'c': IOCLR0=LED;
			 break;
				case 'd': IOSET0=LED;
		 	break;
			case 'e': IOCLR0=MOTOR;
			 break;
			case 'f': IOSET0=MOTOR;
			break;
			
		//	default:uart_tx_string("\r\n Invalid comment : please enter correct option");
		}
	}
}

		