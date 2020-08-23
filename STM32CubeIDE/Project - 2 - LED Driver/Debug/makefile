################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F0xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
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
Project\ -\ 2\ -\ LED\ Driver.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Project\ -\ 2\ -\ LED\ Driver.list \

OBJCOPY_BIN += \
Project\ -\ 2\ -\ LED\ Driver.bin \


# All Target
all: Project\ -\ 2\ -\ LED\ Driver.elf secondary-outputs

# Tool invocations
Project\ -\ 2\ -\ LED\ Driver.elf: $(OBJS) $(USER_OBJS) D:\temp\CileGomuluSistemEgitimi\STM32CubeIDE\Project\ -\ 2\ -\ LED\ Driver\STM32F070RBTX_FLASH.ld
	arm-none-eabi-gcc -o "Project - 2 - LED Driver.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0 -T"D:\temp\CileGomuluSistemEgitimi\STM32CubeIDE\Project - 2 - LED Driver\STM32F070RBTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Project - 2 - LED Driver.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Project\ -\ 2\ -\ LED\ Driver.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Project - 2 - LED Driver.list"
	@echo 'Finished building: $@'
	@echo ' '

Project\ -\ 2\ -\ LED\ Driver.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Project - 2 - LED Driver.bin"
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
