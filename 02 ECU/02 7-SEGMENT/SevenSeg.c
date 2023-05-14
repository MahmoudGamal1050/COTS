#include	"STD_TYPES.h"
#include	"BIT_MATH.h"
#include    "GPIO_interface.h"
#include 	"SevenSeg.h"


void SevenSeg_init(void){
	GPIO_voidSetPinMode(GPIOA, A, GPIO_OUTPUT_2MHZ_PP);
	GPIO_voidSetPinMode(GPIOA, B, GPIO_OUTPUT_2MHZ_PP);
	GPIO_voidSetPinMode(GPIOB, C, GPIO_OUTPUT_2MHZ_PP);
	GPIO_voidSetPinMode(GPIOB, D, GPIO_OUTPUT_2MHZ_PP);
	GPIO_voidSetPinMode(GPIOB, E, GPIO_OUTPUT_2MHZ_PP);
	GPIO_voidSetPinMode(GPIOB, F, GPIO_OUTPUT_2MHZ_PP);
	GPIO_voidSetPinMode(GPIOA, G, GPIO_OUTPUT_2MHZ_PP);
    GPIO_voidSetPinMode(GPIOA, H, GPIO_OUTPUT_2MHZ_PP);
}

void Sevenseg_write(u8 number) {
	switch(number){
		case 0 :  	
			GPIO_voidSetPinValue(GPIOA, A, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOA, B, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOB, C, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOB, D, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOB, E, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOB, F, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOA, G, GPIO_LOW);

			break ;
			
		case 1 :  	
			GPIO_voidSetPinValue(GPIOA, A, GPIO_LOW);
			GPIO_voidSetPinValue(GPIOA, B, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOB, C, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOB, D, GPIO_LOW);
			GPIO_voidSetPinValue(GPIOB, E, GPIO_LOW);
			GPIO_voidSetPinValue(GPIOB, F, GPIO_LOW);
			GPIO_voidSetPinValue(GPIOA, G, GPIO_LOW);

			break ;
		case 2 :  	
			GPIO_voidSetPinValue(GPIOA, A, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOA, B, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOB, C, GPIO_LOW);
			GPIO_voidSetPinValue(GPIOB, D, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOB, E, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOB, F, GPIO_LOW);
			GPIO_voidSetPinValue(GPIOA, G, GPIO_HIGH);

			break ;
		case 3 :  	
			GPIO_voidSetPinValue(GPIOA, A, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOA, B, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOB, C, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOB, D, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOB, E, GPIO_LOW);
			GPIO_voidSetPinValue(GPIOB, F, GPIO_LOW);
			GPIO_voidSetPinValue(GPIOA, G, GPIO_HIGH);

			break ;
		case 4 :  	
			GPIO_voidSetPinValue(GPIOA, A, GPIO_LOW);
			GPIO_voidSetPinValue(GPIOA, B, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOB, C, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOB, D, GPIO_LOW);
			GPIO_voidSetPinValue(GPIOB, E, GPIO_LOW);
			GPIO_voidSetPinValue(GPIOB, F, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOA, G, GPIO_HIGH);

			break ;
		case 5 :  	
			GPIO_voidSetPinValue(GPIOA, A, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOA, B, GPIO_LOW);
			GPIO_voidSetPinValue(GPIOB, C, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOB, D, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOB, E, GPIO_LOW);
			GPIO_voidSetPinValue(GPIOB, F, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOA, G, GPIO_HIGH);

			break ;
		case 6 :  	
			GPIO_voidSetPinValue(GPIOA, A, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOA, B, GPIO_LOW);
			GPIO_voidSetPinValue(GPIOB, C, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOB, D, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOB, E, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOB, F, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOA, G, GPIO_HIGH);

			break ;
		case 7 :  	
			GPIO_voidSetPinValue(GPIOA, A, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOA, B, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOB, C, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOB, D, GPIO_LOW);
			GPIO_voidSetPinValue(GPIOB, E, GPIO_LOW);
			GPIO_voidSetPinValue(GPIOB, F, GPIO_LOW);
			GPIO_voidSetPinValue(GPIOA, G, GPIO_LOW);

			break ;
		case 8 :  	
			GPIO_voidSetPinValue(GPIOA, A, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOA, B, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOB, C, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOB, D, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOB, E, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOB, F, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOA, G, GPIO_HIGH);

			break ;
		case 9 :  	
			GPIO_voidSetPinValue(GPIOA, A, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOA, B, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOB, C, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOB, D, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOB, E, GPIO_LOW);
			GPIO_voidSetPinValue(GPIOB, F, GPIO_HIGH);
			GPIO_voidSetPinValue(GPIOA, G, GPIO_HIGH);

			break ;
		
	}
}