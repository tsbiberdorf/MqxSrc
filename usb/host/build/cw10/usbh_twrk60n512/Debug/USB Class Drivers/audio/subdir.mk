################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"$(AUDIO)/usb_host_audio.c" \
"$(AUDIO)/usb_host_audio_intf.c" \

C_SRCS += \
$(AUDIO)/usb_host_audio.c \
$(AUDIO)/usb_host_audio_intf.c \

OBJS += \
./USB\ Class\ Drivers/audio/usb_host_audio_c.obj \
./USB\ Class\ Drivers/audio/usb_host_audio_intf_c.obj \

OBJS_QUOTED += \
"./USB Class Drivers/audio/usb_host_audio_c.obj" \
"./USB Class Drivers/audio/usb_host_audio_intf_c.obj" \

C_DEPS += \
./USB\ Class\ Drivers/audio/usb_host_audio_c.d \
./USB\ Class\ Drivers/audio/usb_host_audio_intf_c.d \

C_DEPS_QUOTED += \
"./USB Class Drivers/audio/usb_host_audio_c.d" \
"./USB Class Drivers/audio/usb_host_audio_intf_c.d" \

OBJS_OS_FORMAT += \
./USB\ Class\ Drivers/audio/usb_host_audio_c.obj \
./USB\ Class\ Drivers/audio/usb_host_audio_intf_c.obj \


# Each subdirectory must supply rules for building sources it contributes
USB\ Class\ Drivers/audio/usb_host_audio_c.obj: $(AUDIO)/usb_host_audio.c
	@echo 'Building file: $<'
	@echo 'Executing target #24 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Class Drivers/audio/usb_host_audio.args" -o "USB Class Drivers/audio/usb_host_audio_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Class\ Drivers/audio/usb_host_audio_c.d: $(AUDIO)/usb_host_audio.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

USB\ Class\ Drivers/audio/usb_host_audio_intf_c.obj: $(AUDIO)/usb_host_audio_intf.c
	@echo 'Building file: $<'
	@echo 'Executing target #25 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Class Drivers/audio/usb_host_audio_intf.args" -o "USB Class Drivers/audio/usb_host_audio_intf_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Class\ Drivers/audio/usb_host_audio_intf_c.d: $(AUDIO)/usb_host_audio_intf.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


