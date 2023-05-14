 /******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: keypad.h
 *
 * Description: Header file for the Keypad driver
 *
 * Author: Mahmoud Gamal
 *
 *******************************************************************************/
#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*Function to initialize keypad*/  
void KEYPAD_init(void );

 u8 getPressedKey(void);


#endif /* KEYPAD_H_ */
