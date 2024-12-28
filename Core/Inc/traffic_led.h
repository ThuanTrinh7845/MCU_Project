/*
 * traffic_led.h
 *
 *  Created on: Nov 19, 2024
 *      Author: Admin
 */

#ifndef INC_TRAFFIC_LED_H_
#define INC_TRAFFIC_LED_H_

#include "global.h"


void displayLED(int status, int lane);
void setDurationBuffer(int index, int duration);
void validateDuration(void);
void blinkyLED1s(int led);
//void turnOffLEDAllin(int lane);
void turnOffLEDAll();
void initBlinkyFor(int led);

#endif /* INC_TRAFFIC_LED_H_ */
