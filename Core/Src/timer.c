/*
 * timer.c
 *
 *  Created on: Nov 19, 2024
 *      Author: Admin
 */

/*
 * timer.c
 *
 *  Created on: Sep 29, 2024
 *      Author: Admin
 */
#include "timer.h"

int timer_horizontal_flag = 0;
int timer_vertical_flag = 0;
int timer_blinky_led_flag = 0;
int timer_lcd_flag = 0;
int timer_lcd_v_flag = 0;


int timer_counter_horizontal = 0;
int timer_counter_vertical = 0;
int timer_counter_blinky = 0;
int timer_counter_lcd = 0;
int timer_counter_lcd_v = 0;

void setTimerVertical(int duration)
{
	timer_vertical_flag = 0;
	timer_counter_vertical = duration;
}
void setTimerHorizontal(int duration)
{
	timer_horizontal_flag = 0;
	timer_counter_horizontal = duration;
}

void setTimerBlinky(int duration)
{
	timer_blinky_led_flag = 0;
	timer_counter_blinky = duration;
}

void setTimerLCD(int duration)
{
	timer_lcd_flag = 0;
	timer_counter_lcd = duration;
}
void setTimerLcdV(int duration)
{
	timer_lcd_v_flag = 0;
	timer_counter_lcd_v = duration;
}


void timerRun()
{
	if(timer_counter_lcd_v > 0)
	{
		timer_counter_lcd_v--;
		if(timer_counter_lcd_v <= 0)
		{
			timer_lcd_v_flag = 1;
		}
	}
	if(timer_counter_vertical > 0)
	{
		timer_counter_vertical--;
		if(timer_counter_vertical <= 0)
		{
			timer_vertical_flag = 1;
		}
	}
	if(timer_counter_horizontal > 0)
	{
		timer_counter_horizontal--;
		if(timer_counter_horizontal <= 0)
		{
			timer_horizontal_flag = 1;
		}
	}

	if(timer_counter_blinky > 0)
	{
		timer_counter_blinky--;
		if(timer_counter_blinky <= 0)
		{
			timer_blinky_led_flag = 1;
		}
	}

	if(timer_counter_lcd > 0)
	{
		timer_counter_lcd--;
		if(timer_counter_lcd <= 0)
		{
			timer_lcd_flag = 1;
		}
	}
}
