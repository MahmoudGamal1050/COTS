/************************************************************/
/* Author	:	Mahmoud Gamal								*/
/* Date		: 	6/5/2023									*/
/************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_



/*	Ports	*/

#define PORTA           0
#define PORTB           1
#define PORTC           2

/* External Interrupt Lines */

#define EXTI_LINE0  0
#define EXTI_LINE1  1
#define EXTI_LINE2  2
#define EXTI_LINE3  3

#define EXTI_LINE4  4
#define EXTI_LINE5  5
#define EXTI_LINE6  6
#define EXTI_LINE7  7

#define EXTI_LINE8  8
#define EXTI_LINE9  9
#define EXTI_LINE10 10
#define EXTI_LINE11 11

#define EXTI_LINE12 12
#define EXTI_LINE13 13
#define EXTI_LINE14 14
#define EXTI_LINE15 15


/*External Interrupt Sense Modes */

#define RISING_EDGE    1
#define FALLING_EDGE   2
#define ON_CHANGE      3






	/*	Functions Decleration	*/

void EXTI_VoidInit( u8 Line , u8 Mode );

void EXTI_VoidEnableEXTI( u8 Line);

void EXTI_VoidDisableEXTI( u8 Line);

void EXTI_VoidSWTrigger( u8 Line);


/*CallBack Functions Declerations*/

void EXTI0_VoidSetCallBack( void (*ptr) (void) );

#endif /* EXTI_INTERFACE_H_ */
