################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"$(PRINTER)/usb_host_printer.c" \

C_SRCS += \
$(PRINTER)/usb_host_printer.c \

OBJS += \
./USB\ Class\ Drivers/printer/usb_host_printer_c.obj \

OBJS_QUOTED += \
"./USB Class Drivers/printer/usb_host_printer_c.obj" \

C_DEPS += \
./USB\ Class\ Drivers/printer/usb_host_printer_c.d \

C_DEPS_QUOTED += \
"./USB Class Drivers/printer/usb_host_printer_c.d" \

OBJS_OS_FORMAT += \
./USB\ Class\ Drivers/printer/usb_host_printer_c.obj \


# Each subdirectory must supply rules for building sources it contributes
USB\ Class\ Drivers/printer/usb_host_printer_c.obj: $(PRINTER)/usb_host_printer.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Class Drivers/printer/usb_host_printer.args" -o "USB Class Drivers/printer/usb_host_printer_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Class\ Drivers/printer/usb_host_printer_c.d: $(PRINTER)/usb_host_printer.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


