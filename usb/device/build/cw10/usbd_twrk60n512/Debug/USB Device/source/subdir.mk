################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"$(DEVICE)/dev_cncl.c" \
"$(DEVICE)/dev_ep_deinit.c" \
"$(DEVICE)/dev_main.c" \
"$(DEVICE)/dev_recv.c" \
"$(DEVICE)/dev_send.c" \
"$(DEVICE)/dev_shut.c" \
"$(DEVICE)/dev_utl.c" \

C_SRCS += \
$(DEVICE)/dev_cncl.c \
$(DEVICE)/dev_ep_deinit.c \
$(DEVICE)/dev_main.c \
$(DEVICE)/dev_recv.c \
$(DEVICE)/dev_send.c \
$(DEVICE)/dev_shut.c \
$(DEVICE)/dev_utl.c \

OBJS += \
./USB\ Device/source/dev_cncl_c.obj \
./USB\ Device/source/dev_ep_deinit_c.obj \
./USB\ Device/source/dev_main_c.obj \
./USB\ Device/source/dev_recv_c.obj \
./USB\ Device/source/dev_send_c.obj \
./USB\ Device/source/dev_shut_c.obj \
./USB\ Device/source/dev_utl_c.obj \

OBJS_QUOTED += \
"./USB Device/source/dev_cncl_c.obj" \
"./USB Device/source/dev_ep_deinit_c.obj" \
"./USB Device/source/dev_main_c.obj" \
"./USB Device/source/dev_recv_c.obj" \
"./USB Device/source/dev_send_c.obj" \
"./USB Device/source/dev_shut_c.obj" \
"./USB Device/source/dev_utl_c.obj" \

C_DEPS += \
./USB\ Device/source/dev_cncl_c.d \
./USB\ Device/source/dev_ep_deinit_c.d \
./USB\ Device/source/dev_main_c.d \
./USB\ Device/source/dev_recv_c.d \
./USB\ Device/source/dev_send_c.d \
./USB\ Device/source/dev_shut_c.d \
./USB\ Device/source/dev_utl_c.d \

C_DEPS_QUOTED += \
"./USB Device/source/dev_cncl_c.d" \
"./USB Device/source/dev_ep_deinit_c.d" \
"./USB Device/source/dev_main_c.d" \
"./USB Device/source/dev_recv_c.d" \
"./USB Device/source/dev_send_c.d" \
"./USB Device/source/dev_shut_c.d" \
"./USB Device/source/dev_utl_c.d" \

OBJS_OS_FORMAT += \
./USB\ Device/source/dev_cncl_c.obj \
./USB\ Device/source/dev_ep_deinit_c.obj \
./USB\ Device/source/dev_main_c.obj \
./USB\ Device/source/dev_recv_c.obj \
./USB\ Device/source/dev_send_c.obj \
./USB\ Device/source/dev_shut_c.obj \
./USB\ Device/source/dev_utl_c.obj \


# Each subdirectory must supply rules for building sources it contributes
USB\ Device/source/dev_cncl_c.obj: $(DEVICE)/dev_cncl.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Device/source/dev_cncl.args" -o "USB Device/source/dev_cncl_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Device/source/dev_cncl_c.d: $(DEVICE)/dev_cncl.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

USB\ Device/source/dev_ep_deinit_c.obj: $(DEVICE)/dev_ep_deinit.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Device/source/dev_ep_deinit.args" -o "USB Device/source/dev_ep_deinit_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Device/source/dev_ep_deinit_c.d: $(DEVICE)/dev_ep_deinit.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

USB\ Device/source/dev_main_c.obj: $(DEVICE)/dev_main.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Device/source/dev_main.args" -o "USB Device/source/dev_main_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Device/source/dev_main_c.d: $(DEVICE)/dev_main.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

USB\ Device/source/dev_recv_c.obj: $(DEVICE)/dev_recv.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Device/source/dev_recv.args" -o "USB Device/source/dev_recv_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Device/source/dev_recv_c.d: $(DEVICE)/dev_recv.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

USB\ Device/source/dev_send_c.obj: $(DEVICE)/dev_send.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Device/source/dev_send.args" -o "USB Device/source/dev_send_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Device/source/dev_send_c.d: $(DEVICE)/dev_send.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

USB\ Device/source/dev_shut_c.obj: $(DEVICE)/dev_shut.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Device/source/dev_shut.args" -o "USB Device/source/dev_shut_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Device/source/dev_shut_c.d: $(DEVICE)/dev_shut.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

USB\ Device/source/dev_utl_c.obj: $(DEVICE)/dev_utl.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Device/source/dev_utl.args" -o "USB Device/source/dev_utl_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Device/source/dev_utl_c.d: $(DEVICE)/dev_utl.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


