 /******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: keypad.c
 *
 * Description: Source file for the Keypad driver
 *
 * Author: Mahmoud Gamal
 *
 *******************************************************************************/

#include "KEYPAD.h"
#include "KEYPAD_config.h"
#include "DELAY.h"
#include "GPIO_interface.h"



	static const u8 keypad[4][4] ={
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
		};


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
 

void KEYPAD_init(void )
{
		GPIO_voidSetPinMode( GPIOA , ROW1 , GPIO_OUTPUT_2MHZ_PP );
		GPIO_voidSetPinMode( GPIOA , ROW2 , GPIO_OUTPUT_2MHZ_PP );
		GPIO_voidSetPinMode( GPIOA , ROW3 , GPIO_OUTPUT_2MHZ_PP );
		GPIO_voidSetPinMode( GPIOA , ROW4 , GPIO_OUTPUT_2MHZ_PP );
		
		GPIO_voidSetPinMode( GPIOB , COL1 , GPIO_INPUT_PULL_UP_DOWN);
		GPIO_voidSetPinMode( GPIOB , COL2 , GPIO_INPUT_PULL_UP_DOWN);
		GPIO_voidSetPinMode( GPIOB , COL3 , GPIO_INPUT_PULL_UP_DOWN);
		GPIO_voidSetPinMode( GPIOB , COL4 , GPIO_INPUT_PULL_UP_DOWN);


	

}

u8 getPressedKey(void)
{
	u8 row,col,col2;
	while(1)
	{

		for(row=0;row<4;row++)
		{
			
			GPIO_voidSetPinValue(GPIOA, 4, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOA, 5, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOA, 6, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOA, 7, GPIO_HIGH);

			GPIO_voidSetPinValue(GPIOA, row+4, GPIO_LOW);


			for(col=0;col<4;col++)
			{
				switch(col)
				{
					case 0 : col2 = 11;
					break;
					case 1 : col2 = 10;
					break;
					case 2 : col2 = 1;
					break;
					case 3 : col2 = 0;
					break;
				}
				if(!GPIO_u8GetPinValue(GPIOB, col2))
				{
					_delay_ms(100);
					if(!GPIO_u8GetPinValue(GPIOB, col2))
					{
						return keypad[row][col];
					}


				}
				
						
			}

		}


	}
}



