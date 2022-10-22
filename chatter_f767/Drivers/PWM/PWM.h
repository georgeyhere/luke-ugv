/*
 * PWM.h
 *
 *  Created on: Oct 8, 2022
 *      Author: Luke Gutierrez
 *
 *  PWM Output Driver Written by Luke Gutiterrez
 *
 *  Outputs are predefined and associated with appropiate timers
 *
 *  For this driver we will be using timer 2 since it is 32 bit
 */

#ifndef PWM_PWM_H_
#define PWM_PWM_H_


#include "stm32f7xx_hal.h"




//void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/*	Structure Definitions	*/

typedef enum {
	PWM_CHANNEL_1 = 1,
	PWM_CHANNEL_2 = 2,
	PWM_CHANNEL_3 = 3,
	PWM_CHANNEL_4 = 4
} PWM_Channel_t;

typedef struct {
	uint32_t PWM1;
	uint32_t PWM2;
	uint32_t PWM3;
	uint32_t PWM4;
} PWM_DutyCycle_t;

/*	Function Definitions	*/

void PWM_init(TIM_HandleTypeDef *htim, uint32_t period, uint32_t dutyCycle); //Must Be Passed Single Timer Instance
void PWM_set(PWM_Channel_t channel, uint32_t dutyCycle);


/*	Low Level Functions		*/




#endif /* PWM_PWM_H_ */
