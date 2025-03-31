#include<LPC21XX.H>
#include"header.h"
s32 v[]={15,60,30,0,15};
void uart_init(u32 baud)
{
 u32 temp=0,pclk=0;
pclk=v[VPBDIV]*1000000;
	if(VPBDIV!=3)
		temp=(pclk/(16*baud));
	PINSEL0|=0x5;
	U0LCR=0x83;
	U0DLL=temp&0xff;
	U0DLM=(temp>>8)&0xff;
	U0LCR=0x03;
}
#define THRE ((U0LSR>>5)&1)
void uart_tx(u8 data)
{
	U0THR=data;
	while(THRE==0);
}
#define RDR (U0LSR&1)
u8 uart_rx(void)
{
	while (RDR==0);
		return U0RBR;
}
	void uart_tx_string(char *ptr)
	{
		while(*ptr!=0)
		{
			U0THR=*ptr;
			while(THRE==0);
			ptr++;
		}
	}
	void uart_rx_string(s8 *ptr,u8 len)
	{
		u8 i;
		for(i=0;i<len;i++)
		{
			while(RDR==0);
			if(ptr[i]=='\r')
				break;
		}
		ptr[i]='\0';
	}
	void uart_integer(s32 num)
	{
		s32 i;
		s8 a[10];
		if(num==0)
		{
			uart_tx('0');
		  return;
		}
	 if(num<0)
	 {
		 uart_tx('-');
		 num=-num;
	 }
	 i=0;
	 while(num>0)
	 {
		 a[i]=(num%10)+48;
		 i++;
		 num/=10;
	 }
	 for(--i;i>=0;i--)
	 uart_tx(a[i]);
 }
	
			
	



