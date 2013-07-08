################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"$(PHDC)/usb_host_phdc.c" \

C_SRCS += \
$(PHDC)/usb_host_phdc.c \

OBJS += \
./USB\ Class\ Drivers/phdc/usb_host_phdc_c.obj \

OBJS_QUOTED += \
"./USB Class Drivers/phdc/usb_host_phdc_c.obj" \

C_DEPS += \
./USB\ Class\ Drivers/phdc/usb_host_phdc_c.d \

C_DEPS_QUOTED += \
"./USB Class Drivers/phdc/usb_host_phdc_c.d" \

OBJS_OS_FORMAT += \
./USB\ Class\ Drivers/phdc/usb_host_phdc_c.obj \


# Each subdirectory must supply rules for building sources it contributes
USB\ Class\ Drivers/phdc/usb_host_phdc_c.obj: $(PHDC)/usb_host_phdc.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Class Drivers/phdc/usb_host_phdc.args" -o "USB Class Drivers/phdc/usb_host_phdc_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Class\ Drivers/phdc/usb_host_phdc_c.d: $(PHDC)/usb_host_phdc.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


