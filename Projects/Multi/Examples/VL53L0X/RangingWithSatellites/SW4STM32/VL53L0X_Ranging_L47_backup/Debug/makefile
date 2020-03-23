################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include src/subdir.mk
-include Drivers/STM32L4xx_HAL_Driver/subdir.mk
-include Drivers/CMSIS/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
VL53L0X_Ranging_L47_backup.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
VL53L0X_Ranging_L47_backup.list \

OBJCOPY_BIN += \
VL53L0X_Ranging_L47_backup.bin \


# All Target
all: VL53L0X_Ranging_L47_backup.elf secondary-outputs

# Tool invocations
VL53L0X_Ranging_L47_backup.elf: $(OBJS) $(USER_OBJS) F:\cubeWorkspace\Cube_VL53L0X_V1.2.0\Projects\Multi\Examples\VL53L0X\RangingWithSatellites\SW4STM32\VL53L0X_Ranging_L47_backup\STM32L476RGTx_FLASH.ld
	arm-none-eabi-gcc -o "VL53L0X_Ranging_L47_backup.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"F:\cubeWorkspace\Cube_VL53L0X_V1.2.0\Projects\Multi\Examples\VL53L0X\RangingWithSatellites\SW4STM32\VL53L0X_Ranging_L47_backup\STM32L476RGTx_FLASH.ld" --specs=nosys.specs -Wl,-Map="VL53L0X_Ranging_L47_backup.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

VL53L0X_Ranging_L47_backup.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "VL53L0X_Ranging_L47_backup.list"
	@echo 'Finished building: $@'
	@echo ' '

VL53L0X_Ranging_L47_backup.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "VL53L0X_Ranging_L47_backup.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
