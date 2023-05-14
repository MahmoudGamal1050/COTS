#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DMA_private.h"
#include "DMA_interface.h"

void ( *CallBackChannel1 )( void );

void DMA1_VoidSetConfiguration( u8 ChannelNum , u8 Direction , u8 Circualation , u8 MINC ,
		u8 PINC , u8 MEMSize , u8 PERSize , u8 ChannelPriority ){

	/* Disable DMA */
	CLR_BIT( DMA1->Channel[ ChannelNum ].CCR , 0 );
	
	// Wait Until DMA Disable
	//while( GET_BIT( DMA1->Channel[ ChannelNum ].CCR , 0 ) == 1 );

	/* Configure Direction */
	switch(Direction)
	{
		case MEM2MEM :	SET_BIT( DMA1->Channel[ ChannelNum ].CCR , 14 ); break;
		case PER2MEM :	CLR_BIT( DMA1->Channel[ ChannelNum ].CCR , 4  ); break;
		case MEM2PER :	SET_BIT( DMA1->Channel[ ChannelNum ].CCR , 4  ); break;
	}
	
	/* Circulation */
	switch(Direction)
	{
		case CIRCULAR_EN  :	SET_BIT( DMA1->Channel[ ChannelNum ].CCR , 5  ); break;
		case CIRCULAR_DIS :	CLR_BIT( DMA1->Channel[ ChannelNum ].CCR , 5  ); break;
	}
	
	/* MINC */
	switch(MINC)
	{
		case MEM_INC_EN  :	SET_BIT( DMA1->Channel[ ChannelNum ].CCR , 7  ); break;
		case MEM_INC_DIS :	CLR_BIT( DMA1->Channel[ ChannelNum ].CCR , 7  ); break;
	}
	
	/* PINC */
	switch(PINC)
	{
		case PER_INC_EN  :	SET_BIT( DMA1->Channel[ ChannelNum ].CCR , 6  ); break;
		case PER_INC_DIS :	CLR_BIT( DMA1->Channel[ ChannelNum ].CCR , 6  ); break;
	}
	
	/* MEMORY SIZE */
	switch(MEMSize)
	{
		case BYTE  		:	CLR_BIT( DMA1->Channel[ ChannelNum ].CCR , 10 );
							CLR_BIT( DMA1->Channel[ ChannelNum ].CCR , 11 ); 
							break;
		case TWO_BYTES	:	SET_BIT( DMA1->Channel[ ChannelNum ].CCR , 10 );
							CLR_BIT( DMA1->Channel[ ChannelNum ].CCR , 11 );
							break;
		case FOUR_BYTES	:	CLR_BIT( DMA1->Channel[ ChannelNum ].CCR , 10 );
							SET_BIT( DMA1->Channel[ ChannelNum ].CCR , 11 );
							break;					
	}
	
	/*  PERIPHERAL SIZE */
	switch(PERSize)
	{
		case BYTE  		:	CLR_BIT( DMA1->Channel[ ChannelNum ].CCR , 8 );
							CLR_BIT( DMA1->Channel[ ChannelNum ].CCR , 9 ); 
							break;
		case TWO_BYTES	:	SET_BIT( DMA1->Channel[ ChannelNum ].CCR , 8 );
							CLR_BIT( DMA1->Channel[ ChannelNum ].CCR , 9 );
							break;
		case FOUR_BYTES	:	CLR_BIT( DMA1->Channel[ ChannelNum ].CCR , 8 );
							SET_BIT( DMA1->Channel[ ChannelNum ].CCR , 9 );
							break;					
	}

	/* CHANNEL PRIORITY */
	switch(ChannelPriority)
	{
		case LOW  		:	CLR_BIT( DMA1->Channel[ ChannelNum ].CCR , 12 );
							CLR_BIT( DMA1->Channel[ ChannelNum ].CCR , 13 ); 
							break;                                     
		case MEDIUM		:	SET_BIT( DMA1->Channel[ ChannelNum ].CCR , 12 );
							CLR_BIT( DMA1->Channel[ ChannelNum ].CCR , 13 );
							break;                                     
		case HIGH		:	CLR_BIT( DMA1->Channel[ ChannelNum ].CCR , 12 );
							SET_BIT( DMA1->Channel[ ChannelNum ].CCR , 13 );
							break;                                     
		case VERY_HIGH	:	SET_BIT( DMA1->Channel[ ChannelNum ].CCR , 12 );
							SET_BIT( DMA1->Channel[ ChannelNum ].CCR , 13 );
							break;
	}
	
	

}



void DMA1_voidInerruptEnable( u8 ChannelNum , u8 INTSource ){

	SET_BIT( DMA1->Channel[ ChannelNum ].CCR , INTSource );

}



void	DMA1_voidStartChannel(u32 * SrcAdd,u32 * DestAdd,u16 BlockLength)
{
	/*		Make Sure that the channel is  disabled */
	CLR_BIT(DMA1 -> Channel[0].CCR,0);
	
	DMA1 -> Channel[0].CPAR	=	(u32)SrcAdd;
	DMA1 -> Channel[0].CMAR	=	(u32)DestAdd;
	
	/*	Load the Block Length				*/
	DMA1 -> Channel[0].CNDTR	=	BlockLength;

	/*		Make Sure that the channel is  Enabled to strat transfere*/
	SET_BIT(DMA1 -> Channel[0].CCR,0);	
}




void DMA1_voidSetCallBackChannel1( void ( *Ptr ) ( void ) ){

	CallBackChannel1 = Ptr ;

}

void DMA1_Channel1_IRQHandler(void){

	CallBackChannel1();
	/* Clear CGIF */
	SET_BIT( DMA1->IFCR , 0) ;


}
