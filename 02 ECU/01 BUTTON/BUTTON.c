/*
 * BUTTON.c
 *
 * Created: 4/5/2023 
 *  Author: Mahmoud Gamal
 */ 


#include "BUTTON.h"



/* Read the button value*/

u8 BUTTON_u8Read (u8 gpiox , u8 pin )
{
	GPIO_voidSetPinMode(gpiox , pin , GPIO_INPUT_PULL_UP_DOWN);
	GPIO_voidSetPinValue(gpiox , pin , GPIO_HIGH);
	
	

	return GPIO_u8GetPinValue(gpiox , pin) ;
}

