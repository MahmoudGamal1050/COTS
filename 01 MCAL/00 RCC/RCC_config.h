 /******************************************************************************
 * File Name: RCC_config.h
 *
 * Description: this file configures the RCC
 *
 * Author : Mahmoud Gamal
 *******************************************************************************/




#ifndef		RCC_CONFIG_H
#define		RCC_CONFIG_H

/******************************************************************
*                                                                 
*  RCC_SYS_CLK :							     		 
*			1- HSI					             						
*			2- HSE_
*			3- HSE_BYPASS					       
*			4- PLL 							 
*				4.1- PLL_HSI_DIVIDED_BY_2       	 
*                       4.2- PLL_HSE                     	 
*                       4.3- PLL_HSE_DIVIDED_BY_2	 		                                 
*                                        				 
*                                                                 
*******************************************************************/
#define	RCC_SYS_CLK		HSI

#if RCC_SYS_CLK = PLL 
#define 	RCC_PLL_SRC		PLL_HSE
#define RCC_PLL_MUL_FACTOR    2         /* RCC_PLL_MUL_FACTOR : 2:16 */
#endif




#endif