/************************************************************/
/* Author	:	Mahmoud Gamal								*/
/* Date		: 	19/5/2023									*/
/************************************************************/

#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

typedef struct{
	u32	CR1;
	u32	CR2;
	u32	OAR1;
	u32	OAR2;
	u32	DR;
	u32	SR1;
	u32	SR2;
	u32	CCR;
	u32	TRISE;
}I2C_t;



#define I2C  ((volatile I2C_t *)(0x40013000))


#endif
