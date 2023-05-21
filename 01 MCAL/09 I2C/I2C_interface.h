/************************************************************/
/* Author	:	Mahmoud Gamal								*/
/* Date		: 	19/5/2023									*/
/************************************************************/


#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H


#define		READ							0
#define		WRITE							1

#define		ENABLED							0
#define		DISABLED						1

void I2C_VoidInit(void);
void I2C_VoidStart(void);
void I2C_VoidSendAddress(u8 address);
void I2C_voidSendData(u8 data);
u8 I2C_U8ReceiveData(void);
void I2C_Voidstop(void);
void I2C_VoidDisable(void);
void I2C_VoidReset(void);
void I2C_VoidEnable(void);


#endif 
