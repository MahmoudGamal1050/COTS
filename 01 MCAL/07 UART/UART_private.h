/************************************************************/
/* Author	:	Mahmoud Gamal								*/
/* Date		: 	16/5/2023									*/
/************************************************************/

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

typedef struct{

	u32 SR;
	u32 DR;
	u32 BRR;
	u32 CR1;
	u32 CR2;
	u32 CR3;
	u32 GTPR;

}UART_t;


#define USART1 ( ( volatile UART_t* ) 0x40013800 )
							   
#define USART2 ( ( volatile UART_t* ) 0x40004400 )
							   
#define USART3 ( ( volatile UART_t* ) 0x40004800 )
							   
#define UART4 (  ( volatile UART_t* ) 0x40004C00 )
							   
#define UART5 (  ( volatile UART_t* ) 0x40005000 )

#endif /* UART_PRIVATE_H_ */
