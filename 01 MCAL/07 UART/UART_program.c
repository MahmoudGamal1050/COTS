/************************************************************/
/* Author	:	Mahmoud Gamal								*/
/* Date		: 	16/5/2023									*/
/************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_config.h"
#include "UART_private.h"

#define THRESHOLD_VALUE  9000000UL

void (*UART1_CallBack)(void);

void UART_VoidInit( void ) 
{
	u32 mantissa = ( F_CPU ) / ( 16 * UART1_BAUD_RATE ) ;

	u32 fraction = ( ( ( F_CPU * 100 ) / ( 16 * UART1_BAUD_RATE )  ) % 100 ) * 16 ;

	if( fraction > 1500 ){ mantissa += 1 ; fraction  = 0 ; }

	#if UART1_STATUS == UART1_ENABLE

		UART1 -> SR = 0 ;

		#if   UART1_WORD_LENGTH == _8BIT_WORD_LENGTH

					CLR_BIT( UART1 -> CR1 , 12 );

		#elif UART1_WORD_LENGTH == _9BIT_WORD_LENGTH

					SET_BIT( UART1 -> CR1 , 12 );

		#endif

		#if   USART1_PARITY == PARITY_DISABLE

					CLR_BIT( UART1 -> CR1 , 10 );

		#elif UART1_PARITY == EVEN_PARITY

					SET_BIT( UART1 -> CR1 , 10 );
					CLR_BIT( UART1 -> CR1 , 11 );

		#elif UART1_PARITY == ODD_PARITY

					SET_BIT( UART1 -> CR1 , 10 );
					SET_BIT( UART1 -> CR1 , 11 );

		#endif

		#if  UART1_INTERRUPT == INT_DISABLE

					CLR_BIT( UART1 -> CR1 , 5 );
					CLR_BIT( UART1 -> CR1 , 6 );
					CLR_BIT( UART1 -> CR1 , 7 );

		#elif UART1_INTERRUPT == TXE_INT_ENABLE

					SET_BIT( UART1 -> CR1 , 7 );

		#elif UART1_INTERRUPT == TCE_INT_ENABLE

					SET_BIT(UART1);

		#elif UART1_INTERRUPT == RXNE_INT_ENABLE

					SET_BIT( UART1 -> CR1 , 5 );

		#endif

		#if   UART1_TRANSMITTER == TRANSMITTER_ENABLE

					SET_BIT( UART1 -> CR1 , 3 );

		#elif UART1_TRANSMITTER == TRANSMITTER_DISABLE

					CLR_BIT(UART1);

		#endif

		#if   UART1_RECEIVER == RECEIVER_ENABLE

					SET_BIT( UART1 -> CR1 , 2 );

		#elif UART1_RECEIVER == RECEIVER_DISBLE

					CLR_BIT( UART1 -> CR1 , 2 );

		#endif

		#if   UART1_STOP_BITS == ONE_STOP_BIT

					CLR_BIT( UART1 -> CR2 , 12 ); CLR_BIT( UART1 -> CR2 , 13 );

		#elif UART1_STOP_BITS == HALF_STOP_BIT

					SET_BIT( UART1 -> CR2 , 12 ); CLR_BIT( UART1 -> CR2 , 13 );

		#elif UART1_STOP_BITS == TWO_STOP_BIT

					CLR_BIT( UART1 -> CR2 , 12 ); SET_BIT( UART1 -> CR2 , 13 );

		#elif UART1_STOP_BITS == ONE_AND_HALF_STOP_BIT

					SET_BIT(UART1); SET_BIT( UART1 -> CR2 , 13 );


		#endif

		UART1 -> BRR = ( mantissa << 4  ) | (fraction / 100 ) ;
		SET_BIT( UART1 -> CR1 , 13 );

	#elif UART1_STATUS == UART1_DISABLE
		CLR_BIT( UART1 -> CR1 , 0 );

	#endif

}


void UART_VoidSendChar( u8 data  )
{
	UART1 -> DR = data ;

	while( GET_BIT( UART1 -> SR , 6 ) == 0 );

	CLR_BIT( UART1 -> SR , 6 );

}

void UART_VoidSendString( u8 *string ) 
{
	u8 i = 0 ;

	while ( string[ i ] != '\0' ){

		UART_VoidSendChar( string[ i ] );
		i++ ;

	}

}

u8 UART_u8ReceiveChar ( void ){

	u8  data  = 0 ;
	u32 timeOut = 0 ;

	CLR_BIT ( UART1 -> SR, 5);

	while( ( GET_BIT ( UART1 -> SR, 5) == 0 ) && ( timeOut < THRESHOLD_VALUE ) )
	{
		timeOut++;
	}

	if( timeOut == THRESHOLD_VALUE )
	{
		data = 255;
	}
	else
	{

		data = UART1 -> DR;
	}

	return data;

}

u8 String[20];
u8 * UART_ReceiveString ( void ){

	u8 i = 0 , data ;

	while( ( data = UART_u8ReceiveChar() ) != 13 ){

		String[ i ] = data ;
		i++;
	}

	String[i] = '\0';

	return ( String );

}


void UART_VoidSetCallBack( void (*ptr) (void) ){

	UART1_CallBack = ptr ;

}

void USART1_IRQHandler(void){

	UART1 -> SR = 0 ;
	UART1_CallBack();

}
