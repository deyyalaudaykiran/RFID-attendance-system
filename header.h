#include<lpc21xx.h>
typedef unsigned char u8;
typedef unsigned int u32  ;
void uart0_init(unsigned int baud);
void uart0_tx(unsigned char data);
void uart0_tx_string(unsigned char *p);
unsigned char uart0_rx(void);
void uart0_rx_string(char *ptr,u8 len);
 void config_vic_for_uart0(void);
 void en_uart0_interrupt(void);

void lcd_data(unsigned char data);
void lcd_cmd(unsigned char cmd);
void lcd_init(void);
void lcd_string(char *ptr);
void lcd_cgram(void);
void lcd_integer(int num);

void i2c_byte_write_frame(u8 sa,u8 mr,u8 data);
u8 i2c_byte_read_frame(u8 sa,u8 mr);
void i2c_init(void);

void delay_sec(unsigned int sec)  ;
void delay_ms(unsigned int ms)	   ;

