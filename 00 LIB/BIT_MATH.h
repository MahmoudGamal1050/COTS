 /******************************************************************************
 *
 * Module: Common - Macros 
 *
 * File Name: BIT_MATH.h
 *
 * Description: Commonly used Macros for bit manipulation
 *
 * Author : Mahmoud Gamal
 *******************************************************************************/


#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(REG , BIT) REG |= (1 << (BIT))
#define CLR_BIT(REG , BIT) REG &= ~(1 << (BIT))
#define TOG_BIT(REG , BIT) REG ^= (1 << BIT)
#define GET_BIT(REG , BIT) ( (REG >> BIT) & 1 )



#endif /* BIT_MATH_H_ */
