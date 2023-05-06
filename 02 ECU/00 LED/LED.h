/*
 * LED.h
 *
 * Created: 4/5/2023 
 *  Author: Mahmoud Gamal
 */ 

#ifndef LED_H_
#define LED_H_
#define NEGATIVE_LOGIC		 0
#define POSITIVE_LOGIC	 	 1
#include	"STD_TYPES.h"
#include	"BIT_MATH.h"
#include    "GPIO_interface.h"

void led_on(u8 gpiox, u8 pin,u8 connection);
void led_off(u8 gpiox, u8 pin,u8 connection);
void led_toggle(u8 gpiox, u8 pin);


#endif /* LED_H_ */
