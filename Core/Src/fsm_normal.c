/*
 * fsm_normal.c
 *
 *  Created on: Nov 19, 2024
 *      Author: Admin
 */

#include "fsm_normal.h"

int v_red, v_green, v_yellow;


void fsm_normal_run()
{
	//lcd_normal_init();
	//lcd_count_down();
	switch(statusHorizontal)
	{
	case INIT:
		setTimerBlinky(-1); //not use in this mode
		validateDuration();
		turnOffLEDAll();
		statusHorizontal = NORMAL_RED;
		setTimerHorizontal(ledDurationBuffer[0]*100);
		setTimerLCD(100);
		red = ledDurationBuffer[0];
		green = ledDurationBuffer[1];
		yellow = ledDurationBuffer[2];
		break;
	case NORMAL_RED:
		if (red <= 0) red = ledDurationBuffer[0];
		displayLED(RED, HORIZONTAL);
		lcd_goto_XY(0, 0);
		lcd_send_string("RED: ");
		lcd_goto_XY(0, 7);
		lcd_send_integer(red);

		if(timer_lcd_flag == 1)
		{
			setTimerLCD(100);
			red--;
		}
		if(timer_horizontal_flag)
		{
			lcd_clear_display();
			setTimerLCD(100);
			statusHorizontal = NORMAL_GREEN;
			setTimerHorizontal(ledDurationBuffer[1]*100);
		}
		if(is_button_pressed(0))
		{
			lcd_clear_display();
			statusHorizontal = MAN_RED_IN_HORIZONTAL;
			statusVertical = -1;
			fsm_manual_init();
		}
		break;
	case NORMAL_GREEN:
		if (green <= 0) green = ledDurationBuffer[1];

		displayLED(GREEN, HORIZONTAL);
		lcd_goto_XY(0, 0);
		lcd_send_string("GREEN: ");
		lcd_goto_XY(0, 7);
		lcd_send_integer(green);

		if(timer_lcd_flag == 1)
		{
			setTimerLCD(100);
			green--;
		}
		if(timer_horizontal_flag)
		{
			setTimerLCD(100);
			lcd_clear_display();
			statusHorizontal = NORMAL_YELLOW;
			setTimerHorizontal(ledDurationBuffer[2]*100);
		}
		if(is_button_pressed(0))
		{
			lcd_clear_display();
			statusHorizontal = MAN_RED_IN_HORIZONTAL;
			statusVertical = -1;
			fsm_manual_init();
		}
		break;
	case NORMAL_YELLOW:
		if (yellow <= 0) yellow = ledDurationBuffer[2];

		displayLED(YELLOW, HORIZONTAL);
		lcd_goto_XY(0, 0);
		lcd_send_string("YELLOW: ");
		lcd_goto_XY(0, 7);
		lcd_send_integer(yellow);

		if(timer_lcd_flag == 1)
		{
			setTimerLCD(100);
			yellow--;
		}
		if(timer_horizontal_flag)
		{
			setTimerLCD(100);
			lcd_clear_display();
			statusHorizontal = NORMAL_RED;
			setTimerHorizontal(ledDurationBuffer[0]*100);
		}
		if(is_button_pressed(0))
		{
			lcd_clear_display();
			statusHorizontal = MAN_RED_IN_HORIZONTAL;
			statusVertical = -1;
			fsm_manual_init();
		}
		break;
	default:
		break;
	}
	switch(statusVertical)
	{
	case INIT:
		//validateDuration();
		statusVertical = NORMAL_GREEN;
		setTimerVertical(ledDurationBuffer[1]*100);
		v_red = ledDurationBuffer[0];
		v_green = ledDurationBuffer[1];
		v_yellow = ledDurationBuffer[2];
		setTimerLcdV(100);
		break;
	case NORMAL_RED:
		if (v_red <= 0) v_red = ledDurationBuffer[0];
		displayLED(RED, VERTICAL);
		lcd_goto_XY(1, 0);
		lcd_send_string("RED: ");
		lcd_goto_XY(1, 7);
		lcd_send_integer(v_red);

		if(timer_lcd_v_flag == 1)
		{
			setTimerLcdV(100);
			v_red--;
		}
		if(timer_vertical_flag)
		{
			setTimerLcdV(100);

			lcd_clear_display();
			statusVertical = NORMAL_GREEN;
			setTimerVertical(ledDurationBuffer[1]*100);
		}
		if(is_button_pressed(0))
		{
			lcd_clear_display();
			statusHorizontal = MAN_RED_IN_HORIZONTAL;
			statusVertical = -1;
			fsm_manual_init();
		}
		break;
	case NORMAL_GREEN:
		if (v_green <= 0) v_green = ledDurationBuffer[1];
		displayLED(GREEN, VERTICAL);
		lcd_goto_XY(1, 0);
		lcd_send_string("GREEN: ");
		lcd_goto_XY(1, 7);
		lcd_send_integer(v_green);

		if(timer_lcd_v_flag == 1)
		{
			setTimerLcdV(100);
			v_green--;
		}
		if(timer_vertical_flag)
		{
			setTimerLcdV(100);
			lcd_clear_display();
			statusVertical = NORMAL_YELLOW;
			setTimerVertical(ledDurationBuffer[2]*100);
		}
		if(is_button_pressed(0))
		{
			lcd_clear_display();
			statusVertical =-1;
			statusHorizontal = MAN_RED_IN_HORIZONTAL;
			fsm_manual_init();
		}
		break;
	case NORMAL_YELLOW:
		if (v_yellow <= 0) v_yellow = ledDurationBuffer[2];
		displayLED(YELLOW, VERTICAL);
		lcd_goto_XY(1, 0);
		lcd_send_string("YELLOW: ");
		lcd_goto_XY(1, 7);
		lcd_send_integer(v_yellow);

		if(timer_lcd_v_flag == 1)
		{
			setTimerLcdV(100);
			v_yellow--;
		}
		if(timer_vertical_flag)
		{
			setTimerLcdV(100);
			lcd_clear_display();
			statusVertical = NORMAL_RED;
			setTimerVertical(ledDurationBuffer[0]*100);
		}
		if(is_button_pressed(0))
		{
			lcd_clear_display();
			statusVertical = -1;
			statusHorizontal = MAN_RED_IN_HORIZONTAL;
			fsm_manual_init();
		}
		break;
	default:
		break;
	}

}
