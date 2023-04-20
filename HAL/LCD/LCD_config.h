/*
 * LCD_config.h
 *
 *  Created on: Apr 9, 2023
 *      Author: yasmi
 */

#ifndef HAL_LCD_CONFIG_H_
#define HAL_LCD_CONFIG_H_

#define LCD PORTA
#define LCD_DDR DDRA
#define LCD_CTRL_DDR DDRB

#define LCD_PRT PORTA

#define LCD_D0 4
#define LCD_D1 5
#define LCD_D2 6
#define LCD_D3 7

#define LCD_D4 4
#define LCD_D5 5
#define LCD_D6 6
#define LCD_D7 7

#define LCD_CTRL_PRT PORTB

#define LCD_Rs 1
#define LCD_Rw 2
#define LCD_E 3


#endif /* HAL_LCD_CONFIG_H_ */
