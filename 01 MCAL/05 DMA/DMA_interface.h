/************************************************************/
/* Author	:	Mahmoud Gamal								*/
/* Date		: 	6/5/2023									*/
/************************************************************/

#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H




//DMA CHANNELS
#define CHANNEL1  0
#define CHANNEL2  1
#define CHANNEL3  2
#define CHANNEL4  3
#define CHANNEL5  4
#define CHANNEL6  5
#define CHANNEL7  6


/* Direction */
#define MEM2MEM   0
#define PER2MEM   1
#define MEM2PER   2

/* Circulation */
#define CIRCULAR_EN  0
#define CIRCULAR_DIS 1

/* MINC */
#define MEM_INC_EN  0
#define MEM_INC_DIS 1

/* PINC */
#define PER_INC_EN  0
#define PER_INC_DIS 1

/* Size */
#define BYTE      		 0
#define TWO_BYTES  	     1
#define FOUR_BYTES       2

/* Channel Priority */
#define LOW         0
#define MEDIUM      1
#define HIGH        2
#define VERY_HIGH   3

/* Interrupt Sources  */
#define TCIE  1
#define HTIE  2
#define TEIE  3

//DMA Flags
#define GIF   0
#define TCIF  1
#define HTIF  2
#define TEIF  3



void DMA1_VoidSetConfiguration( u8 ChannelNum , u8 Direction , u8 Circualation , u8 MINC ,
							   u8 PINC    , u8 MEMSize   , u8 PERSize      	  , u8 ChannelPriority );
							   
void DMA1_voidInerruptEnable( u8 Channel , u8 INTSource );
void DMA1_voidStartChannel(u32 * SrcAdd,u32 * DestAdd,u16 BlockLength);

void DMA1_voidSetCallBackChannel1( void ( *Ptr ) ( void ) );


#endif /* DMA_INTERFACE_H */
