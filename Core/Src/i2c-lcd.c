/*
 * i2c-lcd.c
 *
 *  Created on: Nov 21, 2024
 *      Author: Admin
 */

/**
Edit by modify: Ngoc Hang
**/

#include "i2c-lcd.h"
extern I2C_HandleTypeDef hi2c1;  // change your handler here accordingly

#define SLAVE_ADDRESS_LCD (0x21 << 1) // change this according to ur setup

void lcd_send_cmd(char cmd)
{
  	char data_u, data_l;
	uint8_t data_t[4];
	data_u = (cmd&0xf0);
	data_l = ((cmd<<4)&0xf0);
	data_t[0] = data_u|0x0C;  //en=1, rs=0
	data_t[1] = data_u|0x08;  //en=0, rs=0
	data_t[2] = data_l|0x0C;  //en=1, rs=0
	data_t[3] = data_l|0x08;  //en=0, rs=0
	HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) data_t, 4, 100);
}

void lcd_send_data(char data)
{
	char data_u, data_l;
	uint8_t data_t[4];
	data_u = (data&0xf0);
	data_l = ((data<<4)&0xf0);
	data_t[0] = data_u|0x0D;  //en=1, rs=0
	data_t[1] = data_u|0x09;  //en=0, rs=0
	data_t[2] = data_l|0x0D;  //en=1, rs=0
	data_t[3] = data_l|0x09;  //en=0, rs=0
	HAL_I2C_Master_Transmit(&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) data_t, 4, 100);
}

void lcd_init(void) {
	lcd_send_cmd (0x33); /* set 4-bits interface */
	lcd_send_cmd (0x32);
	HAL_Delay(50);
	lcd_send_cmd (0x28); /* start to set LCD function */
	HAL_Delay(50);
	lcd_send_cmd (0x01); /* clear display */
	HAL_Delay(50);
	lcd_send_cmd (0x06); /* set entry mode */
	HAL_Delay(50);
	lcd_send_cmd (0x0c); /* set display to on */
	HAL_Delay(50);
	lcd_send_cmd (0x02); /* move cursor to home and set data address to 0 */
	HAL_Delay(50);
	lcd_send_cmd (0x80);

}

void lcd_send_string(char *str)
{
	while (*str) lcd_send_data (*str++);
}

void lcd_clear_display(void)
{
	lcd_send_cmd (0x01); //clear display
	HAL_Delay(50);
}

void lcd_goto_XY (int row, int col)
{
	uint8_t pos_Addr;
		if(row == 0)
		{
			pos_Addr = 0x80 + row + col;
		}
		else
		{
			pos_Addr = 0x80 | (0x40 + col);
		}
		lcd_send_cmd(pos_Addr);
}


void lcd_send_integer(int number) {
    char buffer[3]; // Tạo buffer để chứa chuỗi
    sprintf(buffer, "%2d", number); // Chuyển đổi số nguyên thành chuỗi
    lcd_send_string(buffer); // Gửi chuỗi để hiển thị
}

void lcd_count_down()
{
	if(timer_lcd_flag)
	{
		setTimerLCD(100);
		LCDBuffer[0]--;
		LCDBuffer[1]--;
		if(LCDBuffer[0] <= 0)
		{
			lcd_update_buffer();
		}
		else if(LCDBuffer[1] <= 0)
		{
			LCDBuffer[1] = LCDBuffer[0];
		}
	}
}

void lcd_update_buffer()
{
	LCDBuffer[0] = ledDurationBuffer[0];
	LCDBuffer[1] = ledDurationBuffer[1];
}

void lcd_normal_init()
{
	lcd_goto_XY(0, 0);
	lcd_send_string("HORIZONTAL: ");
	lcd_goto_XY(1, 0);
	lcd_send_string("VERTICAL: ");
}
