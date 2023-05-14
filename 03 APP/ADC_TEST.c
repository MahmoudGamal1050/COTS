/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mahmoud Gamal
 * @brief          : Main program body
 ******************************************************************************/


#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

#include	"RCC_interface.h"
#include	"GPIO_interface.h"
#include	"NVIC_interface.h"
#include 	"STK_interface.h"
#include 	"DMA_interface.h"
#include 	"ADC_interface.h"


u16 RxData[3]={1,2,3};

float Temperature;


int main(void)
{
	/*Enable System Clock*/
	RCC_voidSysClkInt();
	/*Enable RCC FOR DM1*/
	RCC_voidEnablePerClk(RCC_AHB, DMA1_RCC);
	/* Enable RCC for ADC and GPIOA*/
	RCC_voidEnablePerClk(RCC_APB2, ADC1_RCC);
	RCC_voidEnablePerClk(RCC_APB2,GPIOA_RCC);
	/* Set A1 in the Analog Mode*/
	GPIO_voidSetPinMode(GPIOA, PIN1, GPIO_INPUT_ANALOG);
	/*Enable SYSTICK*/
	STK_voidInit();
	/* Initialize ADC and internal temperature sensor*/
	ADC_Init ();
	TempSensor_init();
	ADC_Enable ();

	/*Configure DMA to transfer 16-bit circularly from ADC to RxData */
	DMA1_VoidSetConfiguration(CHANNEL1, PER2MEM, CIRCULAR_EN, MEM_INC_EN, PER_INC_DIS, TWO_BYTES, TWO_BYTES, VERY_HIGH);
	DMA1_voidStartChannel((u32*)ADC_Read(), (u32*) RxData, 3);


	/*Start Conversion*/
	ADC_Start ();

	while (1)
	{
		Temperature = ((1.43 - ((float)(3.3*RxData[2]/(float)4095))) / 0.0043) + 25;

		STK_voidSetBusyWait(1000000);
	}

	}
