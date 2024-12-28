/*
 * timer.h
 *
 *  Created on: Nov 19, 2024
 *      Author: Admin
 */
#ifndef INC_TIMER_H_
#define INC_TIMER_H_
#include "global.h"

extern int timer_horizontal_flag;
extern int timer_vertical_flag;
extern int timer_blinky_led_flag;
extern int timer_lcd_flag;
extern int timer_lcd_v_flag;


void setTimerHorizontal(int duration);
void setTimerVertical(int duration);
void setTimerBlinky(int duration);
void setTimerLCD(int duration);
void setTimerLcdV(int duration);
void timerRun();

#endif /* INC_TIMER_H_ */
