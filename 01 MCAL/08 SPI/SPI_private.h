

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

typedef  struct{
	u32 CR1;
	u32 CR2;
	u32 SR;
	u32 DR;
	u32 CRCPR;
	u32 RXCRCR;
	u32 TXCRCR;
	u32 I2SCFGR;	
	u32 I2SPR;
}SPI_t;

#define SPI1 (( volatile SPI_t* ) 0x40013000 )



#endif
