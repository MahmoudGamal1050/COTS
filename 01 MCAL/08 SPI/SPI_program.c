
#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

#include	"SPI_interface.h"
#include	"SPI_private.h"
#include	"SPI_config.h"

#include	"GPIO_interface.h"

/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/

void (*SPI1_CallBack)(u8);
void SPI1_voidInit(void){
	
#if   SPI1_STATUS == SPI_ENABLE

#if		SPI1_CLOCK_MODE == SPI_MODE0

	CLR_BIT( SPI1 -> CR1 , 0 ); CLR_BIT( SPI1 -> CR1 , 1 );

#elif	SPI1_CLOCK_MODE == SPI_MODE1

	SET_BIT( SPI1 -> CR1 , 0 ); CLR_BIT( SPI1 -> CR1 , 1 );

#elif	SPI1_CLOCK_MODE == SPI_MODE2

	CLR_BIT( SPI1 -> CR1 , 0 ); SET_BIT( SPI1 -> CR1 , 1 );

#elif	SPI1_CLOCK_MODE == SPI_MODE3

	SET_BIT( SPI1 -> CR1 , 0 ); SET_BIT( SPI1 -> CR1 , 1 );

#endif

#if    SPI1_MASTER_SLAVE == SPI_MASTER

	SET_BIT( SPI1 -> CR1 , 2 );

#elif  SPI1_MASTER_SLAVE == SPI_SLAVE

	CLR_BIT( SPI1 -> CR1 , 2 );

#endif

#if   SPI1_DATA_ORDER == SPI_MSB_FIRST

	CLR_BIT( SPI1 -> CR1 , 7 );

#elif SPI1_DATA_ORDER == SPI_LSB_FIRST

	SET_BIT( SPI1 -> CR1 , 7 );

#endif

#if   SPI1_SS_MANAGE  == HW_SLAVE_SELECT

	CLR_BIT( SPI1 -> CR1 , 9 );

#elif SPI1_SS == SW_SS

	SET_BIT( SPI1 -> CR1 , 9 );

#endif

#if   SPI1_DATA_SIZE == SPI_8BIT_DATA

	CLR_BIT( SPI1 -> CR1 , 11 );

#elif SPI1_DATA_SIZE == SPI_16BIT_DATA

	SET_BIT( SPI1 -> CR1 , 11 );

#endif

#if   SPI1_INT_STATUS == SPI_INT_DISABLE

	SPI1 -> CR2 = 0 ;

#elif SPI1_INT_STATUS == SPI_TXE_INT_ENABLE

	SET_BIT( SPI1 -> CR2 , 7 );

#elif SPI1_INT_STATUS == SPI_RXNE_INT_ENABLE

	SET_BIT( SPI1 -> CR2 , 6 );

#endif

	SPI1 -> CR1 &= 0xFFC7 ;
	SPI1 -> CR1 |= ( SPI1_PRESCALLER << 3 ) ;

	SET_BIT( SPI1 -> CR1 , 6 );

#elif SPI1_STATUS == SPI_DISABLE
	CLR_BIT( SPI1 -> CR1 , 6 );
#endif
	
	
}

u8 SPI1_voidSendReciveByte(u8 TXData)
{
	u8 RXData;
	/* Slave Select=low*/
	GPIO_voidSetPinValue(SLAVE_SELECT,GPIO_LOW);
	/* Send data*/
	SPI1->DR=TXData;
	/* Wait on Busy Flag*/
	while(GET_BIT(SPI1->SR,7)==1);
	/*Return Data*/
	RXData = SPI1->DR;
		/* Slave Select=HIGH*/
	GPIO_voidSetPinValue(SLAVE_SELECT,GPIO_HIGH);
	return RXData;
	
	
}



void SPI1_voidSendReciveByteAsync(u8 TXData,void (*ptr) (u8))
{
	SPI1_CallBack = ptr;
	GPIO_voidSetPinValue(SLAVE_SELECT,GPIO_LOW);
	/* Send data*/
	SPI1->DR=TXData;

}

void SPI1_IRQHandler(void)
{

	SPI1_CallBack(SPI1->DR);
	GPIO_voidSetPinValue(SLAVE_SELECT,GPIO_HIGH);


}






















