################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 25
first : all
-include ../makefile.init

# This file contains definitions of environment variables used in the makefiles and .args files if exist.
-include makefile.local

RM := "$(GNU_Make_Install_DirEnv)/rm -f"

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include USB\ Low\ Level\ Driver/khci/subdir.mk
-include USB\ Host/source/subdir.mk
-include USB\ Host/os/subdir.mk
-include USB\ Class\ Drivers/printer/subdir.mk
-include USB\ Class\ Drivers/phdc/subdir.mk
-include USB\ Class\ Drivers/msd/subdir.mk
-include USB\ Class\ Drivers/hub/subdir.mk
-include USB\ Class\ Drivers/hid/subdir.mk
-include USB\ Class\ Drivers/cdc/subdir.mk
-include USB\ Class\ Drivers/audio/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
$(USB)/usbh.a \

EXECUTABLES_QUOTED += \
"$(USB)/usbh.a" \

EXECUTABLES_OS_FORMAT += \
$(USB)/usbh.a \


# All Target
all: warning-messages explicit-dependencies $(USB)/usbh.a

# Tool invocations
$(USB)/usbh.a: $(OBJS) $(LCF_BUILD_DEPENCENCY) $(USER_OBJS) $(LCF_SRCS)
	@echo 'Building target: $@'
	@echo 'Executing target #26 $@'
	@echo 'Invoking: ARM Linker'
	"$(ARM_ToolsDirEnv)/mwldarm" -o "$(USB)/usbh.a" @@"usbh.args"  $(USER_OBJS_QUOTED) $(LIBS_QUOTED)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(S_DEPS_QUOTED) $(CC_DEPS_QUOTED) $(CPP_DEPS_QUOTED) "./*/*/*.obj"  $(S_UPPER_DEPS_QUOTED) $(CXX_DEPS_QUOTED) $(ASM_DEPS_QUOTED) $(ASM_UPPER_DEPS_QUOTED) $(C_UPPER_DEPS_QUOTED) $(EXECUTABLES_QUOTED) "./*/*/*.d"  $(USB)/usbh.a
	-@echo ' '

post-build:
	-"D:\projects\Freescale\Freescale_MQX_4_0\usb\host\build\cw10\usbh_twrk60n512\..\..\..\..\../usb/host/build/bat/usbh_twrk60n512.bat" "D:\projects\Freescale\Freescale_MQX_4_0\usb\host\build\cw10\usbh_twrk60n512\..\..\..\..\.." "D:\projects\Freescale\Freescale_MQX_4_0\usb\host\build\cw10\usbh_twrk60n512\..\..\..\..\../lib/twrk60n512.cw10/debug/usb" cw10
	-@echo ' '

.PHONY: all clean dependents explicit-dependencies warning-messages
.SECONDARY: post-build

-include ../makefile.targets

explicit-dependencies: 

warning-messages: 

