#include"header.h"
#include<string.h>
		
	extern int i;							   
	 unsigned char temp[100];
		int main()
		{
		 int a;
	 	unsigned char empl[100];
		int flag1=0,j;
		
		int index;
		int flag,k;
		unsigned char h,m,s,t;
		unsigned char date,month,year;
		int b[5]={0,0,0,0,0,};
		
	
		i2c_init();
		lcd_init();
		uart0_init(9600);
		config_vic_for_uart0();
	     en_uart0_interrupt();
		uart0_tx_string("DS1307 RTC\r\n");
		
		i2c_byte_write_frame(0XD0,0X2,0x49);  //hrs
		i2c_byte_write_frame(0XD0,0X1,0X30);  //mins
		i2c_byte_write_frame(0XD0,0X0,0X00);  //seconds
		i2c_byte_write_frame(0XD0,0X4,0X10);  //date
		i2c_byte_write_frame(0XD0,0X5,0X03);  //month
		i2c_byte_write_frame(0XD0,0X6,0X26);  //year
		i2c_byte_write_frame(0XD0,0X3,0X03);  //day

		  
     	while(1)
		{
		 lcd_cmd(0x80);
		 h=i2c_byte_read_frame(0XD0,0X02);
		 m=i2c_byte_read_frame(0XD0,0X01);
		 s=i2c_byte_read_frame(0XD0,0X00);
		 date=i2c_byte_read_frame(0XD0,0X04);	  
		 month=i2c_byte_read_frame(0XD0,0X05);
		 year=i2c_byte_read_frame(0XD0,0X06);
		 index=i2c_byte_read_frame(0XD0,0X03);
	     
	     t=(h & 0x1f);
		  a=(h>>5)&1 ;
		 if((h>>5)&1)
		   {
	        flag=1;
	   	   }	
	      else
		   {
			 flag=0;
		    }      
	
		lcd_data(t/16+48);
		lcd_data(t%16+48);
		lcd_data(':');
		
		
		lcd_data(m/16+48);
		lcd_data(m%16+48);
		lcd_data(':');
		
		
		lcd_data(s/16+48);
		lcd_data(s%16+48);
		 if(flag==1)
		    lcd_string(" PM");
		 else
		     lcd_string(" AM");
	
	    
		lcd_cmd(0xC0);
		   
	    lcd_data(date/16+48);
		lcd_data(date%16+48);
		lcd_data('/');
	
		lcd_data(month/16+48);
		lcd_data(month%16+48);
		lcd_data('/');
	
	    lcd_string("20");
		lcd_data(year/16+48);
		lcd_data(year%16+48);
	
		 lcd_cmd(0xcf-3);

		 if(index==1)
		    lcd_string("SUN");
		 if(index==2)
		    lcd_string("MON");
		 if(index==3)
		    lcd_string("TUE");
		 if(index==4)
		    lcd_string("WED");
		 if(index==5)
		    lcd_string("THU");
		 if(index==6)
		    lcd_string("FRI");
		 if(index==7)
		    lcd_string("SAT");

		
		 if(i==12)
		 {
		 flag1=1;
				 i=0;

		  }

           if(flag1==1)
		     {
			   for(j=0,k=0;temp[k];k++)
            		   empl[j++]=temp[k];           
			   empl[j++]=' ';

			   empl[j++]=t/16+48;
			   empl[j++]=t%16+48;
			   empl[j++]=':';
			   empl[j++]=m/16+48;
			   empl[j++]=m%16+48;
			   empl[j++]=':';
			   empl[j++]=s/16+48;
			   empl[j++]=s%16+48;
			   empl[j++]=' ';
					
					//AM PM
					if(a)
					{
					    empl[j++]='P';
						empl[j++]='M';
						empl[j++]=' ';
					}
					else
					{
					    empl[j++]='A';
						empl[j++]='M';
						empl[j++]=' ';
					
					}

			   empl[j++]=date/16+48;
			   empl[j++]=date%16+48;
			   empl[j++]='/';
			   empl[j++]=month/16+48;
			   empl[j++]=month%16+48;
			   empl[j++]='/';
			   empl[j++]=year/16+48;
			   empl[j++]=year%16+48;
			   empl[j++]=' ';
		   //day
			   		
		 if(index==1)
		  { empl[j++]='S';
			empl[j++]='U';
			empl[j++]='N';
			empl[j++]=' ';
		  }
		 if(index==2)
		  {  empl[j++]='M';
			empl[j++]='O';
			empl[j++]='N';
			empl[j++]=' ';
		  }
		 if(index==3)
		  { empl[j++]='T';
			empl[j++]='U';
			empl[j++]='E';
			empl[j++]=' ';
		  }
		 if(index==4)
		  {  empl[j++]='W';
			empl[j++]='E';
			empl[j++]='D';
			empl[j++]=' ';
		  }
		 if(index==5)
		  {  empl[j++]='T';
			empl[j++]='H';
			empl[j++]='U';
			empl[j++]=' ';
		  }
		 if(index==6)
		  {  empl[j++]='F';
			empl[j++]='R';
			empl[j++]='I';
			empl[j++]=' ';
		  }
		 if(index==7)
		  { empl[j++]='S';
			empl[j++]='A';
			empl[j++]='T';
			empl[j++]=' ';
		  }
			   empl[j++]='\r';
			   empl[j++]='\n';
			   empl[j]='\0';
			   
			   uart0_tx_string(empl);
			   	lcd_cmd(0x01);
			   if(strcmp(temp,"4900C9C08FCF")==0){
			   lcd_cmd(0x80);
			   lcd_string("uday");
			   b[0]++;
			   lcd_cmd(0xC0);
			   if(b[0]%2==0)
			   lcd_string("logout");
			   else
			   lcd_string("login");  
			   delay_ms(500);
			   }

			   else if(strcmp(temp,"4900C8EC3855")==0){
			   lcd_cmd(0x80);
			   lcd_string("sachin");
			   b[1]++;
			   lcd_cmd(0xC0);
			   if(b[1]%2==0)
			   lcd_string("logout");
			   else
			   lcd_string("login");  
			   delay_ms(500);
			   }


			   else if(strcmp(temp,"0200105B3C75")==0){
			   lcd_cmd(0x80);
			   lcd_string("Anuradha");
			   b[2]++;
			   lcd_cmd(0xC0);
			   if(b[2]%2==0)
			   lcd_string("logout");
			   else
			   lcd_string("login");  
			   delay_ms(500);
			   }

               else if(strcmp(temp,"4900C8E53F5V")==0){
			   lcd_cmd(0x80);
			   lcd_string("parti");
			   b[3]++;
			   lcd_cmd(0xC0);
			   if(b[3]%2==0)
			   lcd_string("logout");
			   else
			   lcd_string("login");  
			   delay_ms(500);
			   }                

			   else if(strcmp(temp,"00201068BE891")==0){
			   lcd_cmd(0x80);
			   lcd_string("Kavya");
			   b[4]++;
			   lcd_cmd(0xC0);
			   if(b[4]%2==0)
			   lcd_string("logout");
			   else
			   lcd_string("login");  
			   delay_ms(500);
			   }

			   else  {
			   lcd_cmd(0x80);
			   lcd_string("Invalid");
			   delay_ms(500);

			   }


			  flag1=0;
			
			 }          

		   }  
		}
		
		
		
		
		
		

