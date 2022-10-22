/*
 * PWM.c
 *
 *  Created on: Oct 8, 2022
 *      Author: laglt2
 */


#include "PWM.h"

/*	Higher Level Functions	*/

void PWM_init(TIM_HandleTypeDef *htim, uint32_t period, uint32_t dutyCycle){

	TIM2->ARR 	= period;
	TIM2->CCR1 	= dutyCycle;
	TIM2->CCR2 	= dutyCycle;
	TIM2->CCR3 	= dutyCycle;
	TIM2->CCR4 	= dutyCycle;


	HAL_TIM_PWM_Start(htim, TIM_CHANNEL_1); //PWM out enable
	HAL_TIM_PWM_Start(htim, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(htim, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(htim, TIM_CHANNEL_4);
}

void PWM_set(PWM_Channel_t channel, uint32_t dutyCycle){
	switch(channel){
		case PWM_CHANNEL_1:
			TIM2->CCR1 = dutyCycle;

			break;
		case PWM_CHANNEL_2:
			TIM2->CCR2 = dutyCycle;

			break;
		case PWM_CHANNEL_3:
			TIM2->CCR3 = dutyCycle;

			break;
		case PWM_CHANNEL_4:
			TIM2->CCR4 = dutyCycle;

			break;
	}
}
