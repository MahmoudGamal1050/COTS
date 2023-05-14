/************************************************************/
/* Author	:	Mahmoud Gamal								*/
/* Date		: 	6/5/2023									*/
/************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_private.h"
#include "AFIO_interface.h"

void AFIO_VoidSetEXTIConfig( u8 Line , u8 Port ){

	u8 Index = Line/4;
	Line %= 4;

	AFIO->EXTICRx[Index] &= ~ ( ( 0b1111 ) << ( Line * 4 ));
	AFIO->EXTICRx[Index] |= ( Port ) << ( Line * 4 );

}
