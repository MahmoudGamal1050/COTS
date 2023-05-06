 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.c
 *
 * Description: Source file for the LCD driver
 *
 * Author: Mahmoud Gamal
 *
 *******************************************************************************/

#include "lcd.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void LCD_init(void)
{
	LCD_CTRL_PORT_DIR |= (1<<RS)|(1<<RW)|(1<<E); /* configure control pins as output*/

	#if (LCD_mode==4)
		#ifdef HIGH_4_PINS
		LCD_DATA_PORT_DIR |= 0XF0;			/*  configure data pins as output*/
		#else
		LCD_DATA_PORT_DIR |= 0X0F;			/*  configure data pins as output*/
		#endif

		LCD_sendCommand(FOUR_BITS_DATA_MODE);
		LCD_sendCommand(LCD_2_LINES_4_BIT);       /* select 2 lines LCD 8 bit mode */

	#elif (LCD_mode==8)
		LCD_DATA_PORT_DIR = 0XFF;			/*  configure data port as output*/
		LCD_sendCommand(LCD_2_LINES_8_BIT);       /* select 2 lines LCD 8 bit mode */

	#endif

	LCD_sendCommand(CURSOR_OFF);
	LCD_sendCommand(LCD_CLEAR);


}


void LCD_sendCommand(u8 command)
{
	CLEAR_BIT(LCD_CTRL_PORT,RS);	/* Instruction Mode RS=0 */
	CLEAR_BIT(LCD_CTRL_PORT,RW);	/* write data to LCD so RW=0 */
	_delay_ms(1);			/* delay for processing Tas = 50ns */	
	SET_BIT(LCD_CTRL_PORT,E);	/* Enable LCD E=1 */
	_delay_ms(1);

	#if (LCD_mode==4)
		/* out the highest 4 bits of the required command to the data bus D4 --> D7 */
		#ifdef HIGH_4_PINS
		LCD_DATA_PORT = (LCD_DATA_PORT& 0X0F)| (command & 0XF0);
		#else
		LCD_DATA_PORT = (LCD_DATA_PORT& 0XF0)| ((command & 0XF0)>>4);
		#endif

		_delay_ms(1);
		CLEAR_BIT(LCD_CTRL_PORT,E);	/* disable LCD E=0 */
		_delay_ms(1);
		SET_BIT(LCD_CTRL_PORT,E);	/* Enable LCD E=1 */
		_delay_ms(1);

		/* out the lowest 4 bits of the required command to the data bus D4 --> D7 */
		#ifdef HIGH_4_PINS
		LCD_DATA_PORT = (LCD_DATA_PORT& 0X0F)| ((command & 0X0F)<<4);
		#else
		LCD_DATA_PORT = (LCD_DATA_PORT& 0XF0)| (command & 0X0F);
  	  	#endif

		_delay_ms(1);
		CLEAR_BIT(LCD_CTRL_PORT,E);	/* disable LCD E=0 */
		_delay_ms(1);



	#elif (LCD_mode==8)
		LCD_DATA_PORT = command ;	/* out the required command to the data bus D0 --> D7 */
		_delay_ms(1);
		CLEAR_BIT(LCD_CTRL_PORT,E);	/* disable LCD E=0 */
		_delay_ms(1);
	#endif






}

void LCD_displayCharacter(u8 data)
{
	SET_BIT(LCD_CTRL_PORT,RS);	/* Data Mode RS=1 */
	CLEAR_BIT(LCD_CTRL_PORT,RW);	/* write data to LCD so RW=0 */
	_delay_ms(1);
	SET_BIT(LCD_CTRL_PORT,E);	 /* Enable LCD E=1 */
	_delay_ms(1);
	#if (LCD_mode==4)
		/* out the highest 4 bits of the required data to the data bus D4 --> D7 */
		#ifdef HIGH_4_PINS
		LCD_DATA_PORT = (LCD_DATA_PORT& 0X0F)| (data & 0XF0);
		#else
		LCD_DATA_PORT = (LCD_DATA_PORT& 0XF0)| ((data & 0XF0)>>4);
		#endif

		_delay_ms(1);
		CLEAR_BIT(LCD_CTRL_PORT,E);	/* disable LCD E=0 */
		_delay_ms(1);
		SET_BIT(LCD_CTRL_PORT,E);	 /* Enable LCD E=1 */
		_delay_ms(1);

	/* out the lowest 4 bits of the required data to the data bus D4 --> D7 */
    #ifdef HIGH_4_PINS
		LCD_DATA_PORT = (LCD_DATA_PORT& 0X0F)| ((data & 0X0F)<<4);
    #else
		LCD_DATA_PORT = (LCD_DATA_PORT& 0XF0)| (data & 0X0F);
    #endif

		_delay_ms(1);
		CLEAR_BIT(LCD_CTRL_PORT,E);	/* disable LCD E=0 */
		_delay_ms(1);

	#elif (LCD_mode==8)
		LCD_DATA_PORT = data ;	/* out the required command to the data bus D0 --> D7 */
		_delay_ms(1);
		CLEAR_BIT(LCD_CTRL_PORT,E);	/* disable LCD E=0 */
		_delay_ms(1);
	#endif

}

void LCD_displayString(const u8 *str)
{

	while(*str != '\0')
	{
		LCD_displayCharacter(*str);
		str++;

	}
}

void LCD_goToRowColumn(u8 row,u8 col)
{
	uint8 address;
	switch(row)
	{
		case 0 :
			address = col;
			break;

		case 1 :
			address = col+0x40;
			break;
		case 2 :
			address = col+0x10;
			break;
		case 3 :
			address = col+0x50;
			break;

	}
	LCD_sendCommand(address+SET_CURSOR);

}

void LCD_displayStringRowColoumn(u8 row,u8 col,const u8 *str)
{
	LCD_goToRowColumn(row,col);
	LCD_displayString(str);

}

void LCD_clear(void)
{
	LCD_sendCommand(LCD_CLEAR);

}

void LCD_intgerToString(int data)
{
	u8 buff[16];
	itoa(data,buff,10);
	LCD_displayString(buff);

}


