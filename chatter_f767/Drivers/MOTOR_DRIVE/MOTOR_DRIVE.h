/*
 * MOTOR_DRIVE.h
 *
 *  Created on: Oct 20, 2022
 *      Author: Luke Gutierrez
 */

#ifndef MOTOR_DRIVE_MOTOR_DRIVE_H_
#define MOTOR_DRIVE_MOTOR_DRIVE_H_


/*	Include Paths	*/
#include "stm32f7xx_hal.h"
#include "../PWM/PWM.h"
#include "stdlib.h"
#include "main.h"


/* 	Defines	*/
#define MOTOR_DRIVE_DIR_PORT		GPIOF		//Direction PINS port

#define MOTOR_DRIVE_DIR_PIN_MOTOR_1	GPIO_PIN_1	//Motor 1
#define MOTOR_DRIVE_DIR_PIN_MOTOR_2	GPIO_PIN_0	//Motor 2
#define MOTOR_DRIVE_DIR_PIN_MOTOR_3	GPIO_PIN_2	//Motor 3
#define MOTOR_DRIVE_DIR_PIN_MOTOR_4	GPIO_PIN_3	//Motor 4

#define MOTOR_DRIVE_PWM_MOTOR_1		PWM_CHANNEL_2
#define MOTOR_DRIVE_PWM_MOTOR_2		PWM_CHANNEL_1
#define MOTOR_DRIVE_PWM_MOTOR_3		PWM_CHANNEL_3
#define MOTOR_DRIVE_PWM_MOTOR_4		PWM_CHANNEL_4

#define MOTOR_DRIVE_DC_MAX 0 //Flip these two if they are in reverse
#define MOTOR_DRIVE_DC_LOW 16000
#define MOTOR_DRIVE_PERIOD 16000

/*	Function Declaration	*/
void initVehicleDrive(TIM_HandleTypeDef *htim);
void driveVehicle(int32_t leftDC, int32_t rightDC); //Signed velocity values


#endif /* MOTOR_DRIVE_MOTOR_DRIVE_H_ */
