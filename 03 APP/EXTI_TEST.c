/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mahmoud Gamal
 * @brief          : Main program body
 ******************************************************************************/

#include <stdint.h>

#include	"STD_TYPES.h"
#include	"BIT_MATH.h"
#include 	"DELAY.h"

#include	"RCC_interface.h"
#include	"GPIO_interface.h"
#include	"NVIC_interface.h"
#include	"AFIO_interface.h"
#include	"EXTI_interface.h"
#include	"LED.h"
#include	"SevenSeg.h"



void Led_toggle(void);




int main(void)
{
	/*Enable System Clock*/
	RCC_voidSysClkInt();
	/*Enable GPIO RCC*/
	RCC_voidEnablePerClk(RCC_APB2, GPIOA_RCC);
	RCC_voidEnablePerClk(RCC_APB2, GPIOB_RCC);
	RCC_voidEnablePerClk(RCC_APB2, GPIOC_RCC);
	/* Enable AFIO RCC */
	RCC_voidEnablePerClk(RCC_APB2, AFIO_RCC);
	/* Configure B0 as input  */
	GPIO_voidSetPinMode(GPIOB, PIN0, GPIO_INPUT_PULL_UP_DOWN);

	/* Use AF for B0*/
	AFIO_VoidSetEXTIConfig(EXTI_LINE0,PORTB);

	/* Two Leds are conncted to A1 and A2*/
	led_init(GPIOA, PIN1);
	led_init(GPIOA, PIN2);

	/* Set priority for EXI0 and EXTI1*/
	NVIC_voidInit();
	NVIC_voidSetSwIntPriority(EXTI0Id, 1, 0);	/* EXTI0 is group 1 priority and subgroup 0 priority*/

	/* Enable Peripheral interrupts*/
	NVIC_VoidEnablePerInt(EXTI0Id);

	/* INT0 on B0 occurs on falling edge */
	EXTI_VoidInit(EXTI_LINE0,FALLING_EDGE);

	/* Pass Led_toggle as a call back function*/
	EXTI0_VoidSetCallBack(Led_toggle);






    /* Loop forever */
	while(1)
	{



	}
	return 0;
}
void Led_toggle(void)
{
	led_toggle(GPIOA, PIN1);



}

