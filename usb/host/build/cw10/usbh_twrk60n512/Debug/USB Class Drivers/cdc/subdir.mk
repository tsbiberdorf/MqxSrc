################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"$(CDC)/usb_host_cdc.c" \
"$(CDC)/usb_host_cdc_intf.c" \

C_SRCS += \
$(CDC)/usb_host_cdc.c \
$(CDC)/usb_host_cdc_intf.c \

OBJS += \
./USB\ Class\ Drivers/cdc/usb_host_cdc_c.obj \
./USB\ Class\ Drivers/cdc/usb_host_cdc_intf_c.obj \

OBJS_QUOTED += \
"./USB Class Drivers/cdc/usb_host_cdc_c.obj" \
"./USB Class Drivers/cdc/usb_host_cdc_intf_c.obj" \

C_DEPS += \
./USB\ Class\ Drivers/cdc/usb_host_cdc_c.d \
./USB\ Class\ Drivers/cdc/usb_host_cdc_intf_c.d \

C_DEPS_QUOTED += \
"./USB Class Drivers/cdc/usb_host_cdc_c.d" \
"./USB Class Drivers/cdc/usb_host_cdc_intf_c.d" \

OBJS_OS_FORMAT += \
./USB\ Class\ Drivers/cdc/usb_host_cdc_c.obj \
./USB\ Class\ Drivers/cdc/usb_host_cdc_intf_c.obj \


# Each subdirectory must supply rules for building sources it contributes
USB\ Class\ Drivers/cdc/usb_host_cdc_c.obj: $(CDC)/usb_host_cdc.c
	@echo 'Building file: $<'
	@echo 'Executing target #22 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Class Drivers/cdc/usb_host_cdc.args" -o "USB Class Drivers/cdc/usb_host_cdc_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Class\ Drivers/cdc/usb_host_cdc_c.d: $(CDC)/usb_host_cdc.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

USB\ Class\ Drivers/cdc/usb_host_cdc_intf_c.obj: $(CDC)/usb_host_cdc_intf.c
	@echo 'Building file: $<'
	@echo 'Executing target #23 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Class Drivers/cdc/usb_host_cdc_intf.args" -o "USB Class Drivers/cdc/usb_host_cdc_intf_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Class\ Drivers/cdc/usb_host_cdc_intf_c.d: $(CDC)/usb_host_cdc_intf.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


