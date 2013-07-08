################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"$(SNMP)/snmp_demo.c" \
"$(SNMP)/snmptraps.c" \

C_SRCS += \
$(SNMP)/snmp_demo.c \
$(SNMP)/snmptraps.c \

OBJS += \
./Source/snmp_demo_c.obj \
./Source/snmptraps_c.obj \

OBJS_QUOTED += \
"./Source/snmp_demo_c.obj" \
"./Source/snmptraps_c.obj" \

C_DEPS += \
./Source/snmp_demo_c.d \
./Source/snmptraps_c.d \

C_DEPS_QUOTED += \
"./Source/snmp_demo_c.d" \
"./Source/snmptraps_c.d" \

OBJS_OS_FORMAT += \
./Source/snmp_demo_c.obj \
./Source/snmptraps_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Source/snmp_demo_c.obj: $(SNMP)/snmp_demo.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Source/snmp_demo.args" -o "Source/snmp_demo_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Source/snmp_demo_c.d: $(SNMP)/snmp_demo.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Source/snmptraps_c.obj: $(SNMP)/snmptraps.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Source/snmptraps.args" -o "Source/snmptraps_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Source/snmptraps_c.d: $(SNMP)/snmptraps.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


