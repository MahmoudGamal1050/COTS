#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"GPIO_interface.h"
#include 	"SevenSegment.h"

/* array of 7-segment numbers 0:9*/
const u8 numbers[]={

			0b0111111,		
			0b0000110,
			0b1011011,
			0b1001111,
			0b1100110,
			0b1101101,
			0b1111101,
			0b0000111,
			0b1111111,
			0b1101111};
			
void SevenSegment(u8 gpiox,position, u8 num )
{
	GPIO_VidSetPortMode( gpiox , position , GPIO_OUTPUT_2MHZ_PP );
	GPIO_VidSetPortValue( gpiox , position , numbers[num] );

	
}

	



