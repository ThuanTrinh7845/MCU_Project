/*
 * traffic_led.c
 *
 *  Created on: Nov 19, 2024
 *      Author: Admin
 */

#include "traffic_led.h"

/*
 * led_display.c
 *
 *  Created on: Oct 23, 2024
 *      Author: Admin
 */



void displayLED(int status, int lane)
{
	switch(lane)
	{
	case VERTICAL:
		switch(status)
		{
		case RED:
			HAL_GPIO_WritePin(D9_GPIO_Port, D9_Pin, SET);
			HAL_GPIO_WritePin(D10_GPIO_Port, D10_Pin, SET);

			HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, SET);
			HAL_GPIO_WritePin(D8_GPIO_Port, D8_Pin, SET);
			break;
		case GREEN:
			HAL_GPIO_WritePin(D9_GPIO_Port, D9_Pin, SET);
			HAL_GPIO_WritePin(D10_GPIO_Port, D10_Pin, RESET);

			HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, SET);
			HAL_GPIO_WritePin(D8_GPIO_Port, D8_Pin, RESET);
			break;
		case YELLOW:
			HAL_GPIO_WritePin(D9_GPIO_Port, D9_Pin, RESET);
			HAL_GPIO_WritePin(D10_GPIO_Port, D10_Pin, SET);

			HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, RESET);
			HAL_GPIO_WritePin(D8_GPIO_Port, D8_Pin, SET);
			break;
		default:
			break;
		}
		break;
	case HORIZONTAL:
		switch(status)
		{
		case RED:
			HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
			HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, SET);

			HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);
			HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
			break;
		case GREEN:
			HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
			HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, RESET);

			HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);
			HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, RESET);
			break;
		case YELLOW:
			HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, RESET);
			HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, SET);

			HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, RESET);
			HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}
void setDurationBuffer(int index, int duration)
{
	ledDurationBuffer[index] = duration;
}

void validateDuration()
{
	if (ledDurationBuffer[0] - (ledDurationBuffer[2] + ledDurationBuffer[1]) > 0)
	{
		ledDurationBuffer[1] += ledDurationBuffer[0] - (ledDurationBuffer[2] + ledDurationBuffer[1]);
	}
	if (ledDurationBuffer[0] - (ledDurationBuffer[2] + ledDurationBuffer[1]) < 0)
	{
		ledDurationBuffer[0] += (ledDurationBuffer[2] + ledDurationBuffer[1]) - ledDurationBuffer[0];
	}

}

void blinkyLED1s(int led)
{
	//Nhớ viết hàm init cho blinky LED
	switch(led)
	{
	case RED:
		if(timer_blinky_led_flag)
		{
			setTimerBlinky(100);
			HAL_GPIO_TogglePin(D3_GPIO_Port, D3_Pin);
			HAL_GPIO_TogglePin(D4_GPIO_Port, D4_Pin);

			HAL_GPIO_TogglePin(D5_GPIO_Port, D5_Pin);
			HAL_GPIO_TogglePin(D6_GPIO_Port, D6_Pin);

			HAL_GPIO_TogglePin(D7_GPIO_Port, D7_Pin);
			HAL_GPIO_TogglePin(D8_GPIO_Port, D8_Pin);

			HAL_GPIO_TogglePin(D9_GPIO_Port, D9_Pin);
			HAL_GPIO_TogglePin(D10_GPIO_Port, D10_Pin);
		}
		break;
	case YELLOW:
		if(timer_blinky_led_flag)
		{
			setTimerBlinky(100);
			HAL_GPIO_TogglePin(D4_GPIO_Port, D4_Pin);
			HAL_GPIO_TogglePin(D6_GPIO_Port, D6_Pin);
			HAL_GPIO_TogglePin(D8_GPIO_Port, D8_Pin);
			HAL_GPIO_TogglePin(D10_GPIO_Port, D10_Pin);
		}
		break;
	case GREEN:
		if(timer_blinky_led_flag)
		{
			setTimerBlinky(100);
			HAL_GPIO_TogglePin(D3_GPIO_Port, D3_Pin);
			HAL_GPIO_TogglePin(D5_GPIO_Port, D5_Pin);
			HAL_GPIO_TogglePin(D7_GPIO_Port, D7_Pin);
			HAL_GPIO_TogglePin(D9_GPIO_Port, D9_Pin);
		}
		break;
	default:
		break;
	}
}
void turnOffLEDAllin(int lane)
{
//	switch(lane)
//	{
//	case VERTICAL:
//		HAL_GPIO_WritePin(RED_VER_GPIO_Port, RED_VER_Pin, RESET);
//		HAL_GPIO_WritePin(GREEN_VER_GPIO_Port, GREEN_VER_Pin, RESET);
//		HAL_GPIO_WritePin(YELLOW_VER_GPIO_Port, YELLOW_VER_Pin, RESET);
//		break;
//	case HORIZONTAL:
//		HAL_GPIO_WritePin(RED_HOZ_GPIO_Port, RED_HOZ_Pin, RESET);
//		HAL_GPIO_WritePin(GREEN_HOZ_GPIO_Port, GREEN_HOZ_Pin, RESET);
//		HAL_GPIO_WritePin(YELLOW_HOZ_GPIO_Port, YELLOW_HOZ_Pin, RESET);
//		break;
//	default:
//		break;
//	}
}
void turnOffLEDAll()
{
	HAL_GPIO_WritePin(D10_GPIO_Port, D10_Pin, RESET);
	HAL_GPIO_WritePin(D9_GPIO_Port, D9_Pin, RESET);
	HAL_GPIO_WritePin(D8_GPIO_Port, D8_Pin, RESET);
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, RESET);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, RESET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, RESET);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, RESET);
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, RESET);
}
void initBlinkyFor(int led)
{
	turnOffLEDAll();
	setTimerBlinky(100);
	switch(led)
	{
	case RED:
		//Do nothing...
		break;
	case GREEN:
		HAL_GPIO_WritePin(D9_GPIO_Port, D9_Pin, SET);
		HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, SET);
		HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
		HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);
		break;
	case YELLOW:
		HAL_GPIO_WritePin(D10_GPIO_Port, D10_Pin, SET);
		HAL_GPIO_WritePin(D8_GPIO_Port, D8_Pin, SET);
		HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, SET);
		HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
		break;
	default:
		break;
	}
}
