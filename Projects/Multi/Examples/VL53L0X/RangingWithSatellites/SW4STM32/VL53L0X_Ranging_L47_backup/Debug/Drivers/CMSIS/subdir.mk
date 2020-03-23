################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
F:/cubeWorkspace/Cube_VL53L0X_V1.2.0/Projects/Multi/Examples/VL53L0X/RangingWithSatellites/SW4STM32/Cube_VL53L0X_V1.2.0/Drivers/CMSIS/Device/ST/STM32L4xx/Source/Templates/system_stm32l4xx.c 

OBJS += \
./Drivers/CMSIS/system_stm32l4xx.o 

C_DEPS += \
./Drivers/CMSIS/system_stm32l4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/system_stm32l4xx.o: F:/cubeWorkspace/Cube_VL53L0X_V1.2.0/Projects/Multi/Examples/VL53L0X/RangingWithSatellites/SW4STM32/Cube_VL53L0X_V1.2.0/Drivers/CMSIS/Device/ST/STM32L4xx/Source/Templates/system_stm32l4xx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DNUCLEO_L476RG -DSTM32 -DSTM32L4 -DUSE_HAL_DRIVER -DSTM32L476xx '-DTRACE_UART=1' '-DVL53L0_LOG_ENABLE=1' '-DXNUCLEO53L0A1_TRACE=1' '-DVL53L0A1_HAVE_UART=1' -c -I./../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc -I./../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I./../../../../../../../../Drivers/CMSIS/Include -I./../../../../../../../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I./../../../Inc -I"F:/cubeWorkspace/Cube_VL53L0X_V1.2.0/Drivers/BSP/X-NUCLEO-53L0A1" -I"F:/cubeWorkspace/Cube_VL53L0X_V1.2.0/Drivers/BSP/Components/vl53l0x" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/system_stm32l4xx.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

