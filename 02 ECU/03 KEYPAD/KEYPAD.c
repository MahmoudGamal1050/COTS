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


/*******************************************************************************
 *                      Functions Prototypes		                          *
 *******************************************************************************/


#if (N_col==3)
	static const u8 keypad[4][3] ={
		{'1','2','3'},
		{'4','5','6'},
		{'7','8','9'},
		{'*','0','#'},
		};

#elif (N_col==4)
	static const u8 keypad[4][4] ={
		{'7','8','9','/'},
		{'4','5','6','X'},
		{'1','2','3','-'},
		{'!','0','=','+'},
		};
#endif

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
 

void KEYPAD_init(void )
{
	#if KEYPAD_PORT==GPIOA
		GPIO_VidSetPortMode( GPIOA , GPIOA_LOW , GPIO_INPUT_PULL_UP_DOWN );
		GPIO_VidSetPortValue( GPIOA , GPIOA_LOW , GPIO_HIGH );

	
	#elif KEYPAD_PORT==GPIOB
		GPIO_VidSetPortMode( GPIOB , GPIOAB_LOW , GPIO_INPUT_PULL_UP_DOWN );
		GPIO_VidSetPortValue( GPIOB , GPIOB_LOW , GPIO_HIGH );
	
	#endif

}

u8 getPressedKey(void)
{
	u8 row,col;
	while(1)
	{

		for(col=0;col<N_col;col++)
		{
			
			GPIO_voidSetPinMode(GPIOA, (col+4),GPIO_OUTPUT_2MHZ_PP );
			GPIO_voidSetPinValue(GPIOA, (col+4),GPIOA_LOW);

			for(row=0;row<N_row;row++)
			{
				if(GPIO_u8GetPinValue(GPIOA, row))
						{
							return keypad[row][col];
							
						}
			}

		}


	}
}



