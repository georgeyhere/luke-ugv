/*
 * MOTOR_DRIVE.c
 *
 *  Created on: Oct 21, 2022
 *      Author: laglt2
 */

#include "MOTOR_DRIVE.h"

/*	Functions	*/

void initVehicleDrive(TIM_HandleTypeDef *htim) {
	HAL_GPIO_WritePin(MOTOR_DRIVE_DIR_PORT,
			MOTOR_DRIVE_DIR_PIN_MOTOR_1 | MOTOR_DRIVE_DIR_PIN_MOTOR_2
					| MOTOR_DRIVE_DIR_PIN_MOTOR_3 | MOTOR_DRIVE_DIR_PIN_MOTOR_4,
			0);

	PWM_init(htim, MOTOR_DRIVE_PERIOD, MOTOR_DRIVE_DC_LOW);
}

void driveVehicle(int32_t leftDC, int32_t rightDC) {
	//Signed velocity values
	uint32_t leftPWM = abs(leftDC);
	uint32_t rightPWM = abs(rightDC);

	if (leftPWM > MOTOR_DRIVE_DC_LOW) {
		leftPWM = MOTOR_DRIVE_DC_LOW;
	} else {
		leftPWM = MOTOR_DRIVE_DC_LOW - leftPWM;
	}
	if (rightPWM > MOTOR_DRIVE_DC_LOW) {
		rightPWM = MOTOR_DRIVE_DC_LOW;
	} else {
		rightPWM = MOTOR_DRIVE_DC_LOW - rightPWM;
	}

	if (leftDC < 0) {
		HAL_GPIO_WritePin(MOTOR_DRIVE_DIR_PORT,
		MOTOR_DRIVE_DIR_PIN_MOTOR_1 | MOTOR_DRIVE_DIR_PIN_MOTOR_3, 1);
		PWM_set(MOTOR_DRIVE_PWM_MOTOR_1, leftPWM);
		PWM_set(MOTOR_DRIVE_PWM_MOTOR_3, leftPWM);
	}
	if (leftDC >= 0) {
		HAL_GPIO_WritePin(MOTOR_DRIVE_DIR_PORT,
		MOTOR_DRIVE_DIR_PIN_MOTOR_1 | MOTOR_DRIVE_DIR_PIN_MOTOR_3, 0);
		PWM_set(MOTOR_DRIVE_PWM_MOTOR_1, leftPWM);
		PWM_set(MOTOR_DRIVE_PWM_MOTOR_3, leftPWM);
	}
	if (rightDC < 0) {
		HAL_GPIO_WritePin(MOTOR_DRIVE_DIR_PORT,
		MOTOR_DRIVE_DIR_PIN_MOTOR_2 | MOTOR_DRIVE_DIR_PIN_MOTOR_4, 1);
		PWM_set(MOTOR_DRIVE_PWM_MOTOR_2, rightPWM);
		PWM_set(MOTOR_DRIVE_PWM_MOTOR_4, rightPWM);
	}
	if (rightDC >= 0) {
		HAL_GPIO_WritePin(MOTOR_DRIVE_DIR_PORT,
		MOTOR_DRIVE_DIR_PIN_MOTOR_2 | MOTOR_DRIVE_DIR_PIN_MOTOR_4, 0);
		PWM_set(MOTOR_DRIVE_PWM_MOTOR_2, rightPWM);
		PWM_set(MOTOR_DRIVE_PWM_MOTOR_4, rightPWM);
	}
}

