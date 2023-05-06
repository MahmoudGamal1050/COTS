

#include "delay.h"
#include	"Std_Types.h"




void _delay_ms(u32 ticks)
{
	for(u32 i=0;i<(ticks*500);i++)
	{

		asm ("NOP");
	}
}
