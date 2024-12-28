/*
 * input_processing.c
 *
 *  Created on: Oct 23, 2024
 *      Author: Admin
 */

#include "fsm_manual.h"

int temp_red = 0, temp_green= 0, temp_yellow = 0;
int blink_led = 0;

void fsm_manual_init(void)
{

	setTimerHorizontal(-1);
	setTimerVertical(-1);
	lcd_clear_display();
	setTimerLCD(-1);
	setTimerBlinky(5);
}
void fsm_manual_run(void)
{
	switch(statusHorizontal)
	{
		case MAN_RED_IN_HORIZONTAL:

			if (temp_red > 99)
			{
				temp_red = 0;
			}
			lcd_goto_XY(0, 0);
			lcd_send_string("MAN_RED: ");
			lcd_goto_XY(0, 9);
			lcd_send_integer(temp_red);
			if(timer_blinky_led_flag == 1)
			{
				setTimerBlinky(25);
				switch (blink_led)
				{
					case 0:
						blink_led = 1;
						turnOffLEDAll();
						break;
					case 1:
						blink_led = 0;
						HAL_GPIO_WritePin(D9_GPIO_Port, D9_Pin, SET);
						HAL_GPIO_WritePin(D10_GPIO_Port, D10_Pin, SET);

						HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, SET);
						HAL_GPIO_WritePin(D8_GPIO_Port, D8_Pin, SET);

						HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
						HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, SET);

						HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);
						HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
				}
			}
			if(is_button_pressed(0))
			{
				setTimerBlinky(25);
				lcd_clear_display();
				statusHorizontal = MAN_GREEN_IN_HORIZONTAL;
			}
			if(is_button_pressed(1))
			{
				lcd_clear_display();
				temp_red++;
			}
			if(is_button_pressed(2))
			{
				ledDurationBuffer[0] = temp_red;
				temp_red = 0;
			}
			break;
		case MAN_GREEN_IN_HORIZONTAL:
			if (temp_green > 99)
			{
				temp_green = 0;
			}
			lcd_goto_XY(0, 0);
			lcd_send_string("MAN_GREEN: ");
			lcd_goto_XY(0, 11);
			lcd_send_integer(temp_green);
			if(timer_blinky_led_flag == 1)
			{
				setTimerBlinky(25);
				switch (blink_led)
				{
					case 0:
						blink_led = 1;
						turnOffLEDAll();
						break;
					case 1:
						blink_led = 0;
						HAL_GPIO_WritePin(D9_GPIO_Port, D9_Pin, 1);
						HAL_GPIO_WritePin(D10_GPIO_Port, D10_Pin, 0);

						HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, 1);
						HAL_GPIO_WritePin(D8_GPIO_Port, D8_Pin, 0);

						HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, 1);
						HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, 0);

						HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, 1);
						HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, 0);
				}
			}
			if(is_button_pressed(0))
			{
				setTimerBlinky(25);
				lcd_clear_display();
				statusHorizontal = MAN_YELLOW_IN_HORIZONTAL;
			}
			if(is_button_pressed(1))
			{
				lcd_clear_display();
				temp_green++;
			}
			if(is_button_pressed(2))
			{
				ledDurationBuffer[1] = temp_green;
				temp_green = 0;
			}
			break;
		case MAN_YELLOW_IN_HORIZONTAL:
			if (temp_yellow > 99)
			{
				temp_yellow = 0;
			}
			lcd_goto_XY(0, 0);
			lcd_send_string("MAN_YELLOW: ");
			lcd_goto_XY(0, 11);
			lcd_send_integer(temp_yellow);
			if(timer_blinky_led_flag == 1)
			{
				setTimerBlinky(25);
				switch (blink_led)
				{
					case 0:
						blink_led = 1;
						turnOffLEDAll();
						break;
					case 1:
						blink_led = 0;
						HAL_GPIO_WritePin(D9_GPIO_Port, D9_Pin, 0);
						HAL_GPIO_WritePin(D10_GPIO_Port, D10_Pin, 1);

						HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, 0);
						HAL_GPIO_WritePin(D8_GPIO_Port, D8_Pin, 1);

						HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, 0);
						HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, 1);

						HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, 0);
						HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, 1);
				}
			}
			if(is_button_pressed(0))
			{
				lcd_clear_display();
				statusHorizontal = INIT;
				statusVertical = INIT;
			}
			if(is_button_pressed(1))
			{
				lcd_clear_display();
				temp_yellow++;
			}
			if(is_button_pressed(2))
			{
				ledDurationBuffer[2] = temp_yellow;
				temp_yellow = 0;
			}
			break;
		default:
			break;
	}
}
