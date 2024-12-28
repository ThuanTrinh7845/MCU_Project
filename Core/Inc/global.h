/*
 * global.h
 *
 *  Created on: Nov 19, 2024
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "timer.h"
#include "button.h"
#include "main.h"
#include "fsm_normal.h"
#include "traffic_led.h"
#include "fsm_manual.h"
#include "i2c-lcd.h"

extern GPIO_PinState buttonBuffer[3];
extern int statusHorizontal;
extern int statusVertical;
extern int ledDurationBuffer[3];
extern int red_duration;
extern int green_duration;
extern int yellow_duration;
extern int LCDBuffer[2];
extern int red, green, yellow;

#define DISABLE					0
#define INIT					1
#define NORMAL_RED				2
#define NORMAL_GREEN			3
#define NORMAL_YELLOW			4

#define RED_MODIFY				5
#define RED_CHANGE_DURATION		6
#define RED_SET_DURATION		7

#define GREEN_MODIFY			8
#define GREEN_CHANGE_DURATION	9
#define GREEN_SET_DURATION		10

#define YELLOW_MODIFY			11
#define YELLOW_CHANGE_DURATION	12
#define YELLOW_SET_DURATION		13

#define MAN_RED_IN_HORIZONTAL	14
#define MAN_GREEN_IN_HORIZONTAL	15
#define MAN_YELLOW_IN_HORIZONTAL 16


//Define the lanes
#define VERTICAL				17
#define HORIZONTAL				18


//Define the display color
#define RED						19
#define GREEN					20
#define YELLOW					21


#endif /* INC_GLOBAL_H_ */
