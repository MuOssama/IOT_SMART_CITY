/*
 * LCD.h
 *
 *  Created on: Aug 24, 2019
 *      Author: Lenovo
 */

#ifndef LCD_H_
#define LCD_H_
#include "STD_TYPES.h"
#include "BIT_MATH.h"
void LCD_Vinit(void);
void LCD_Send_Command(u8 command);
void LCD_Send_Data(u8 data);
void LCD_Clear(void);
void LCD_Send_string(u8 *ptr);
void LCD_GOTOXY(u8 raw,u8 col);



#endif /* HAL_LCD_LCD_H_ */
