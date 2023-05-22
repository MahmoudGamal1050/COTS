/************************************************************/
/* Author	:	Mahmoud Gamal								*/
/* Date		: 	19/5/2023									*/
/************************************************************/

#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

#include	"I2C_interface.h"
#include	"I2C_private.h"
#include	"I2C_config.h"

#include	"GPIO_interface.h"

/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/


void I2C_VoidInit(void)
{
	I2C->CR2 |= 8;
	I2C->CCR |= 40;
	I2C->TRISE |= 9;
	SET_BIT(I2C->CR1,0);
	

}
void I2C_VoidStart(void)
{
	SET_BIT(I2C->CR1,10);
	SET_BIT(I2C->CR1,8);
	while(!GET_BIT(I2C -> SR1,0));
}

void I2C_VoidSendAddress(u8 address)
{
	I2C->DR = address;
	while(!GET_BIT(I2C -> SR1,1));
}

void I2C_voidSendData(u8 data)
{
	while(!GET_BIT(I2C -> SR1,7));  /* wait for TXE bit */
	I2C->DR = data;
	while(!GET_BIT(I2C -> SR1,2));  /* wait for BTF bit*/

}


u8 I2C_U8ReceiveData(void)
{
	while(!GET_BIT(I2C -> SR1,6));
	retuen (I2C->DR);
}


void I2C_Voidstop(void)
{
	SET_BIT(I2C->CR1,9);
}

void I2C_VoidReset(void)
{
	SET_BIT(I2C->CR1,15);	/* reset the I2C*/
	CLR_BIT(I2C->CR1,15);	/* Normal operation*/
}

void I2C_VoidEnable(void)
{
	SET_BIT(I2C->CR1,0);
}
void I2C_VoidDisable(void)
{
	CLR_BIT(I2C->CR1,0);
}
















