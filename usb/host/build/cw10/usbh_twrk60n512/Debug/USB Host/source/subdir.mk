################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"$(HOST)/host_ch9.c" \
"$(HOST)/host_close.c" \
"$(HOST)/host_cnl.c" \
"$(HOST)/host_common.c" \
"$(HOST)/host_dev_list.c" \
"$(HOST)/host_main.c" \
"$(HOST)/host_rcv.c" \
"$(HOST)/host_shut.c" \
"$(HOST)/host_snd.c" \

C_SRCS += \
$(HOST)/host_ch9.c \
$(HOST)/host_close.c \
$(HOST)/host_cnl.c \
$(HOST)/host_common.c \
$(HOST)/host_dev_list.c \
$(HOST)/host_main.c \
$(HOST)/host_rcv.c \
$(HOST)/host_shut.c \
$(HOST)/host_snd.c \

OBJS += \
./USB\ Host/source/host_ch9_c.obj \
./USB\ Host/source/host_close_c.obj \
./USB\ Host/source/host_cnl_c.obj \
./USB\ Host/source/host_common_c.obj \
./USB\ Host/source/host_dev_list_c.obj \
./USB\ Host/source/host_main_c.obj \
./USB\ Host/source/host_rcv_c.obj \
./USB\ Host/source/host_shut_c.obj \
./USB\ Host/source/host_snd_c.obj \

OBJS_QUOTED += \
"./USB Host/source/host_ch9_c.obj" \
"./USB Host/source/host_close_c.obj" \
"./USB Host/source/host_cnl_c.obj" \
"./USB Host/source/host_common_c.obj" \
"./USB Host/source/host_dev_list_c.obj" \
"./USB Host/source/host_main_c.obj" \
"./USB Host/source/host_rcv_c.obj" \
"./USB Host/source/host_shut_c.obj" \
"./USB Host/source/host_snd_c.obj" \

C_DEPS += \
./USB\ Host/source/host_ch9_c.d \
./USB\ Host/source/host_close_c.d \
./USB\ Host/source/host_cnl_c.d \
./USB\ Host/source/host_common_c.d \
./USB\ Host/source/host_dev_list_c.d \
./USB\ Host/source/host_main_c.d \
./USB\ Host/source/host_rcv_c.d \
./USB\ Host/source/host_shut_c.d \
./USB\ Host/source/host_snd_c.d \

C_DEPS_QUOTED += \
"./USB Host/source/host_ch9_c.d" \
"./USB Host/source/host_close_c.d" \
"./USB Host/source/host_cnl_c.d" \
"./USB Host/source/host_common_c.d" \
"./USB Host/source/host_dev_list_c.d" \
"./USB Host/source/host_main_c.d" \
"./USB Host/source/host_rcv_c.d" \
"./USB Host/source/host_shut_c.d" \
"./USB Host/source/host_snd_c.d" \

OBJS_OS_FORMAT += \
./USB\ Host/source/host_ch9_c.obj \
./USB\ Host/source/host_close_c.obj \
./USB\ Host/source/host_cnl_c.obj \
./USB\ Host/source/host_common_c.obj \
./USB\ Host/source/host_dev_list_c.obj \
./USB\ Host/source/host_main_c.obj \
./USB\ Host/source/host_rcv_c.obj \
./USB\ Host/source/host_shut_c.obj \
./USB\ Host/source/host_snd_c.obj \


# Each subdirectory must supply rules for building sources it contributes
USB\ Host/source/host_ch9_c.obj: $(HOST)/host_ch9.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Host/source/host_ch9.args" -o "USB Host/source/host_ch9_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Host/source/host_ch9_c.d: $(HOST)/host_ch9.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

USB\ Host/source/host_close_c.obj: $(HOST)/host_close.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Host/source/host_close.args" -o "USB Host/source/host_close_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Host/source/host_close_c.d: $(HOST)/host_close.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

USB\ Host/source/host_cnl_c.obj: $(HOST)/host_cnl.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Host/source/host_cnl.args" -o "USB Host/source/host_cnl_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Host/source/host_cnl_c.d: $(HOST)/host_cnl.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

USB\ Host/source/host_common_c.obj: $(HOST)/host_common.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Host/source/host_common.args" -o "USB Host/source/host_common_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Host/source/host_common_c.d: $(HOST)/host_common.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

USB\ Host/source/host_dev_list_c.obj: $(HOST)/host_dev_list.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Host/source/host_dev_list.args" -o "USB Host/source/host_dev_list_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Host/source/host_dev_list_c.d: $(HOST)/host_dev_list.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

USB\ Host/source/host_main_c.obj: $(HOST)/host_main.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Host/source/host_main.args" -o "USB Host/source/host_main_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Host/source/host_main_c.d: $(HOST)/host_main.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

USB\ Host/source/host_rcv_c.obj: $(HOST)/host_rcv.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Host/source/host_rcv.args" -o "USB Host/source/host_rcv_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Host/source/host_rcv_c.d: $(HOST)/host_rcv.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

USB\ Host/source/host_shut_c.obj: $(HOST)/host_shut.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Host/source/host_shut.args" -o "USB Host/source/host_shut_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Host/source/host_shut_c.d: $(HOST)/host_shut.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

USB\ Host/source/host_snd_c.obj: $(HOST)/host_snd.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Host/source/host_snd.args" -o "USB Host/source/host_snd_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Host/source/host_snd_c.d: $(HOST)/host_snd.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


