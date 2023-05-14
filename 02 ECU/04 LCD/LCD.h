	/*
 * LCD.h
 *
 * Created: 3/13/2023 1:55:17 AM
 *  Author: Mahmoud Gamal
 */ 


#ifndef LCD_H_
#define LCD_H_

#include	"STD_TYPES.h"
#include	"BIT_MATH.h"
#include    "GPIO_interface.h"
#include 	"STK_interface.h"


/*********** Define the LCD PINS below ****************/
#define CONTROL_PORT		 GPIOA
#define  RS					 PIN11
#define  E                   PIN8

#define DATA_PORT 			 GPIOB
#define D4					 PIN15
#define D5					 PIN14
#define D6					 PIN13
#define D7					 PIN12

// function prototype
// initialize function
void LCD_init(void ) ;
//write data
void LCD_writechar(u8 data) ;
//write command
void LCD_writecmd(u8 cmd)  ;
//function to write string on LCD
void LCD_writestring(u8 *str);
//select the position you need to display on lcd
void LCD_goto(u8 row, u8 col);
//function to writer number on LCD
void LCD_writernumber(u16 number) ;
//function to customize  char

void LCD_customchar(u8 x , u8 y );
void LCD_clear (void);


void	_delay_ms(u32 ticks);





#endif /* LCD_H_ */
