 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.h
 *
 * Description: Header file for the LCD driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef LCD_H_
#define LCD_H_

#include "Std_Types.h"
#include "Bit_Math.h"

#include "GPIO_interface.h"


/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/* LCD Data bits mode configuration */
#define LCD_mode 8
//#define HIGH_4_PINS

/* LCD HW Pins */
#define LCD_CTRL_PORT PORTD
#define LCD_CTRL_PORT_DIR DDRD
#define LCD_DATA_PORT PORTC
#define LCD_DATA_PORT_DIR DDRC
#define RS PD4
#define RW PD5
#define E PD6

/********* LCD Commands*************/
#define LCD_CLEAR 0X01
#define CURSOR_OFF 0X0C
#define CURSOR_ON 0X0E
#define LCD_2_LINES_8_BIT 0X38
#define SET_CURSOR 0X80
#define LCD_2_LINES_4_BIT 0X28
#define FOUR_BITS_DATA_MODE 0x02



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void LCD_init(void);
void LCD_sendCommand(u8 command);
void LCD_displayCharacter(u8 data);
void LCD_displayString(const u8 *str);
void LCD_clear(void);
void LCD_displayStringRowColoumn(uint8 row,u8 col,const u *str);
void LCD_goToRowColumn(u8 row,u8 col);
void LCD_intgerToString(int data);






#endif /* LCD_H_ */
