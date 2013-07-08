################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"$(KHCI)/callback_khci.c" \
"$(KHCI)/khci_dev_main.c" \

C_SRCS += \
$(KHCI)/callback_khci.c \
$(KHCI)/khci_dev_main.c \

OBJS += \
./USB\ Low\ Level\ Driver/khci/callback_khci_c.obj \
./USB\ Low\ Level\ Driver/khci/khci_dev_main_c.obj \

OBJS_QUOTED += \
"./USB Low Level Driver/khci/callback_khci_c.obj" \
"./USB Low Level Driver/khci/khci_dev_main_c.obj" \

C_DEPS += \
./USB\ Low\ Level\ Driver/khci/callback_khci_c.d \
./USB\ Low\ Level\ Driver/khci/khci_dev_main_c.d \

C_DEPS_QUOTED += \
"./USB Low Level Driver/khci/callback_khci_c.d" \
"./USB Low Level Driver/khci/khci_dev_main_c.d" \

OBJS_OS_FORMAT += \
./USB\ Low\ Level\ Driver/khci/callback_khci_c.obj \
./USB\ Low\ Level\ Driver/khci/khci_dev_main_c.obj \


# Each subdirectory must supply rules for building sources it contributes
USB\ Low\ Level\ Driver/khci/callback_khci_c.obj: $(KHCI)/callback_khci.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Low Level Driver/khci/callback_khci.args" -o "USB Low Level Driver/khci/callback_khci_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Low\ Level\ Driver/khci/callback_khci_c.d: $(KHCI)/callback_khci.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

USB\ Low\ Level\ Driver/khci/khci_dev_main_c.obj: $(KHCI)/khci_dev_main.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Low Level Driver/khci/khci_dev_main.args" -o "USB Low Level Driver/khci/khci_dev_main_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Low\ Level\ Driver/khci/khci_dev_main_c.d: $(KHCI)/khci_dev_main.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


