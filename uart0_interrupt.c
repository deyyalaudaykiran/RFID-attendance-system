#include<lpc21xx.h>
#include"header.h"

extern unsigned char temp[100];
 int i=0;

int num; 
 void UART0_Handler(void)__irq
 {
 num=U0IIR;
if(num&4)
 {
 temp[i++]=U0RBR;
 }
 VICVectAddr=0; 
 }


 void config_vic_for_uart0(void)
 {
    VICIntSelect=0;
	 VICVectAddr0=(int)UART0_Handler;
	 VICVectCntl0=6|(1<<5);
	 VICIntEnable|=1<<6;
}
void en_uart0_interrupt(void)
{
U0IER=3;
}

