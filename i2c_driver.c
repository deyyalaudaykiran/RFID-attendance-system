#include<lpc21xx.h>
#include"header.h"
#define SI ((I2CONSET>>3)&1)
void i2c_byte_write_frame(u8 sa,u8 mr,u8 data)
{
/*generat start condi*/
	I2CONSET =(1<<5); // STA =1
	I2CONCLR =(1<<3); //CLEAR SI
	while(SI==0);
	I2CONCLR=(1<<5);//*STA=0
	if(I2STAT!=0X8)
	{
	 uart0_tx_string("Erra:start \r\n");
	 goto exit;
	}

   /* send SA + W & Cheak ACK */
	I2DAT= sa;// send sa+w
	I2CONCLR=(1<<3); // CLEAR SI
	while(SI==0);
	if(I2STAT==0X20)
	{
	  uart0_tx_string("Erra:SA + W \r\n");
	  goto exit;
	}
 /*SEND MEMORY ADDR & CHEAK ACK*/
	 I2DAT=mr;//send m/r addr
	 I2CONCLR=(1<<3);//CLER SI
	 while(SI==0);
	 if(I2STAT==0X30)
	 {
	 uart0_tx_string("Erra:M/R \r\n");
	 goto exit;
	 }
  /*SEND DATA & CHEAK ACK*/
	I2DAT= data;// send data
	I2CONCLR=(1<<3); // CLEAR SI
	while(SI==0);
	if(I2STAT==0X30)
	{
	  uart0_tx_string("Erra:data \r\n");
	  goto exit;
	}
  /*GENERATE STOP CONDI*/
	exit:
	I2CONSET =(1<<4); // STO =1
	I2CONCLR =(1<<3); //CLEAR SI
}

u8 i2c_byte_read_frame(u8 sa,u8 mr)
  {
   u8 temp;
   /*generata condition*/
	I2CONSET =(1<<5); // STA =1
	I2CONCLR =(1<<3); //CLEAR SI
	while(SI==0);
	I2CONCLR=(1<<5);//*STA=0
	if(I2STAT!=0X8)
	{
	 uart0_tx_string("Erra:start \r\n");
	 goto exit;
	}

/*send SA+W & CHECK ACK*/
   	I2DAT= sa;// send sa+w
	I2CONCLR=(1<<3); // CLEAR SI
	while(SI==0);
	if(I2STAT==0X20)
	{
	  uart0_tx_string("Erra:SA + W \r\n");
	  goto exit;
	}
/*send m/r addr& cheak ack*/
	I2DAT= mr;// send m/r addr
	I2CONCLR=(1<<3); // CLEAR SI
	while(SI==0);
	if(I2STAT==0X30)
	{
	  uart0_tx_string("Erra:m/r \r\n");
	  goto exit;
	}
/*generat restart condi*/
   	I2CONSET =(1<<5); // STA =1
	I2CONCLR =(1<<3); //CLEAR SI
	while(SI==0);
	I2CONCLR=(1<<5);//*STA=0
	if(I2STAT!=0X10)
	{
	 uart0_tx_string("Erra:restart \r\n");
	 goto exit;
	}
/* send SA + R & Cheak ACK */
	I2DAT= sa|1;// send sa+R
	I2CONCLR=(1<<3); // CLEAR SI
	while(SI==0);
	if(I2STAT==0X48)
	{
	  uart0_tx_string("Erra:SA + W \r\n");
	  goto exit;
	}
/*READ SLAVE DADA & SEND NO ACK*/
	I2CONCLR=(1<<3); // CLEAR SI
	while(SI==0);// WAITING FOR DATA TO READ/ RECIVE
	temp=I2DAT;

/*GENERATE STOP CONDI*/
	exit:
	I2CONSET =(1<<4); // STo =1
	I2CONCLR =(1<<3); //CLEAR SI
	return temp;
}
void i2c_init()
{
	PINSEL0|=0X50;//P0.2-> SCL,P0.3->SDA
	I2SCLL=I2SCLH=75;// FOR LOOP BACK
	I2CONSET=(1<<6);// EN I2C INTERFACE
}




