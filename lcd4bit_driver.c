#include<lpc21xx.h>
#include "header.h"
void lcd_data(unsigned char data)
{
unsigned int temp;
//Higher nibble
IOCLR1=0XFE<<16;
temp=((data &0xf0)<<16);
IOSET1=temp;
IOSET1=1<<17;
IOCLR1=1<<18;
IOSET1=1<<19;
delay_ms(2);
IOCLR1=1<<19;
//lower nibble
IOCLR1=0XFE<<16;
temp=((data&0x0f)<<20);
IOSET1=temp;
IOSET1=1<<17;
IOCLR1=1<<18;
IOSET1=1<<19;
delay_ms(2);
IOCLR1=1<<19;
}
void lcd_cmd(unsigned char cmd)
{
//Higher nibble
unsigned  int temp;
IOCLR1=0XFE<<16;
temp=((cmd&0xf0)<<16);
IOSET1=temp;
IOCLR1=1<<17;
IOCLR1=1<<18;
IOSET1=1<<19;
delay_ms(2);
IOCLR1=1<<19;
//lower nibble
IOCLR1=0XFE<<16;
temp=((cmd&0x0f)<<20);
IOSET1=temp;
IOCLR1=1<<17;
IOCLR1=1<<18;
IOSET1=1<<19;
delay_ms(2);					 
IOCLR1=1<<19;
}
void lcd_init()
{
IODIR1=0XFE<<16;
IOCLR1=1<<19;
PINSEL2=0X0;
lcd_cmd(0x02);
lcd_cmd(0x28);
lcd_cmd(0x0e);
lcd_cmd(0x01);
lcd_cmd(0x03);
}  

void lcd_string(char *ptr)
{
while(*ptr!=0)
{
lcd_data(*ptr);
ptr++;
}
}

unsigned char a[10]={0xE,0x11,0x1B,0x11,0x11,0x1E,0xE,0x0};
void lcd_cgram()
{	 int i;
    lcd_cmd(0x40);
	for(i=0;i<=7;i++)
	{
	  lcd_data(a[i]);
	}
}

void lcd_integer(int num)
{	 int i;
    char a[20];
	if(num==0)
	{
	    lcd_data('0');
	}
	if(num<0)
	{
	lcd_data('-');
	num=-num;
	}
	i=0;
	while(num>0)
	{
	   a[i]=num%10;
	   num=num/10;
	   i++;
	}
	for(i=i-1;i>=0;i--)
	{
	lcd_data(a[i]+48);
	}
}


