/*
 * LCD4BIT.c
 *
 * Created: 3/13/2023 1:54:54 AM
 *  Author: ahmed
 */ 

//INCLUDEING PART 
#include "LCD.h"
#include "LCDEXTRA.h"
#include "DELAY.h"


// initialize function
void LCD_init( ){
	GPIO_voidSetPinMode(CONTROL_PORT ,RS , GPIO_OUTPUT_2MHZ_PP) ;
	GPIO_voidSetPinMode(CONTROL_PORT ,E , GPIO_OUTPUT_2MHZ_PP) ;

	GPIO_voidSetPinMode(DATA_PORT ,PIN12 , GPIO_OUTPUT_2MHZ_PP) ;
	GPIO_voidSetPinMode(DATA_PORT ,PIN13 , GPIO_OUTPUT_2MHZ_PP) ;
	GPIO_voidSetPinMode(DATA_PORT ,PIN14 , GPIO_OUTPUT_2MHZ_PP) ;
	GPIO_voidSetPinMode(DATA_PORT ,PIN15 , GPIO_OUTPUT_2MHZ_PP) ;

	// 4 bit initialisation
	_delay_ms(50);
	LCD_writecmd(0X30) ;
	_delay_ms(5);
	LCD_writecmd(0X30) ;
	_delay_ms(1);
	LCD_writecmd(0X30) ;
	_delay_ms(10);
	LCD_writecmd(0X20) ;
	_delay_ms(10);

	// dislay initialisation
	LCD_writecmd(0x28) ;	// Function set --> DL=0 (4 bit mode), N = 1 (2 line display) F = 0 (5x8 characters)
	_delay_ms(1);
	LCD_writecmd(0x08) ;	//Display on/off control --> D=0,C=0, B=0  ---> display off
	_delay_ms(1);
	LCD_writecmd(0x01) ;	// clear display
	_delay_ms(1);
	_delay_ms(1);
	LCD_writecmd(0x06) ;	//Entry mode set --> I/D = 1 (increment cursor) & S = 0 (no shift)
	_delay_ms(1);
	LCD_writecmd(0x0C) ;	//Display on/off control --> D = 1, C and B = 0. (Cursor and blink, last two bits)

}
//write data
void LCD_writechar(u8 data) {

		//WRITE ON PORTS
		GPIO_voidSetPinValue(CONTROL_PORT,RS , GPIO_HIGH) ; //rs=1 for data
		
		GPIO_voidSetPinValue(DATA_PORT,D7 , (data>>7)&0x01);
		GPIO_voidSetPinValue(DATA_PORT,D6 , (data>>6)&0x01);
		GPIO_voidSetPinValue(DATA_PORT,D5 , (data>>5)&0x01);
		GPIO_voidSetPinValue(DATA_PORT,D4 , (data>>4)&0x01);

		GPIO_voidSetPinValue(CONTROL_PORT,E , GPIO_HIGH);
		_delay_ms(20);
		GPIO_voidSetPinValue(CONTROL_PORT,E ,GPIO_LOW) ;
		_delay_ms(20);

		GPIO_voidSetPinValue(DATA_PORT,D7 , (data>>3)&0x01);
		GPIO_voidSetPinValue(DATA_PORT,D6 , (data>>2)&0x01);
		GPIO_voidSetPinValue(DATA_PORT,D5 , (data>>1)&0x01);
		GPIO_voidSetPinValue(DATA_PORT,D4 , (data>>0)&0x01);

		GPIO_voidSetPinValue(CONTROL_PORT,E , GPIO_HIGH);
		_delay_ms(20);
		GPIO_voidSetPinValue(CONTROL_PORT,E ,GPIO_LOW) ;
		_delay_ms(20);
		
}
//write command
void LCD_writecmd(u8 cmd)  {

	//WRITE ON PORTS
	GPIO_voidSetPinValue(CONTROL_PORT,RS , GPIO_LOW) ;// rs=0 for command

	GPIO_voidSetPinValue(DATA_PORT,D7 , (cmd>>7)&0x01);
	GPIO_voidSetPinValue(DATA_PORT,D6 , (cmd>>6)&0x01);
	GPIO_voidSetPinValue(DATA_PORT,D5 , (cmd>>5)&0x01);
	GPIO_voidSetPinValue(DATA_PORT,D4 , (cmd>>4)&0x01);


	GPIO_voidSetPinValue(CONTROL_PORT,E , GPIO_HIGH);
	_delay_ms(20);
	GPIO_voidSetPinValue(CONTROL_PORT,E ,GPIO_LOW) ;
	_delay_ms(20);
	
	GPIO_voidSetPinValue(DATA_PORT,D7 , (cmd>>3)&0x01);
	GPIO_voidSetPinValue(DATA_PORT,D6 , (cmd>>2)&0x01);
	GPIO_voidSetPinValue(DATA_PORT,D5 , (cmd>>1)&0x01);
	GPIO_voidSetPinValue(DATA_PORT,D4 , (cmd>>0)&0x01);

	GPIO_voidSetPinValue(CONTROL_PORT,E , GPIO_HIGH);
	_delay_ms(20);
	GPIO_voidSetPinValue(CONTROL_PORT,E ,GPIO_LOW) ;
	_delay_ms(20);

}
//function to write string on LCD
void LCD_writestring(u8 *str){
	while(*str != '\0')
	{
		LCD_writechar(*str) ;
		str++ ;
	}
}
//select the position you need to display on lcd
void LCD_goto(u8 row, u8 col){
	if (row<2 &&col<16)
	{
		switch(row){
			case 0 : LCD_writecmd(0X80+col) ;
			break;
			case 1: LCD_writecmd(0XC0+col)  ;
			break;
		}
		}else {
		
	}
}
//function to writer number on LCD
void LCD_writernumber(u16 number) {
 u16 sum=0   ; u8 num = 0 ;
	while(number != 0){
		sum = (number%10) + sum*10  ;
		number=number/10    ;
	}
	while(sum!=0){
		num = sum%10;
		LCD_writechar(0x30+num) ;
		sum = sum/10  ;
	}
}
//function to customize  char

void LCD_customchar(u8 x , u8 y ){
	u8 i    ;
	u8 j   ;
	LCD_writecmd(0x40) ;
	for (i=0 ; i<64 ; i++)
	{
		LCD_writechar(make[i]) ;
	}
	//LCD_writecmd(0X80) ;
	LCD_goto(x,y) ;
	for (j=0 ; j<8 ; j ++)
	{
		LCD_writechar(j) ;
	}
}
void LCD_clear (void)
{
	LCD_writecmd(0x01);
	_delay_ms(2);
}
