################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup_src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: TivaCTemplate.elf

# Tool invocations
TivaCTemplate.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross GCC Linker'
	arm-none-eabi-gcc -L/home/kristofkalocsai/Projects/ONLAB/khazytol/TivaWare_C_Series-2.1.0.12573/driverlib/gcc -Wl,--static,--gc-sections,-T../startup_src/TM4C.ld -mthumb -mcpu=cortex-m4 -o "TivaCTemplate.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) TivaCTemplate.elf
	-@echo ' '

post-build:
	-@echo 'Generate .bin from .elf'
	-arm-none-eabi-objcopy -O binary TivaCTemplate.elf TivaCTemplate.bin
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
