/************************************************************/
/* Author	:	Mahmoud Gamal								*/
/* Date		: 	6/5/2023									*/
/************************************************************/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H


#define	ADC_CHANNEL1	1
#define	ADC_CHANNEL2	2
#define	ADC_CHANNEL3	3
#define	ADC_CHANNEL4	4
#define	ADC_CHANNEL5	5
#define	ADC_CHANNEL6	6
#define	ADC_CHANNEL7	7
#define	ADC_CHANNEL8	8
#define	ADC_CHANNEL9	9
#define	ADC_CHANNEL10	10


/* Prescaler definition*/
#define PCLK2_DIVIDED_BY_2		0
#define PCLK2_DIVIDED_BY_4		1
#define PCLK2_DIVIDED_BY_6		2
#define PCLK2_DIVIDED_BY_8		3

#define	ENABLE					1
#define	DIABLE					0

void ADC_Init (void);
void TempSensor_init(void);
void ADC_Enable (void);
void ADC_Start(void);
u32* ADC_Read(void);


#endif /* ADC_INTERFACE_H */
