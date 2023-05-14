/************************************************************/
/* Author	:	Mahmoud Gamal								*/
/* Date		: 	6/5/2023									*/
/************************************************************/
#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

typedef struct{

	u32 CCR       ;
	u32 CNDTR     ;
	u32 CPAR      ;
	u32 CMAR      ;
	u32 RESERVED  ;

}DMA_Channel;

typedef struct{

	u32 ISR  ;
	u32 IFCR ;
	DMA_Channel Channel[7];

}DMA_t;

#define 	DMA1 	( ( volatile DMA_t * ) 0x40020000 )


#endif /* DMA_private_H_ */
