################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"$(MSD)/usb_host_msd_bo.c" \
"$(MSD)/usb_host_msd_queue.c" \
"$(MSD)/usb_host_msd_ufi.c" \
"$(MFS)/usbmfs.c" \

C_SRCS += \
$(MSD)/usb_host_msd_bo.c \
$(MSD)/usb_host_msd_queue.c \
$(MSD)/usb_host_msd_ufi.c \
$(MFS)/usbmfs.c \

OBJS += \
./USB\ Class\ Drivers/msd/usb_host_msd_bo_c.obj \
./USB\ Class\ Drivers/msd/usb_host_msd_queue_c.obj \
./USB\ Class\ Drivers/msd/usb_host_msd_ufi_c.obj \
./USB\ Class\ Drivers/msd/usbmfs_c.obj \

OBJS_QUOTED += \
"./USB Class Drivers/msd/usb_host_msd_bo_c.obj" \
"./USB Class Drivers/msd/usb_host_msd_queue_c.obj" \
"./USB Class Drivers/msd/usb_host_msd_ufi_c.obj" \
"./USB Class Drivers/msd/usbmfs_c.obj" \

C_DEPS += \
./USB\ Class\ Drivers/msd/usb_host_msd_bo_c.d \
./USB\ Class\ Drivers/msd/usb_host_msd_queue_c.d \
./USB\ Class\ Drivers/msd/usb_host_msd_ufi_c.d \
./USB\ Class\ Drivers/msd/usbmfs_c.d \

C_DEPS_QUOTED += \
"./USB Class Drivers/msd/usb_host_msd_bo_c.d" \
"./USB Class Drivers/msd/usb_host_msd_queue_c.d" \
"./USB Class Drivers/msd/usb_host_msd_ufi_c.d" \
"./USB Class Drivers/msd/usbmfs_c.d" \

OBJS_OS_FORMAT += \
./USB\ Class\ Drivers/msd/usb_host_msd_bo_c.obj \
./USB\ Class\ Drivers/msd/usb_host_msd_queue_c.obj \
./USB\ Class\ Drivers/msd/usb_host_msd_ufi_c.obj \
./USB\ Class\ Drivers/msd/usbmfs_c.obj \


# Each subdirectory must supply rules for building sources it contributes
USB\ Class\ Drivers/msd/usb_host_msd_bo_c.obj: $(MSD)/usb_host_msd_bo.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Class Drivers/msd/usb_host_msd_bo.args" -o "USB Class Drivers/msd/usb_host_msd_bo_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Class\ Drivers/msd/usb_host_msd_bo_c.d: $(MSD)/usb_host_msd_bo.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

USB\ Class\ Drivers/msd/usb_host_msd_queue_c.obj: $(MSD)/usb_host_msd_queue.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Class Drivers/msd/usb_host_msd_queue.args" -o "USB Class Drivers/msd/usb_host_msd_queue_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Class\ Drivers/msd/usb_host_msd_queue_c.d: $(MSD)/usb_host_msd_queue.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

USB\ Class\ Drivers/msd/usb_host_msd_ufi_c.obj: $(MSD)/usb_host_msd_ufi.c
	@echo 'Building file: $<'
	@echo 'Executing target #17 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Class Drivers/msd/usb_host_msd_ufi.args" -o "USB Class Drivers/msd/usb_host_msd_ufi_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Class\ Drivers/msd/usb_host_msd_ufi_c.d: $(MSD)/usb_host_msd_ufi.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

USB\ Class\ Drivers/msd/usbmfs_c.obj: $(MFS)/usbmfs.c
	@echo 'Building file: $<'
	@echo 'Executing target #18 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Class Drivers/msd/usbmfs.args" -o "USB Class Drivers/msd/usbmfs_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Class\ Drivers/msd/usbmfs_c.d: $(MFS)/usbmfs.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


