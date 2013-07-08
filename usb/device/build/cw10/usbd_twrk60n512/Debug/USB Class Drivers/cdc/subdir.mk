################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"$(CDC)/usb_cdc.c" \
"$(CDC)/usb_cdc_pstn.c" \

C_SRCS += \
$(CDC)/usb_cdc.c \
$(CDC)/usb_cdc_pstn.c \

OBJS += \
./USB\ Class\ Drivers/cdc/usb_cdc_c.obj \
./USB\ Class\ Drivers/cdc/usb_cdc_pstn_c.obj \

OBJS_QUOTED += \
"./USB Class Drivers/cdc/usb_cdc_c.obj" \
"./USB Class Drivers/cdc/usb_cdc_pstn_c.obj" \

C_DEPS += \
./USB\ Class\ Drivers/cdc/usb_cdc_c.d \
./USB\ Class\ Drivers/cdc/usb_cdc_pstn_c.d \

C_DEPS_QUOTED += \
"./USB Class Drivers/cdc/usb_cdc_c.d" \
"./USB Class Drivers/cdc/usb_cdc_pstn_c.d" \

OBJS_OS_FORMAT += \
./USB\ Class\ Drivers/cdc/usb_cdc_c.obj \
./USB\ Class\ Drivers/cdc/usb_cdc_pstn_c.obj \


# Each subdirectory must supply rules for building sources it contributes
USB\ Class\ Drivers/cdc/usb_cdc_c.obj: $(CDC)/usb_cdc.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Class Drivers/cdc/usb_cdc.args" -o "USB Class Drivers/cdc/usb_cdc_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Class\ Drivers/cdc/usb_cdc_c.d: $(CDC)/usb_cdc.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

USB\ Class\ Drivers/cdc/usb_cdc_pstn_c.obj: $(CDC)/usb_cdc_pstn.c
	@echo 'Building file: $<'
	@echo 'Executing target #17 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Class Drivers/cdc/usb_cdc_pstn.args" -o "USB Class Drivers/cdc/usb_cdc_pstn_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Class\ Drivers/cdc/usb_cdc_pstn_c.d: $(CDC)/usb_cdc_pstn.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


