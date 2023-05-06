#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

#include	"GPIO_interface.h"
#include	"GPIO_private.h"






void	GPIO_voidSetPinMode(u8 gpiox, u8 pin, u8 mode)
{
	/*		Range Check 		*/
	if(gpiox < 3 && pin < 16)
	{
		if(pin<8)	/*		Low	(PIN0:PIN7) CRL	*/
		{
			switch(gpiox)
			{
				case GPIOA :
					/*		Clear the 4 bits before writing		*/
					GPIOA_CRL &= ~((0b1111)<<(pin * 4));
					/*		Assign the mode value			*/
					GPIOA_CRL |=  ((mode)<<(pin * 4));
					break;
				
				case GPIOB :
					/*		Clear the 4 bits before writing		*/
					GPIOB_CRL &= ~((0b1111)<<(pin * 4));
					/*		Assign the mode value			*/
					GPIOB_CRL |=  ((mode)<<(pin * 4));
					break;
				
				case GPIOC :
					/*		Clear the 4 bits before writing		*/
					GPIOC_CRL &= ~((0b1111)<<(pin * 4));
					/*		Assign the mode value			*/
					GPIOC_CRL |=  ((mode)<<(pin * 4));
					break;
			}
		}else if(pin<16)	/*		HIGH (PIN8:PIN15) CRH	*/
		{
			pin -= 8;
			switch(gpiox)
			{
				case GPIOA :
					/*		Clear the 4 bits before writing		*/
					GPIOA_CRH &= ~((0b1111)<<(pin * 4));
					/*		Assign the mode value			*/
					GPIOA_CRH |=  ((mode)<<(pin * 4));
					break;
				
				case GPIOB :
					/*		Clear the 4 bits before writing		*/
					GPIOB_CRH &= ~((0b1111)<<(pin * 4));
					/*		Assign the mode value			*/
					GPIOB_CRH |=  ((mode)<<(pin * 4));
					break;
				
				case GPIOC :
					/*		Clear the 4 bits before writing		*/
					GPIOC_CRH &= ~((0b1111)<<(pin * 4));
					/*		Assign the mode value			*/
					GPIOC_CRH |=  ((mode)<<(pin * 4));
					break;
			}

		}
	}
	
	else{/*	Return Error	*/}
}
void	GPIO_voidSetPinValue(u8 gpiox, u8 pin, u8 value)
{
	/*		Range Check 		*/
	if(gpiox < 3 && pin < 16)
	{
		if(value == GPIO_HIGH)
		{
			switch(gpiox)
			{
				case	GPIOA	:	GPIOA_BSRR = (1<<pin);	break;
				case	GPIOB	:	GPIOB_BSRR = (1<<pin);	break;
				case	GPIOC	:	GPIOC_BSRR = (1<<pin);	break;
			}
		}
		else if(value == GPIO_LOW)
		{
			switch(gpiox)
			{
				case	GPIOA	:	GPIOA_BRR = (1<<pin);	break;
				case	GPIOB	:	GPIOB_BRR = (1<<pin);	break;
				case	GPIOC	:	GPIOC_BRR = (1<<pin);	break;
			}			
		}
		
	}
	
	else{/*	Return Error	*/}
	
}

void	GPIO_voidTogPin(u8 gpiox, u8 pin)
{
	/*		Range Check 		*/
	if(gpiox < 3 && pin < 16)
	{
		
		switch(gpiox)
		{
			case	GPIOA	:	TOG_BIT(GPIOA_ODR,pin);	break;
			case	GPIOB	:	TOG_BIT(GPIOB_ODR,pin);	break;
			case	GPIOC	:	TOG_BIT(GPIOC_ODR,pin);	break;
		}	
		
	}
	
	else{/*	Return Error	*/}
}

u8		GPIO_u8GetPinValue(u8 gpiox, u8 pin)
{
	u8	local_u8val = 0x99;

	/*		Range Check 		*/
	if(gpiox < 3 && pin < 16)
	{
			switch(gpiox)
			{
				case	GPIOA	:	local_u8val	=	GET_BIT(GPIOA_IDR,pin);	break;
				case	GPIOB	:	local_u8val	=	GET_BIT(GPIOB_IDR,pin);	break;
				case	GPIOC	:	local_u8val	=	GET_BIT(GPIOC_IDR,pin);	break;
			}
	}
	else{/*	Return Error	*/}	
	
	return local_u8val;
}




void GPIO_VoidSetPortMode( u8 gpiox , u8 position , u8 mode ){

	switch( gpiox ){

	case GPIOA:

		if  ( position == GPIO_LOW  )
		{ 
			GPIOA_CRL = ( 0x11111111 * mode );
		}
		else if ( position == GPIO_HIGH )
		{ 
			GPIOA_CRH = ( 0x11111111 * mode ) ; 
		}
		break;
		
	case GPIOB:

		if  ( position == GPIO_LOW  )
		{ 
			GPIOB_CRL = ( 0x11111111 * mode );
		}
		else if ( position == GPIO_HIGH )
		{ 
			GPIOB_CRH = ( 0x11111111 * mode ) ; 
		}
		break;
	case GPIOC:

		if  ( position == GPIO_LOW  )
		{ 
			GPIOC_CRL = ( 0x11111111 * mode );
		}
		else if ( position == GPIO_HIGH )
		{ 
			GPIOC_CRH = ( 0x11111111 * mode ) ; 
		}
		break;

	}

}

void GPIO_VoidSetPortValue( u8 gpiox , u8 position , u8 value ){

	switch( gpiox ){

	case GPIOA:

		if  ( position == GPIO_LOW  )
		{ 
			GPIOA_ODR = (GPIOA_ODR & 0xFF00 ) | ( value )  ;
		}
		else if ( position == GPIO_HIGH )
		{ 
			GPIOA_ODR = (GPIOA_ODR & 0x00FF ) | ( value<<8 ) ;
		}

		break;
	case GPIOB:

		if   ( position == GPIO_LOW  )
		{ 
			GPIOB_ODR = (GPIOB_ODR & 0xFF00 ) | ( value ) ;
		}
		else if ( position == GPIO_HIGH )
		{ 
			GPIOB_ODR = (GPIOB_ODR & 0x00FF ) | ( value<<8) ;
		}
		break;
		
	case GPIOC:

		if  ( position == GPIO_LOW  )
		{ 
			GPIOC_ODR = (GPIOC_ODR & 0xFF00 ) | ( value ) ;
		}
		else if ( position == GPIO_HIGH )
		{ 
			GPIOC_ODR = (GPIOC_ODR & 0x00FF ) | ( value<<8 ) ;
		}

		break;

	}

}

