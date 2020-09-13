################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
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
CSE433_171044079_Final_Project.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
CSE433_171044079_Final_Project.list \

OBJCOPY_BIN += \
CSE433_171044079_Final_Project.bin \


# All Target
all: CSE433_171044079_Final_Project.elf secondary-outputs

# Tool invocations
CSE433_171044079_Final_Project.elf: $(OBJS) $(USER_OBJS) C:\Users\PC\STM32CubeIDE\workspace_1.2.0\CSE433_171044079_Final_Project\STM32F411RETX_FLASH.ld
	arm-none-eabi-gcc -o "CSE433_171044079_Final_Project.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\PC\STM32CubeIDE\workspace_1.2.0\CSE433_171044079_Final_Project\STM32F411RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="CSE433_171044079_Final_Project.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -u _printf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

CSE433_171044079_Final_Project.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "CSE433_171044079_Final_Project.list"
	@echo 'Finished building: $@'
	@echo ' '

CSE433_171044079_Final_Project.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "CSE433_171044079_Final_Project.bin"
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
