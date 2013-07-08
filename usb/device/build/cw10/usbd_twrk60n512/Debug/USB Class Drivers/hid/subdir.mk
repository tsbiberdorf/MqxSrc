################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"$(HID)/usb_hid.c" \

C_SRCS += \
$(HID)/usb_hid.c \

OBJS += \
./USB\ Class\ Drivers/hid/usb_hid_c.obj \

OBJS_QUOTED += \
"./USB Class Drivers/hid/usb_hid_c.obj" \

C_DEPS += \
./USB\ Class\ Drivers/hid/usb_hid_c.d \

C_DEPS_QUOTED += \
"./USB Class Drivers/hid/usb_hid_c.d" \

OBJS_OS_FORMAT += \
./USB\ Class\ Drivers/hid/usb_hid_c.obj \


# Each subdirectory must supply rules for building sources it contributes
USB\ Class\ Drivers/hid/usb_hid_c.obj: $(HID)/usb_hid.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Class Drivers/hid/usb_hid.args" -o "USB Class Drivers/hid/usb_hid_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Class\ Drivers/hid/usb_hid_c.d: $(HID)/usb_hid.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


