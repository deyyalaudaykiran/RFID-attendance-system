#include<LPC21xx.H>
#include"header.h"
#define RDR ((U0LSR&1))
#define u8 unsigned char 
#define u32 unsigned int
#define THRE ((U0LSR>>5)&1)
  /* uart init */
void uart0_init(unsigned int baud)

{

unsigned int result=0;

int a[]={15,60,30,15,15};

unsigned int pclk=a[VPBDIV]*1000000;

result=pclk/(16*baud);

PINSEL0|=5;

U0LCR=0X83;

U0DLL=result&0XFF;

U0DLM=(result>>8)&0XFF;

U0LCR=0x03;

}

#define THRE ((U0LSR>>5)&1)
/* uart transmit*/
void uart0_tx(unsigned char data)

{

U0THR=data;

while(THRE==0);

}
	 /* uart transmit string*/
void uart0_tx_string(unsigned char *p)
{
while(*p)
{
U0THR=*p;
while(THRE==0);
p++;
}
}
  /* receive*/
unsigned char uart0_rx(void)
{
while((U0LSR&1)==0);
return U0RBR;
}

/* rx string*/
void uart0_rx_string(char *ptr,u8 len)
{
int i;
for(i=0;i<len;i++)
{
 while(RDR==0);
ptr[i]=U0RBR;
if(ptr[i]=='\r')
break;
}
ptr[i]='\0';
}


  
