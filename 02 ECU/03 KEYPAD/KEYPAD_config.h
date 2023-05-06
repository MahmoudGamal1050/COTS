 /******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: keypad.h
 *
 * Description: Header file for the Keypad driver
 *
 * Author: Mahmoud Gamal
 *
 *******************************************************************************/



/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/*****Keypad configuration of rows and columns*/
#define N_col 4
#define N_row 4

/*Keypad Port Configuration*/

#define KEYPAD_PORT GPIOA


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
u8 getPressedKey(void);


#endif /* KEYPAD_H_ */
