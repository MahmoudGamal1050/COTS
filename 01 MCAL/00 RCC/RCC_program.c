/*
 * RCC_program.c
 *
 * Created: 4/5/2023 
 *  Author: Mahmoud Gamal
 */ 
#include "STD_TYPES.H"
#include "BIT_MATH.H"
#include "ERROR_STATUS.H"

#include "RCC_interface.H"
#include "RCC_private.H"
#include "RCC_config.H"

void RCC_voidSysClkInt(void)
{	
	#if RCC_SYS_CLK == HSI
		/* Set HSION (Bit 0) IN RCC_CR Register */
		SET_BIT( RCC_CR , 0 );

		/*  RCC_CFGR SW[1:0] = 00 to select HSI as system clock */
		CLR_BIT( RCC_CFGR , 0  );
		CLR_BIT( RCC_CFGR , 1  );

	#elif RCC_SYS_CLK == HSE
		/* Set HSEON (Bit 16) IN RCC_CR Register */
		/* Clear CSSBYB to disable bybass */
		SET_BIT( RCC_CR , 16 );
		CLR_BIT( RCC_CR , 18  );

		/*  RCC_CFGR SW[1:0] = 01 to select HSE as system clock */
		SET_BIT( RCC_CFGR , 0  );
		CLR_BIT( RCC_CFGR , 1  );
	#elif RCC_SYS_CLK == HSE_BYPASS
		/* Set HSEON (Bit 16) IN RCC_CR Register */
		/* Set CSSBYB to enable bybass */
		SET_BIT( RCC_CR , 16 );
		SET_BIT( RCC_CR , 18  );

		/*  RCC_CFGR SW[1:0] = 01 to select HSE as system clock */
		SET_BIT( RCC_CFGR , 0  );
		CLR_BIT( RCC_CFGR , 1  );


	#elif RCC_SYS_CLK == PLL

		/*  RCC_CFGR SW[1:0] = 10 to select PLL as system clock */
		CLR_BIT( RCC_CFGR , 0  );
		SET_BIT( RCC_CFGR , 1  );

		
		/* Choosing PLL Multiplication Factor  */
		/* Write PLL multiplication factor to PLLMUL[3:0] */
		RCC_CFGR &= ~( ( 0b1111 ) << 18 ) ;
		RCC_CFGR |=  ( RCC_PLL_MUL_FACTOR ) << 18   ;

	
		#if	RCC_PLL_SRC == PLL_HSI_DIVIDED_BY_2

			/*  Clear PLLSRC (bit 16) in RCC_CFGR TO */
			CLR_BIT( RCC_CFGR , 16 );

		#elif RCC_PLL_SRC == PLL_HSE

			/* Set HSEON (Bit 16) in RCC_CR */
			SET_BIT( RCC_CR   , 16 );

			/* Set PLLSRC (bit 16) in RCC_CFGR to select HSE as input for PLL */
			SET_BIT( RCC_CFGR , 16 );

			/* Clear PLLXTPRE (bit 17) in RCC_CFGR (HSE  not divided) */
			CLR_BIT( RCC_CFGR , 17 );

		#elif RCC_PLL_SRC == PLL_HSE_DIVIDED_BY_2

			/* Set HSEON (Bit 16) in RCC_CR */
			SET_BIT( RCC_CR   , 16 );

			/* Set PLLSRC (bit 16) in RCC_CFGR to select HSE as input for PLL */
			SET_BIT( RCC_CFGR , 16 );

			/* Set PLLXTPRE (bit 17) in RCC_CFGR (HSE/2) */
			SET_BIT( RCC_CFGR , 17 );

		#endif

		/* PLL Clock Enable (bit 24 in RCC_CR)*/
		SET_BIT( RCC_CR , 24 );

	
	#endif


}


void		RCC_voidEnablePerClk(u8 BusId , u8 PerId)
{
	/*	Range Check		*/
	if(PerId < 32)
	{
		switch(BusId)
		{
			case	RCC_AHB	:	SET_BIT(RCC_AHBENR,PerId) ;		break;
			case	RCC_APB1	:	SET_BIT(RCC_APB1ENR,PerId);	break;
			case	RCC_APB2	:	SET_BIT(RCC_APB2ENR,PerId);	break;
		
		}
		
	}

	else
	{	
		/* Return Error "Out Of The Range" */
	}
	
}
void	RCC_voidDisablePerClk	(u8 BusId , u8 PerId)
{
	/*	Range Check		*/
	if(PerId < 32)
	{
		switch(BusId)
		{
			case	RCC_AHB		:	CLR_BIT(RCC_AHBENR,PerId) ;	break;
			case	RCC_APB1	:	CLR_BIT(RCC_APB1ENR,PerId);	break;
			case	RCC_APB2	:	CLR_BIT(RCC_APB2ENR,PerId);	break;
		}
		
	}

	else
	{	
		/*	Return Error "Out Of The Range"	*/	
	}	
}