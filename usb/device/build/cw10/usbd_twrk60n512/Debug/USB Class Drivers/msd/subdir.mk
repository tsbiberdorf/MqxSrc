################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"$(MSD)/usb_msc.c" \
"$(MSD)/usb_msc_scsi.c" \

C_SRCS += \
$(MSD)/usb_msc.c \
$(MSD)/usb_msc_scsi.c \

OBJS += \
./USB\ Class\ Drivers/msd/usb_msc_c.obj \
./USB\ Class\ Drivers/msd/usb_msc_scsi_c.obj \

OBJS_QUOTED += \
"./USB Class Drivers/msd/usb_msc_c.obj" \
"./USB Class Drivers/msd/usb_msc_scsi_c.obj" \

C_DEPS += \
./USB\ Class\ Drivers/msd/usb_msc_c.d \
./USB\ Class\ Drivers/msd/usb_msc_scsi_c.d \

C_DEPS_QUOTED += \
"./USB Class Drivers/msd/usb_msc_c.d" \
"./USB Class Drivers/msd/usb_msc_scsi_c.d" \

OBJS_OS_FORMAT += \
./USB\ Class\ Drivers/msd/usb_msc_c.obj \
./USB\ Class\ Drivers/msd/usb_msc_scsi_c.obj \


# Each subdirectory must supply rules for building sources it contributes
USB\ Class\ Drivers/msd/usb_msc_c.obj: $(MSD)/usb_msc.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Class Drivers/msd/usb_msc.args" -o "USB Class Drivers/msd/usb_msc_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Class\ Drivers/msd/usb_msc_c.d: $(MSD)/usb_msc.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

USB\ Class\ Drivers/msd/usb_msc_scsi_c.obj: $(MSD)/usb_msc_scsi.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Class Drivers/msd/usb_msc_scsi.args" -o "USB Class Drivers/msd/usb_msc_scsi_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Class\ Drivers/msd/usb_msc_scsi_c.d: $(MSD)/usb_msc_scsi.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


