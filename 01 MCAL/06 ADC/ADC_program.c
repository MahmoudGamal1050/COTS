#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_private.h"
#include "ADC_private.h"
#include "ADC_interface.h"
#include "ADC_config.h"


void ADC_Init (void)
{
	

/* Set the prescalar in the Clock configuration register (RCC_CFGR)*/
	RCC_CFGR |= (PRESCALAR<<14);

/* Set the Scan Mode and Resolution in the Control Register 1 (CR1)*/
	ADC->CR1 = (1<<8);   

/* Set the Continuous Conversion*/
	ADC->CR2 = (CONTINOUS_MODE<<1);
/* External Event selection pointed to SWSTART bit*/
	ADC->CR2 |= (7<<17);  
/*Data Alignment RIGHT*/
	ADC->CR2 &= ~(1<<11);   

/* Set the Sampling Time for the channels(1.5 cycles)*/
	ADC->SMPR2 &= ~(7<<((CHANNEL_NUM-1)*3)); 

/*Set the Regular channel sequence length in ADC_SQR1*/
	ADC->SQR1 |= (CONVERSIONS_NUMBER<<20);
	ADC->SQR3 |= (CHANNEL_NUM<<0);  // SEQ1 for Channel 1


}

	/**************************************************************************************************/

void TempSensor_init(void)
{
	/* Sampling Freq for Temp Sensor*/
	ADC->SMPR1 |= (7<<18);  

	/* Set the TSVREFE Bit to wake the sensor*/
	ADC->CR2 |= (1<<23);

	/* Enable DMA for ADC*/
	ADC->CR2 |= (1<<8);



}


void ADC_Enable (void)
{
	/* ADON =1 enable ADC1*/
	ADC->CR2 |= 1<<0;   
	/*Wait for ADC to stabilize	*/
	u32 delay = 10000;
	while (delay--);
}

void ADC_Start(void)
{

	/* Clear Status register*/
	ADC->SR = 0; 
	/*Conversion on external event enabled	*/
	ADC->CR2 |= (1<<20); 
	/*Start conversion*/
	ADC->CR2 |= 1<<22;                
}

u32* ADC_Read(void)
{


	return &ADC->DR;
}
