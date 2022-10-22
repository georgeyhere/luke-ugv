################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/MOTOR_DRIVE/MOTOR_DRIVE.c 

C_DEPS += \
./Drivers/MOTOR_DRIVE/MOTOR_DRIVE.d 

OBJS += \
./Drivers/MOTOR_DRIVE/MOTOR_DRIVE.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/MOTOR_DRIVE/%.o Drivers/MOTOR_DRIVE/%.su: ../Drivers/MOTOR_DRIVE/%.c Drivers/MOTOR_DRIVE/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I../Core/Inc -I"/Users/laglt2/Google Drive/Projects/2022/NGCP/chatter_f767/Drivers/MOTOR_DRIVE" -I"/Users/laglt2/Google Drive/Projects/2022/NGCP/chatter_f767/Drivers/OLED" -I"/Users/laglt2/Google Drive/Projects/2022/NGCP/chatter_f767/Drivers/PWM" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-MOTOR_DRIVE

clean-Drivers-2f-MOTOR_DRIVE:
	-$(RM) ./Drivers/MOTOR_DRIVE/MOTOR_DRIVE.d ./Drivers/MOTOR_DRIVE/MOTOR_DRIVE.o ./Drivers/MOTOR_DRIVE/MOTOR_DRIVE.su

.PHONY: clean-Drivers-2f-MOTOR_DRIVE

