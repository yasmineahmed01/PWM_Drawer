/*
 * LCD_int.h
 *
 *  Created on: Apr 9, 2023
 *      Author: yasmi
 */

#ifndef HAL_LCD_INT_H_
#define HAL_LCD_INT_H_

#include "avr/io.h"
#include "LCD_config.h"


void LCD_Init();
void LCD_Write_Command(uint8_t command);
void LCD_Write_Character(uint8_t character);
void LCD_Write_String(uint8_t* str);
void LCD_Write_Number(uint32_t number);
void LCD_Clear();



#endif /* HAL_LCD_INT_H_ */
