/*
 * global.c
 *
 *  Created on: Nov 19, 2024
 *      Author: Admin
 */

#include "global.h"

GPIO_PinState buttonBuffer[3] = {SET};
int statusHorizontal = INIT;
int statusVertical = INIT;
int ledDurationBuffer[3] = {5, 3, 2};
int red, green, yellow;
int LCDBuffer[2] = {0, 0};

int red_duration = 0;
int green_duration = 0;
int yellow_duration = 0;
