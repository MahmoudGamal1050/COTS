/************************************************************/
/* Author	:	Mahmoud Gamal								*/
/* Date		: 	6/5/2023									*/
/************************************************************/
#ifndef		EXTI_PRIVATE_H
#define		EXTI_PRIVATE_H


typedef struct{

	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;

}EXTI_t;

#define EXTI ((volatile EXTI_t *) 0x40010400)

#endif /* EXTI_PRIVATE_H_ */


