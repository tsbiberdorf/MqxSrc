################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"$(HUB)/usb_host_hub.c" \
"$(HUB)/usb_host_hub_sm.c" \

C_SRCS += \
$(HUB)/usb_host_hub.c \
$(HUB)/usb_host_hub_sm.c \

OBJS += \
./USB\ Class\ Drivers/hub/usb_host_hub_c.obj \
./USB\ Class\ Drivers/hub/usb_host_hub_sm_c.obj \

OBJS_QUOTED += \
"./USB Class Drivers/hub/usb_host_hub_c.obj" \
"./USB Class Drivers/hub/usb_host_hub_sm_c.obj" \

C_DEPS += \
./USB\ Class\ Drivers/hub/usb_host_hub_c.d \
./USB\ Class\ Drivers/hub/usb_host_hub_sm_c.d \

C_DEPS_QUOTED += \
"./USB Class Drivers/hub/usb_host_hub_c.d" \
"./USB Class Drivers/hub/usb_host_hub_sm_c.d" \

OBJS_OS_FORMAT += \
./USB\ Class\ Drivers/hub/usb_host_hub_c.obj \
./USB\ Class\ Drivers/hub/usb_host_hub_sm_c.obj \


# Each subdirectory must supply rules for building sources it contributes
USB\ Class\ Drivers/hub/usb_host_hub_c.obj: $(HUB)/usb_host_hub.c
	@echo 'Building file: $<'
	@echo 'Executing target #19 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Class Drivers/hub/usb_host_hub.args" -o "USB Class Drivers/hub/usb_host_hub_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Class\ Drivers/hub/usb_host_hub_c.d: $(HUB)/usb_host_hub.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

USB\ Class\ Drivers/hub/usb_host_hub_sm_c.obj: $(HUB)/usb_host_hub_sm.c
	@echo 'Building file: $<'
	@echo 'Executing target #20 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Class Drivers/hub/usb_host_hub_sm.args" -o "USB Class Drivers/hub/usb_host_hub_sm_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Class\ Drivers/hub/usb_host_hub_sm_c.d: $(HUB)/usb_host_hub_sm.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


