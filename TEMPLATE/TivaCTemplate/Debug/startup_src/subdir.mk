################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../startup_src/TM4C_startup.c 

OBJS += \
./startup_src/TM4C_startup.o 

C_DEPS += \
./startup_src/TM4C_startup.d 


# Each subdirectory must supply rules for building sources it contributes
startup_src/%.o: ../startup_src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-none-eabi-gcc -DPART_TM4C1294NCPDT -I/home/kristofkalocsai/Projects/ONLAB/khazytol/TivaWare_C_Series-2.1.0.12573 -O0 -g3 -Wall -c -fmessage-length=0 -mthumb -mcpu=cortex-m4 -march=armv7e-m -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -ffunction-sections -fdata-sections -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


