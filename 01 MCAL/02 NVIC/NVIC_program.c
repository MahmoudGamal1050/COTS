/************************************************************/
/* Author	:	Mahmoud Gamal								*/
/* Date		: 	6/5/2023									*/
/************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_config.h"
#include "NVIC_private.h"
#include "NVIC_interface.h"


void		NVIC_voidInit()
{
	/*		How many Groups and Sub Group used in the system	*/
	#ifndef SCB_AIRCR
		#define	SCB_AIRCR	*((volatile u32 *)(0xE000ED0C))
	#endif
	SCB_AIRCR = NVIC_NUM_GRP_SUB;
}


void NVIC_VoidEnablePerInt  ( u8 IntNum )
{
	if(IntNum<=31)
	{
		NVIC_ISER0 = (1<<IntNum);
	}
	
	else if(IntNum<60)
	{
		IntNum -= 32;
		NVIC_ISER1 = (1<<IntNum);
	}
	
	else
	{
		/* Return Error */
	}
}


void NVIC_VoidDisablePerInt  ( u8 IntNum )
{
	if(IntNum<=31)
	{
		NVIC_ICER0 = (1<<IntNum);
	}
	
	else if(IntNum<60)
	{
		IntNum -= 32;
		NVIC_ICER1 = (1<<IntNum);
	}
	
	else
	{
		/* Return Error */
	}
}


void NVIC_VoidSetPendingFlag ( u8 IntNum )
{
	if(IntNum<=31)
	{
		NVIC_ISPR0 = (1<<IntNum);
	}
	
	else if(IntNum<60)
	{
		IntNum -= 32;
		NVIC_ISPR1 = (1<<IntNum);
	}
	
	else
	{
		/* Return Error */
	}
}


void NVIC_VoidClearPendingFlag ( u8 IntNum )
{
	if(IntNum<=31)
	{
		NVIC_ICPR0 = (1<<IntNum);
	}
	
	else if(IntNum<60)
	{
		IntNum -= 32;
		NVIC_ICPR1 = (1<<IntNum);
	}
	
	else
	{
		/* Return Error */
	}
}

u8   NVIC_u8GetActiveFlag( u8 IntNum )
{
	u8 Local_u8Result;
	if(IntNum<=31)
	{
		 Local_u8Result = GET_BIT (NVIC_IABR0,IntNum);
	}
	
	else if(IntNum<60)
	{
		IntNum -= 32;
		Local_u8Result =  GET_BIT (NVIC_IABR1,IntNum);
	}
	
	else
	{
		/* Return Error */
	}
	
	return Local_u8Result;
}


void		NVIC_voidSetSwIntPriority(u8 IntNum , u8 GroupPriority , u8 SubPriority)
{
	u8 Priority =  SubPriority | GroupPriority << ( (GRB_04_SUB_04 - 0x05FA0300) / 0x100 )  ;

	/*		Range Check			*/
	if(IntNum<60)
	{
		NVIC_IPR[IntNum] = (Priority << 4 );
	}


}
















