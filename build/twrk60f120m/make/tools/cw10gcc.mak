#------------------------------------------------------------
# use specific TOOLCHAIN_ROOTDIR if not set in global.mak
#------------------------------------------------------------
#TOOLCHAIN_ROOTDIR = C:/FREESC~1/CWMCUV~1.3

#------------------------------------------------------------
# toolchain settings
#------------------------------------------------------------
AS = $(TOOLCHAIN_ROOTDIR)/Cross_Tools/arm-none-eabi-gcc-4_6_2/bin/arm-none-eabi-gcc.exe 
CC = $(TOOLCHAIN_ROOTDIR)/Cross_Tools/arm-none-eabi-gcc-4_6_2/bin/arm-none-eabi-gcc.exe 
CX = $(TOOLCHAIN_ROOTDIR)/Cross_Tools/arm-none-eabi-gcc-4_6_2/bin/arm-none-eabi-gcc.exe 
AR = $(TOOLCHAIN_ROOTDIR)/Cross_Tools/arm-none-eabi-gcc-4_6_2/bin/arm-none-eabi-ar.exe 
LD = $(TOOLCHAIN_ROOTDIR)/Cross_Tools/arm-none-eabi-gcc-4_6_2/bin/arm-none-eabi-gcc.exe 

#------------------------------------------------------------
# toolchain macros
# $(1) - output file path
# $(2) - list of object files
# $(3) - file contains list of object files
#------------------------------------------------------------
AS_PROCESS = $(AS) -x assembler-with-cpp -Wall $(AS_FLAGS) $(AS_DEFINE) $(addprefix -I,$(INCLUDE)) -c $(2) -o $(1) 
CC_PROCESS = $(CC) $(CC_FLAGS) $(CC_DEFINE) $(addprefix -I,$(INCLUDE)) -c $(2) -o $(1) 
CX_PROCESS = $(CX) $(CX_FLAGS) $(CX_DEFINE) $(addprefix -I,$(INCLUDE)) -c $(2) -o $(1) 
AR_PROCESS = $(MQX_ROOTDIR)/build/common/make/repl.exe \\ / < $(3) > $(3)2 & $(AR) $(AR_FLAGS) -r $(1) @"$(3)2" 
LD_PROCESS = $(MQX_ROOTDIR)/build/common/make/repl.exe \\ / < $(3) > $(3)2 & $(LD) $(LD_FLAGS) @"$(3)2" -T$(LINKER_FILE) -o $(1) \
-Xlinker -Map=$(basename $(1)).map \
-Xlinker --start-group \
$(LIBRARIES) $(RT_LIBRARIES) \
-Xlinker --end-group \




#------------------------------------------------------------
# tool extensions 
#------------------------------------------------------------
LIBRARY_EXT     = a
APPLICATION_EXT = elf

#------------------------------------------------------------
# all configs, just to avoid typo
#------------------------------------------------------------
CONFIG_LIST = debug release 

#------------------------------------------------------------
# tool libraries
#------------------------------------------------------------
RT_LIBRARIES += $(TOOLCHAIN_ROOTDIR)/MCU/ARM_GCC_Support/ewl/lib/armv7e-m/__arm_start.o
RT_LIBRARIES += $(TOOLCHAIN_ROOTDIR)/MCU/ARM_GCC_Support/ewl/lib/armv7e-m/__arm_end.o
RT_LIBRARIES += $(TOOLCHAIN_ROOTDIR)/MCU/ARM_GCC_Support/ewl/lib/armv7e-m/librt.a
RT_LIBRARIES += $(TOOLCHAIN_ROOTDIR)/MCU/ARM_GCC_Support/ewl/lib/armv7e-m/libc.a
RT_LIBRARIES += $(TOOLCHAIN_ROOTDIR)/MCU/ARM_GCC_Support/ewl/lib/armv7e-m/libm.a
RT_LIBRARIES += $(TOOLCHAIN_ROOTDIR)/MCU/ARM_GCC_Support/ewl/lib/armv7e-m/libc++.a
RT_LIBRARIES += $(TOOLCHAIN_ROOTDIR)/MCU/ARM_GCC_Support/ewl/lib/armv7e-m/libstdc++.a
RT_LIBRARIES += $(TOOLCHAIN_ROOTDIR)/Cross_Tools/arm-none-eabi-gcc-4_6_2/lib/gcc/arm-none-eabi/4.6.2/armv7e-m/libgcc.a
RT_LIBRARIES += $(TOOLCHAIN_ROOTDIR)/Cross_Tools/arm-none-eabi-gcc-4_6_2/arm-none-eabi/lib/armv7e-m/libsupc++.a


#------------------------------------------------------------
# tool include
#------------------------------------------------------------
INCLUDE += $(TOOLCHAIN_ROOTDIR)/MCU/ARM_GCC_Support/ewl/EWL_Runtime/include
INCLUDE += $(TOOLCHAIN_ROOTDIR)/MCU/ARM_GCC_Support/ewl/EWL_C/include



#------------------------------------------------------------
# libraries tool options 
#------------------------------------------------------------
ifeq ($(TYPE),library)

### 'debug' configuration
ifeq ($(CONFIG),debug)
ifeq ($(NAME),psp)
CC_FLAGS += -O0 -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostdinc -ffunction-sections -fdata-sections -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
CX_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -nostdinc -nostdinc++ -ffunction-sections -fdata-sections -fno-exceptions -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AS_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AR_FLAGS += 
LD_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostartfiles -nodefaultlibs -nostdlib -Xlinker --gc-sections -Xlinker -cref -Xlinker -static -mthumb -g2 -gdwarf-2 -gstrict-dwarf -Xlinker -z -Xlinker muldefs 
CC_DEFINE += -DMQX_DISABLE_CONFIG_CHECK=1 -D__VFPV4__=1 -D_DEBUG=1 
CX_DEFINE += -D__VFPV4__=1 -D_DEBUG=1 
AS_DEFINE += -D_DEBUG=1 
endif
ifeq ($(NAME),shell)
CC_FLAGS += -O0 -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostdinc -ffunction-sections -fdata-sections -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
CX_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -nostdinc -nostdinc++ -ffunction-sections -fdata-sections -fno-exceptions -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AS_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AR_FLAGS += 
LD_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostartfiles -nodefaultlibs -nostdlib -Xlinker --gc-sections -Xlinker -cref -Xlinker -static -mthumb -g2 -gdwarf-2 -gstrict-dwarf -Xlinker -z -Xlinker muldefs 
CC_DEFINE += -D__VFPV4__=1 -D_DEBUG=1 
CX_DEFINE += -D__VFPV4__=1 -D_DEBUG=1 
AS_DEFINE += -D_DEBUG=1 
endif
ifeq ($(NAME),usbd)
CC_FLAGS += -O0 -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostdinc -ffunction-sections -fdata-sections -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
CX_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -nostdinc -nostdinc++ -ffunction-sections -fdata-sections -fno-exceptions -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AS_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AR_FLAGS += 
LD_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostartfiles -nodefaultlibs -nostdlib -Xlinker --gc-sections -Xlinker -cref -Xlinker -static -mthumb -g2 -gdwarf-2 -gstrict-dwarf -Xlinker -z -Xlinker muldefs 
CC_DEFINE += -D__VFPV4__=1 -D_DEBUG=1 
CX_DEFINE += -D__VFPV4__=1 -D_DEBUG=1 
AS_DEFINE += -D_DEBUG=1 
endif
ifeq ($(NAME),usbh)
CC_FLAGS += -O0 -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostdinc -ffunction-sections -fdata-sections -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
CX_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -nostdinc -nostdinc++ -ffunction-sections -fdata-sections -fno-exceptions -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AS_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AR_FLAGS += 
LD_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostartfiles -nodefaultlibs -nostdlib -Xlinker --gc-sections -Xlinker -cref -Xlinker -static -mthumb -g2 -gdwarf-2 -gstrict-dwarf -Xlinker -z -Xlinker muldefs 
CC_DEFINE += -D__VFPV4__=1 -D_DEBUG=1 
CX_DEFINE += -D__VFPV4__=1 -D_DEBUG=1 
AS_DEFINE += -D_DEBUG=1 
endif
ifeq ($(NAME),mfs)
CC_FLAGS += -O0 -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostdinc -ffunction-sections -fdata-sections -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
CX_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -nostdinc -nostdinc++ -ffunction-sections -fdata-sections -fno-exceptions -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AS_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AR_FLAGS += 
LD_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostartfiles -nodefaultlibs -nostdlib -Xlinker --gc-sections -Xlinker -cref -Xlinker -static -mthumb -g2 -gdwarf-2 -gstrict-dwarf -Xlinker -z -Xlinker muldefs 
CC_DEFINE += -D__VFPV4__=1 -D_DEBUG=1 
CX_DEFINE += -D__VFPV4__=1 -D_DEBUG=1 
AS_DEFINE += -D_DEBUG=1 
endif
ifeq ($(NAME),bsp)
CC_FLAGS += -O0 -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostdinc -ffunction-sections -fdata-sections -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
CX_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -nostdinc -nostdinc++ -ffunction-sections -fdata-sections -fno-exceptions -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AS_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AR_FLAGS += 
LD_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostartfiles -nodefaultlibs -nostdlib -Xlinker --gc-sections -Xlinker -cref -Xlinker -static -mthumb -g2 -gdwarf-2 -gstrict-dwarf -Xlinker -z -Xlinker muldefs 
CC_DEFINE += -D__VFPV4__=1 -D_DEBUG=1 
CX_DEFINE += -D__VFPV4__=1 -D_DEBUG=1 
AS_DEFINE += -D_DEBUG=1 
endif
ifeq ($(NAME),rtcs)
CC_FLAGS += -O0 -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostdinc -ffunction-sections -fdata-sections -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
CX_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -nostdinc -nostdinc++ -ffunction-sections -fdata-sections -fno-exceptions -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AS_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AR_FLAGS += 
LD_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostartfiles -nodefaultlibs -nostdlib -Xlinker --gc-sections -Xlinker -cref -Xlinker -static -mthumb -g2 -gdwarf-2 -gstrict-dwarf -Xlinker -z -Xlinker muldefs 
CC_DEFINE += -D__VFPV4__=1 -D_DEBUG=1 
CX_DEFINE += -D__VFPV4__=1 -D_DEBUG=1 
AS_DEFINE += -D_DEBUG=1 
endif
endif

### 'release' configuration
ifeq ($(CONFIG),release)
ifeq ($(NAME),psp)
CC_FLAGS += -Os -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostdinc -ffunction-sections -fdata-sections -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
CX_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -nostdinc -nostdinc++ -ffunction-sections -fdata-sections -fno-exceptions -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AS_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AR_FLAGS += 
LD_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostartfiles -nodefaultlibs -nostdlib -Xlinker --gc-sections -Xlinker -cref -Xlinker -static -mthumb -g2 -gdwarf-2 -gstrict-dwarf -Xlinker -z -Xlinker muldefs 
CC_DEFINE += -DMQX_DISABLE_CONFIG_CHECK=1 -D__VFPV4__=1 
CX_DEFINE += -D__VFPV4__=1 
AS_DEFINE += 
endif
ifeq ($(NAME),shell)
CC_FLAGS += -Os -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostdinc -ffunction-sections -fdata-sections -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
CX_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -nostdinc -nostdinc++ -ffunction-sections -fdata-sections -fno-exceptions -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AS_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AR_FLAGS += 
LD_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostartfiles -nodefaultlibs -nostdlib -Xlinker --gc-sections -Xlinker -cref -Xlinker -static -mthumb -g2 -gdwarf-2 -gstrict-dwarf -Xlinker -z -Xlinker muldefs 
CC_DEFINE += -D__VFPV4__=1 
CX_DEFINE += -D__VFPV4__=1 
AS_DEFINE += 
endif
ifeq ($(NAME),usbd)
CC_FLAGS += -Os -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostdinc -ffunction-sections -fdata-sections -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
CX_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -nostdinc -nostdinc++ -ffunction-sections -fdata-sections -fno-exceptions -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AS_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AR_FLAGS += 
LD_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostartfiles -nodefaultlibs -nostdlib -Xlinker --gc-sections -Xlinker -cref -Xlinker -static -mthumb -g2 -gdwarf-2 -gstrict-dwarf -Xlinker -z -Xlinker muldefs 
CC_DEFINE += -D__VFPV4__=1 
CX_DEFINE += -D__VFPV4__=1 
AS_DEFINE += 
endif
ifeq ($(NAME),usbh)
CC_FLAGS += -Os -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostdinc -ffunction-sections -fdata-sections -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
CX_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -nostdinc -nostdinc++ -ffunction-sections -fdata-sections -fno-exceptions -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AS_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AR_FLAGS += 
LD_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostartfiles -nodefaultlibs -nostdlib -Xlinker --gc-sections -Xlinker -cref -Xlinker -static -mthumb -g2 -gdwarf-2 -gstrict-dwarf -Xlinker -z -Xlinker muldefs 
CC_DEFINE += -D__VFPV4__=1 
CX_DEFINE += -D__VFPV4__=1 
AS_DEFINE += 
endif
ifeq ($(NAME),mfs)
CC_FLAGS += -Os -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostdinc -ffunction-sections -fdata-sections -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
CX_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -nostdinc -nostdinc++ -ffunction-sections -fdata-sections -fno-exceptions -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AS_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AR_FLAGS += 
LD_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostartfiles -nodefaultlibs -nostdlib -Xlinker --gc-sections -Xlinker -cref -Xlinker -static -mthumb -g2 -gdwarf-2 -gstrict-dwarf -Xlinker -z -Xlinker muldefs 
CC_DEFINE += -D__VFPV4__=1 
CX_DEFINE += -D__VFPV4__=1 
AS_DEFINE += 
endif
ifeq ($(NAME),bsp)
CC_FLAGS += -Os -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostdinc -ffunction-sections -fdata-sections -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
CX_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -nostdinc -nostdinc++ -ffunction-sections -fdata-sections -fno-exceptions -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AS_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AR_FLAGS += 
LD_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostartfiles -nodefaultlibs -nostdlib -Xlinker --gc-sections -Xlinker -cref -Xlinker -static -mthumb -g2 -gdwarf-2 -gstrict-dwarf -Xlinker -z -Xlinker muldefs 
CC_DEFINE += -D__VFPV4__=1 
CX_DEFINE += -D__VFPV4__=1 
AS_DEFINE += 
endif
ifeq ($(NAME),rtcs)
CC_FLAGS += -Os -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostdinc -ffunction-sections -fdata-sections -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
CX_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -nostdinc -nostdinc++ -ffunction-sections -fdata-sections -fno-exceptions -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AS_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AR_FLAGS += 
LD_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostartfiles -nodefaultlibs -nostdlib -Xlinker --gc-sections -Xlinker -cref -Xlinker -static -mthumb -g2 -gdwarf-2 -gstrict-dwarf -Xlinker -z -Xlinker muldefs 
CC_DEFINE += -D__VFPV4__=1 
CX_DEFINE += -D__VFPV4__=1 
AS_DEFINE += 
endif
endif

endif

#------------------------------------------------------------
# applications tool options 
#------------------------------------------------------------
ifeq ($(TYPE),application)

ifeq ($(CONFIG),debug)
CC_FLAGS += -O0 -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostdinc -ffunction-sections -fdata-sections -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
CX_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -nostdinc -nostdinc++ -ffunction-sections -fdata-sections -fno-exceptions -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AS_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AR_FLAGS += 
LD_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostartfiles -nodefaultlibs -nostdlib -Xlinker --gc-sections -Xlinker -cref -Xlinker -static -mthumb -g2 -gdwarf-2 -gstrict-dwarf -Xlinker -z -Xlinker muldefs 
CC_DEFINE += -D__VFPV4__=1 -D_DEBUG=1 
CX_DEFINE += -D__VFPV4__=1 -D_DEBUG=1 
AS_DEFINE += -D_DEBUG=1 
endif
ifeq ($(CONFIG),release)
CC_FLAGS += -Os -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostdinc -ffunction-sections -fdata-sections -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
CX_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -nostdinc -nostdinc++ -ffunction-sections -fdata-sections -fno-exceptions -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AS_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -Wall -mthumb -g2 -gdwarf-2 -gstrict-dwarf 
AR_FLAGS += 
LD_FLAGS += -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=fpv4-sp-d16 -std=gnu99 -nostartfiles -nodefaultlibs -nostdlib -Xlinker --gc-sections -Xlinker -cref -Xlinker -static -mthumb -g2 -gdwarf-2 -gstrict-dwarf -Xlinker -z -Xlinker muldefs 
CC_DEFINE += -D__VFPV4__=1 
CX_DEFINE += -D__VFPV4__=1 
AS_DEFINE += 
endif

endif

