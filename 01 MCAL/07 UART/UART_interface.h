/************************************************************/
/* Author	:	Mahmoud Gamal								*/
/* Date		: 	16/5/2023									*/
/************************************************************/

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


#define UART1_DISABLE          0
#define UART1_ENABLE           1

#define _8BIT_WORD_LENGTH       0
#define _9BIT_WORD_LENGTH       1

#define PARITY_DISABLE          0
#define EVEN_PARITY             1
#define ODD_PARITY              2

#define INT_DISABLE             0
#define TXE_INT_ENABLE          1
#define TCE_INT_ENABLE          3
#define RXNE_INT_ENABLE         5

#define TRANSMITTER_DISABLE     0
#define TRANSMITTER_ENABLE      1

#define RECEIVER_DISBLE         0
#define RECEIVER_ENABLE         1

#define ONE_STOP_BIT            0
#define HALF_STOP_BIT           1
#define TWO_STOP_BIT            2
#define ONE_AND_HALF_STOP_BIT   3


void UART_VoidInit( void ) ;
void UART_VoidSendChar( u8 data  ) ;
void UART_VoidSendString( u8 *string ) ;
u8   UART_u8ReceiveChar( void ) ;
u8 * UART_ReceiveString( void ) ;
void UART_VoidSetCallBack( void (*ptr) (void)  ) ;

#endif /* USART_INTERFACE_H_ */
