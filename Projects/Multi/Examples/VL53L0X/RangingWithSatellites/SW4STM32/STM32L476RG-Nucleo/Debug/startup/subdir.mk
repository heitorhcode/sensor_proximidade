################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
F:/cubeWorkspace/Cube_VL53L0X_V1.2.0/Drivers/CMSIS/Device/ST/STM32L4xx/Source/Templates/gcc/startup_stm32l476xx.s 

OBJS += \
./startup/startup_stm32l476xx.o 


# Each subdirectory must supply rules for building sources it contributes
startup/startup_stm32l476xx.o: F:/cubeWorkspace/Cube_VL53L0X_V1.2.0/Drivers/CMSIS/Device/ST/STM32L4xx/Source/Templates/gcc/startup_stm32l476xx.s
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -c -I./../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc -I./../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I./../../../../../../../../Drivers/CMSIS/Include -I./../../../../../../../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I./../../../Inc -x assembler-with-cpp --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

