/*
 * BUTTON.h
 *
 * Created: 4/5/2023 
 *  Author: Mahmoud Gamal
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include	"STD_TYPES.h"
#include	"BIT_MATH.h"
#include	"DELAY.H"

#include    "GPIO_interface.h"



/* Function to read the button value*/

u8 BUTTON_u8Read (u8 gpiox , u8 pin );



#endif /* BUTTON_H_ */
