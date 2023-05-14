/*
 *  LED.c
 *
 * Created: 4/5/2023 
 *  Author: Mahmoud Gamal
 */ 
#include	"LED.h"


void led_init(u8 gpiox, u8 pin)
{
	GPIO_voidSetPinMode(gpiox,pin,GPIO_OUTPUT_2MHZ_PP);
}
void led_on(u8 gpiox, u8 pin,u8 connection)
{
	
	if(connection==NEGATIVE_LOGIC)
	{
		GPIO_voidSetPinValue(gpiox,pin, GPIO_LOW);


	}
	else if ((connection==POSITIVE_LOGIC))
	{		
		GPIO_voidSetPinValue(gpiox,pin, GPIO_HIGH);

	}


}
void led_off(u8 gpiox, u8 pin,u8 connection)
{
	if(connection==NEGATIVE_LOGIC)
	{		
		GPIO_voidSetPinValue(gpiox,pin, GPIO_HIGH);

	}
	else if ((connection==POSITIVE_LOGIC))
	{		
		GPIO_voidSetPinValue(gpiox,pin, GPIO_LOW);

	}
	
}

void led_toggle(u8 gpiox, u8 pin)
{


	GPIO_voidTogPin(gpiox,pin);	

}

