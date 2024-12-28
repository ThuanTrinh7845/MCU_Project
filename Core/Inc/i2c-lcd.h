/*
 * i2c-lcd.h
 *
 *  Created on: Nov 21, 2024
 *      Author: Admin
 */

#ifndef INC_I2C_LCD_H_
#define INC_I2C_LCD_H_

/**
Edit by modify: Ngoc Hang
**/

#include "stm32f1xx_hal.h"
#include "stdio.h"
#include "global.h"

void lcd_init (void);   // initialize lcd

void lcd_send_cmd (char cmd);  // send command to the lcd

void lcd_send_data (char data);  // send data to the lcd

void lcd_send_string (char *str);  // send string to the lcd

void lcd_clear_display (void);	//clear display lcd

void lcd_goto_XY (int row, int col); //set proper location on screen

void lcd_send_integer(int number);

void lcd_count_down();

void lcd_update_buffer();

void lcd_normal_init();
#endif /* INC_I2C_LCD_H_ */
