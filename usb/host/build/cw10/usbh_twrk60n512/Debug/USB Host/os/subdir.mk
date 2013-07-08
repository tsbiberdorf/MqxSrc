################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"$(MQX)/mqx_dll.c" \
"$(MQX)/usb_mqx.c" \

C_SRCS += \
$(MQX)/mqx_dll.c \
$(MQX)/usb_mqx.c \

OBJS += \
./USB\ Host/os/mqx_dll_c.obj \
./USB\ Host/os/usb_mqx_c.obj \

OBJS_QUOTED += \
"./USB Host/os/mqx_dll_c.obj" \
"./USB Host/os/usb_mqx_c.obj" \

C_DEPS += \
./USB\ Host/os/mqx_dll_c.d \
./USB\ Host/os/usb_mqx_c.d \

C_DEPS_QUOTED += \
"./USB Host/os/mqx_dll_c.d" \
"./USB Host/os/usb_mqx_c.d" \

OBJS_OS_FORMAT += \
./USB\ Host/os/mqx_dll_c.obj \
./USB\ Host/os/usb_mqx_c.obj \


# Each subdirectory must supply rules for building sources it contributes
USB\ Host/os/mqx_dll_c.obj: $(MQX)/mqx_dll.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Host/os/mqx_dll.args" -o "USB Host/os/mqx_dll_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Host/os/mqx_dll_c.d: $(MQX)/mqx_dll.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

USB\ Host/os/usb_mqx_c.obj: $(MQX)/usb_mqx.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Host/os/usb_mqx.args" -o "USB Host/os/usb_mqx_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Host/os/usb_mqx_c.d: $(MQX)/usb_mqx.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


