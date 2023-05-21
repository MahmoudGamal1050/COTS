/************************************************************/
/* Author	:	Mahmoud Gamal								*/
/* Date		: 	16/5/2023									*/
/************************************************************/
#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

/* System Clock */

#define F_CPU                    8000000UL

/* USART1_Configuration */

#define UART1_STATUS           	UART1_ENABLE
#define UART1_BAUD_RATE         (u32)9600

#define UART1_WORD_LENGTH       _8BIT_WORD_LENGTH
#define UART1_PARITY            PARITY_DISABLE
#define UART1_INTERRUPT         INT_DISABLE

#define UART1_TRANSMITTER       TRANSMITTER_ENABLE
#define UART1_RECEIVER          RECEIVER_ENABLE

#define UART1_STOP_BITS         ONE_STOP_BIT

#endif /* UART_CONFIG_H_ */
