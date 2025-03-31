#include<LPC21XX.H>
#include"header.h"
void delay_sec(int sec)
{
T0PR=1500000-1;
T0TC=T0PC=0;
T0TCR=1;
while(T0TC<sec);
T0TCR=0;
}

void delay_ms(int ms)
{
T0PR=15000-1;
T0TC=T0PC=0;
T0TCR=1;
while(T0TC<ms);
T0TCR=0;
}
