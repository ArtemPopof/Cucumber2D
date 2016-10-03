################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Platform/cucumber_system_configuration.cpp 

OBJS += \
./Platform/cucumber_system_configuration.o 

CPP_DEPS += \
./Platform/cucumber_system_configuration.d 


# Each subdirectory must supply rules for building sources it contributes
Platform/%.o: ../Platform/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


