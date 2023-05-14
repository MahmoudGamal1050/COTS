/************************************************************/
/* Author	:	Mahmoud Gamal								*/
/* Date		: 	6/5/2023									*/
/************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_private.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"


void (*EXTI0_CallBack) (void)= NULL;
void (*EXTI1_CallBack) (void)= NULL;


void EXTI_VoidInit( u8 Line , u8 Mode )
{

	switch(Mode){

	case RISING_EDGE:

		SET_BIT( EXTI->RTSR , Line );

		break;


	case FALLING_EDGE:

		SET_BIT( EXTI->FTSR , Line );

		break;


	case ON_CHANGE:

		SET_BIT( EXTI->RTSR , Line );
		SET_BIT( EXTI->FTSR , Line );

		break;
	}

	SET_BIT( EXTI->IMR , Line );

}

void EXTI_VoidEnableEXTI( u8 Line)
{
	SET_BIT( EXTI->IMR , Line );

}

void EXTI_VoidDisableEXTI( u8 Line)
{
	CLR_BIT( EXTI->IMR , Line );

}

void EXTI_VoidSWTrigger( u8 Line)
{
	SET_BIT( EXTI->SWIER , Line );

}

/* ISR 0 */
void EXTI0_VoidSetCallBack( void (*ptr) (void) )
{
	EXTI0_CallBack = ptr;

}
void EXTI0_IRQHandler(void){

	EXTI0_CallBack();
	
	/* Clear pending bit*/
	SET_BIT( EXTI->PR , 0 );

}
void EXTI1_VoidSetCallBack( void (*ptr) (void) )
{
	EXTI1_CallBack = ptr;

}
void EXTI1_IRQHandler(void){

	EXTI1_CallBack();

	/* Clear pending bit*/
	SET_BIT( EXTI->PR , 0 );

}














