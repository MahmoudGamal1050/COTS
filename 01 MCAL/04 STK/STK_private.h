/************************************************************/
/* Author	:	Mahmoud Gamal								*/
/* Date		: 	6/5/2023									*/
/************************************************************/
#ifndef	STK_PRIVATE_H
#define	STK_PRIVATE_H


#define		STK_AHB_DIV_8			0
#define		STK_AHB					1

#define		STK_SINGLE_INTERVAL		0
#define		STK_PERIOD_INTERVAL		1

typedef struct
{
	u32		CTRL;
	u32		LOAD;
	u32		VAL;
	u32		CALIB;
	
}STK_t;

#define			STK		((volatile STK_t *)(0xE000E010))

#endif
