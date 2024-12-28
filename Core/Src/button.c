/*
 * button.c
 *
 *  Created on: Nov 19, 2024
 *      Author: Admin
 */

/*
 * input_reading.c
 *
 *  Created on: Oct 23, 2024
 *      Author: Admin
 */

#include "button.h"
// we aim to work with more than one buttons
#define N0_OF_BUTTONS	3
// timer interrupt duration is 10ms , so to pass 1 second ,
// we need to jump to the interrupt service routine 100 time
#define DURATION_FOR_AUTO_INCREASING 	100
#define BUTTON_IS_PRESSED 		GPIO_PIN_RESET
#define BUTTON_IS_RELEASED 		GPIO_PIN_SET
// the buffer that the final result is stored after debouncing

// we define two buffers for debouncing
static GPIO_PinState debounceButtonBuffer0[N0_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer1[N0_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[N0_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer3[N0_OF_BUTTONS];
// we define a flag for a button pressed more than 1 second .
//static uint8_t flagForButtonPress1s[N0_OF_BUTTONS];
// we define counter for automatically increasing the value after the button is pressed more than 1 second .
//static uint16_t counterForButtonPress1s[N0_OF_BUTTONS];

void button_reading(void)
{
	for (int i = 0; i < N0_OF_BUTTONS; i++)
	{
		debounceButtonBuffer0[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = debounceButtonBuffer2[i];
		switch(i)
		{
		case 0:
			debounceButtonBuffer2[0] = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
			break;
		case 1:
			debounceButtonBuffer2[1] = HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin);
			break;
		case 2:
			debounceButtonBuffer2[2] = HAL_GPIO_ReadPin(Button3_GPIO_Port, Button3_Pin);
			break;
		default:
			break;
		}

		if((debounceButtonBuffer0[i] == debounceButtonBuffer1[i]) && (debounceButtonBuffer1[i] == debounceButtonBuffer2[i]))
		{
			if(debounceButtonBuffer3[i] != debounceButtonBuffer2[i])
			{
				debounceButtonBuffer3[i] = debounceButtonBuffer2[i];
				if(debounceButtonBuffer2[i] == BUTTON_IS_PRESSED)
				{
					buttonBuffer[i] = debounceButtonBuffer2[i];
				}
			}
		}
//		if(buttonBuffer[i] == BUTTON_IS_PRESSED)
//		{
//			// if a button is pressed , we start counting
//			if(counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING)
//			{
//				counterForButtonPress1s[i]++;
//			}
//			else
//			{
//				// the flag is turned on when 1 second has passed since the button is pressed .
//				flagForButtonPress1s[i] = 1;
//				//TODO
//			}
//		}
//		else
//		{
//			counterForButtonPress1s[i] = 0;
//			flagForButtonPress1s[i] = 0;
//		}
	}
}
unsigned int is_button_pressed(uint8_t index)
{
	if(index >= N0_OF_BUTTONS) return 0;
	if(buttonBuffer[index] == BUTTON_IS_PRESSED)
	{
		buttonBuffer[index] = BUTTON_IS_RELEASED;
		return 1;
	}
	return 0;
}

//unsigned int is_button_pressed_1s(unsigned char index)
//{
//	if(index >= N0_OF_BUTTONS) return 0xff;
//	return (flagForButtonPress1s[index] == 1);
//}

