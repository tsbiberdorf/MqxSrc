################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"$(KHCI)/khci.c" \

C_SRCS += \
$(KHCI)/khci.c \

OBJS += \
./USB\ Low\ Level\ Driver/khci/khci_c.obj \

OBJS_QUOTED += \
"./USB Low Level Driver/khci/khci_c.obj" \

C_DEPS += \
./USB\ Low\ Level\ Driver/khci/khci_c.d \

C_DEPS_QUOTED += \
"./USB Low Level Driver/khci/khci_c.d" \

OBJS_OS_FORMAT += \
./USB\ Low\ Level\ Driver/khci/khci_c.obj \


# Each subdirectory must supply rules for building sources it contributes
USB\ Low\ Level\ Driver/khci/khci_c.obj: $(KHCI)/khci.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Low Level Driver/khci/khci.args" -o "USB Low Level Driver/khci/khci_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Low\ Level\ Driver/khci/khci_c.d: $(KHCI)/khci.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


