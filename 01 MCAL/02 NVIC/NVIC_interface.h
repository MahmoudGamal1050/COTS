/************************************************************/
/* Author	:	Mahmoud Gamal								*/
/* Date		: 	6/5/2023									*/
/************************************************************/

#ifndef	NVIC_INTERFACE_H
#define	NVIC_INTERFACE_H


/* Interrupt IDs*/

#define EXTI0Id  					6
#define EXTI1Id  					7
#define EXTI2Id  					8
#define EXTI3Id  					9
#define EXTI4Id  					10
#define DMA1_Channel1_Int_Id		11
#define DMA1_Channel2_Int_Id		12
#define DMA1_Channel3_Int_Id		13
#define DMA1_Channel4_Int_Id		14
#define DMA1_Channel5_Int_Id		15
#define DMA1_Channel6_Int_Id		16
#define DMA1_Channel7_Int_Id		17




void		NVIC_voidInit();

void NVIC_VoidEnablePerInt   ( u8 IntNum );

void NVIC_VoidDisablePerInt  ( u8 IntNum );

void NVIC_VoidSetPendingFlag        ( u8 IntNum );

void NVIC_VoidClearPendingFlag      ( u8 IntNum );

u8   NVIC_u8GetActiveFlag       ( u8 IntNum );

void NVIC_voidSetSwIntPriority(u8 IntNum , u8 GroupPriority , u8 SubPriority);



















#endif
