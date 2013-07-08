#------------------------------------------------------------
# use specific TOOLCHAIN_ROOTDIR if not set in global.mak
#------------------------------------------------------------
#TOOLCHAIN_ROOTDIR = C:/FREESC~1/CWMCUV~1.2

#------------------------------------------------------------
# toolchain settings
#------------------------------------------------------------
AS = $(TOOLCHAIN_ROOTDIR)/MCU/ARM_Tools/Command_Line_Tools/mwasmarm.exe 
CC = $(TOOLCHAIN_ROOTDIR)/MCU/ARM_Tools/Command_Line_Tools/mwccarm.exe 
CX = $(TOOLCHAIN_ROOTDIR)/MCU/ARM_Tools/Command_Line_Tools/mwccarm.exe 
AR = $(TOOLCHAIN_ROOTDIR)/MCU/ARM_Tools/Command_Line_Tools/mwldarm.exe 
LD = $(TOOLCHAIN_ROOTDIR)/MCU/ARM_Tools/Command_Line_Tools/mwldarm.exe 

#------------------------------------------------------------
# toolchain macros
# $(1) - output file path
# $(2) - list of object files
# $(3) - file contains list of object files
#------------------------------------------------------------
AS_PROCESS = $(AS) $(2) -o $(1) $(AS_DEFINE) $(AS_FLAGS) $(addprefix -I,$(INCLUDE)) 
CC_PROCESS = $(CC) $(2) -o $(1) $(CC_DEFINE) $(CC_FLAGS) $(addprefix -I,$(INCLUDE)) -MDfile $(DEPENDS_DIR)/$(notdir $(basename $(1))).d 
CX_PROCESS = $(CX) $(2) -o $(1) $(CX_DEFINE) $(CX_FLAGS) $(addprefix -I,$(INCLUDE)) -MDfile $(DEPENDS_DIR)/$(notdir $(basename $(1))).d 
AR_PROCESS = $(AR) $(AR_FLAGS) -library @"$(3)" -o $(1) 
LD_PROCESS = $(LD) $(LD_FLAGS) -application @"$(3)" $(addprefix -l,$(LIBRARIES)) $(addprefix -l,$(RT_LIBRARIES)) $(LINKER_FILE) -o $(1) 



LD_FLAGS += -L"$(TOOLCHAIN_ROOTDIR)/MCU/ARM_EABI_Support/ewl/lib"


#------------------------------------------------------------
# tool extensions 
#------------------------------------------------------------
LIBRARY_EXT     = a
APPLICATION_EXT = afx

#------------------------------------------------------------
# all configs, just to avoid typo
#------------------------------------------------------------
CONFIG_LIST = debug release 

#------------------------------------------------------------
# tool libraries
#------------------------------------------------------------


#------------------------------------------------------------
# tool include
#------------------------------------------------------------
INCLUDE += $(TOOLCHAIN_ROOTDIR)/MCU/ARM_EABI_Support/ewl/EWL_C/include



#------------------------------------------------------------
# libraries tool options 
#------------------------------------------------------------
ifeq ($(TYPE),library)

### 'debug' configuration
ifeq ($(CONFIG),debug)
ifeq ($(NAME),psp)
CC_FLAGS += -opt level=0 -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -Cpp_Exceptions off -RTTI off -opt space -lang c99 
CX_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -opt space -lang c++ 
AS_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g -nosyspath 
AR_FLAGS += -proc cortex-m4 -fp vfpv4 -sreclength 80 -srec -map -library -nostdlib -interworking -thumb -g3 -msgstyle parseable -little 
LD_FLAGS += -proc cortex-m4 -fp vfpv4 -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -nostdlib -main __boot -map -map closure -map keep -srec -sreclength 80 -little 
CC_DEFINE += -DMQX_DISABLE_CONFIG_CHECK=1 -D_DEBUG=1 -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
CX_DEFINE += -D_DEBUG=1 
AS_DEFINE += -D_DEBUG=1 -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
endif
ifeq ($(NAME),shell)
CC_FLAGS += -opt level=0 -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -Cpp_Exceptions off -RTTI off -opt space -lang c99 
CX_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -opt space -lang c++ 
AS_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g -nosyspath 
AR_FLAGS += -proc cortex-m4 -fp vfpv4 -sreclength 80 -srec -map -library -nostdlib -interworking -thumb -g3 -msgstyle parseable -little 
LD_FLAGS += -proc cortex-m4 -fp vfpv4 -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -nostdlib -main __boot -map -map closure -map keep -srec -sreclength 80 -little 
CC_DEFINE += -D_DEBUG=1 -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
CX_DEFINE += -D_DEBUG=1 
AS_DEFINE += -D_DEBUG=1 -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
endif
ifeq ($(NAME),usbd)
CC_FLAGS += -opt level=0 -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -Cpp_Exceptions off -RTTI off -opt space -lang c99 
CX_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -opt space -lang c++ 
AS_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g -nosyspath 
AR_FLAGS += -proc cortex-m4 -fp vfpv4 -sreclength 80 -srec -map -library -nostdlib -interworking -thumb -g3 -msgstyle parseable -little 
LD_FLAGS += -proc cortex-m4 -fp vfpv4 -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -nostdlib -main __boot -map -map closure -map keep -srec -sreclength 80 -little 
CC_DEFINE += -D_DEBUG=1 -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
CX_DEFINE += -D_DEBUG=1 
AS_DEFINE += -D_DEBUG=1 -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
endif
ifeq ($(NAME),usbh)
CC_FLAGS += -opt level=0 -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -Cpp_Exceptions off -RTTI off -opt space -lang c99 
CX_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -opt space -lang c++ 
AS_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g -nosyspath 
AR_FLAGS += -proc cortex-m4 -fp vfpv4 -sreclength 80 -srec -map -library -nostdlib -interworking -thumb -g3 -msgstyle parseable -little 
LD_FLAGS += -proc cortex-m4 -fp vfpv4 -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -nostdlib -main __boot -map -map closure -map keep -srec -sreclength 80 -little 
CC_DEFINE += -D_DEBUG=1 -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
CX_DEFINE += -D_DEBUG=1 
AS_DEFINE += -D_DEBUG=1 -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
endif
ifeq ($(NAME),mfs)
CC_FLAGS += -opt level=0 -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -Cpp_Exceptions off -RTTI off -opt space -lang c99 
CX_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -opt space -lang c++ 
AS_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g -nosyspath 
AR_FLAGS += -proc cortex-m4 -fp vfpv4 -sreclength 80 -srec -map -library -nostdlib -interworking -thumb -g3 -msgstyle parseable -little 
LD_FLAGS += -proc cortex-m4 -fp vfpv4 -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -nostdlib -main __boot -map -map closure -map keep -srec -sreclength 80 -little 
CC_DEFINE += -D_DEBUG=1 -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
CX_DEFINE += -D_DEBUG=1 
AS_DEFINE += -D_DEBUG=1 -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
endif
ifeq ($(NAME),bsp)
CC_FLAGS += -opt level=0 -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -Cpp_Exceptions off -RTTI off -opt space -lang c99 
CX_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -opt space -lang c++ 
AS_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g -nosyspath 
AR_FLAGS += -proc cortex-m4 -fp vfpv4 -sreclength 80 -srec -map -library -nostdlib -interworking -thumb -g3 -msgstyle parseable -little 
LD_FLAGS += -proc cortex-m4 -fp vfpv4 -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -nostdlib -main __boot -map -map closure -map keep -srec -sreclength 80 -little 
CC_DEFINE += -D_DEBUG=1 -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
CX_DEFINE += -D_DEBUG=1 
AS_DEFINE += -D_DEBUG=1 -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
endif
ifeq ($(NAME),rtcs)
CC_FLAGS += -opt level=0 -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -Cpp_Exceptions off -RTTI off -opt space -lang c99 
CX_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -opt space -lang c++ 
AS_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g -nosyspath 
AR_FLAGS += -proc cortex-m4 -fp vfpv4 -sreclength 80 -srec -map -library -nostdlib -interworking -thumb -g3 -msgstyle parseable -little 
LD_FLAGS += -proc cortex-m4 -fp vfpv4 -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -nostdlib -main __boot -map -map closure -map keep -srec -sreclength 80 -little 
CC_DEFINE += -D_DEBUG=1 -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
CX_DEFINE += -D_DEBUG=1 
AS_DEFINE += -D_DEBUG=1 -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
endif
endif

### 'release' configuration
ifeq ($(CONFIG),release)
ifeq ($(NAME),psp)
CC_FLAGS += -opt level=4 -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -Cpp_Exceptions off -RTTI off -opt space -lang c99 
CX_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -opt space -lang c++ 
AS_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g -nosyspath 
AR_FLAGS += -proc cortex-m4 -fp vfpv4 -sreclength 80 -srec -map -library -nostdlib -interworking -thumb -g3 -msgstyle parseable -little 
LD_FLAGS += -proc cortex-m4 -fp vfpv4 -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -nostdlib -main __boot -map -map closure -map keep -srec -sreclength 80 -little 
CC_DEFINE += -DMQX_DISABLE_CONFIG_CHECK=1 -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
CX_DEFINE += 
AS_DEFINE += -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
endif
ifeq ($(NAME),shell)
CC_FLAGS += -opt level=4 -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -Cpp_Exceptions off -RTTI off -opt space -lang c99 
CX_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -opt space -lang c++ 
AS_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g -nosyspath 
AR_FLAGS += -proc cortex-m4 -fp vfpv4 -sreclength 80 -srec -map -library -nostdlib -interworking -thumb -g3 -msgstyle parseable -little 
LD_FLAGS += -proc cortex-m4 -fp vfpv4 -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -nostdlib -main __boot -map -map closure -map keep -srec -sreclength 80 -little 
CC_DEFINE += -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
CX_DEFINE += 
AS_DEFINE += -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
endif
ifeq ($(NAME),usbd)
CC_FLAGS += -opt level=4 -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -Cpp_Exceptions off -RTTI off -opt space -lang c99 
CX_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -opt space -lang c++ 
AS_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g -nosyspath 
AR_FLAGS += -proc cortex-m4 -fp vfpv4 -sreclength 80 -srec -map -library -nostdlib -interworking -thumb -g3 -msgstyle parseable -little 
LD_FLAGS += -proc cortex-m4 -fp vfpv4 -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -nostdlib -main __boot -map -map closure -map keep -srec -sreclength 80 -little 
CC_DEFINE += -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
CX_DEFINE += 
AS_DEFINE += -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
endif
ifeq ($(NAME),usbh)
CC_FLAGS += -opt level=4 -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -Cpp_Exceptions off -RTTI off -opt space -lang c99 
CX_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -opt space -lang c++ 
AS_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g -nosyspath 
AR_FLAGS += -proc cortex-m4 -fp vfpv4 -sreclength 80 -srec -map -library -nostdlib -interworking -thumb -g3 -msgstyle parseable -little 
LD_FLAGS += -proc cortex-m4 -fp vfpv4 -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -nostdlib -main __boot -map -map closure -map keep -srec -sreclength 80 -little 
CC_DEFINE += -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
CX_DEFINE += 
AS_DEFINE += -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
endif
ifeq ($(NAME),mfs)
CC_FLAGS += -opt level=4 -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -Cpp_Exceptions off -RTTI off -opt space -lang c99 
CX_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -opt space -lang c++ 
AS_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g -nosyspath 
AR_FLAGS += -proc cortex-m4 -fp vfpv4 -sreclength 80 -srec -map -library -nostdlib -interworking -thumb -g3 -msgstyle parseable -little 
LD_FLAGS += -proc cortex-m4 -fp vfpv4 -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -nostdlib -main __boot -map -map closure -map keep -srec -sreclength 80 -little 
CC_DEFINE += -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
CX_DEFINE += 
AS_DEFINE += -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
endif
ifeq ($(NAME),bsp)
CC_FLAGS += -opt level=4 -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -Cpp_Exceptions off -RTTI off -opt space -lang c99 
CX_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -opt space -lang c++ 
AS_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g -nosyspath 
AR_FLAGS += -proc cortex-m4 -fp vfpv4 -sreclength 80 -srec -map -library -nostdlib -interworking -thumb -g3 -msgstyle parseable -little 
LD_FLAGS += -proc cortex-m4 -fp vfpv4 -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -nostdlib -main __boot -map -map closure -map keep -srec -sreclength 80 -little 
CC_DEFINE += -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
CX_DEFINE += 
AS_DEFINE += -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
endif
ifeq ($(NAME),rtcs)
CC_FLAGS += -opt level=4 -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -Cpp_Exceptions off -RTTI off -opt space -lang c99 
CX_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -opt space -lang c++ 
AS_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g -nosyspath 
AR_FLAGS += -proc cortex-m4 -fp vfpv4 -sreclength 80 -srec -map -library -nostdlib -interworking -thumb -g3 -msgstyle parseable -little 
LD_FLAGS += -proc cortex-m4 -fp vfpv4 -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -nostdlib -main __boot -map -map closure -map keep -srec -sreclength 80 -little 
CC_DEFINE += -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
CX_DEFINE += 
AS_DEFINE += -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
endif
endif

endif

#------------------------------------------------------------
# applications tool options 
#------------------------------------------------------------
ifeq ($(TYPE),application)

ifeq ($(CONFIG),debug)
CC_FLAGS += -opt level=0 -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -Cpp_Exceptions off -RTTI off -opt space -lang c99 
CX_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -opt space -lang c++ 
AS_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g -nosyspath 
AR_FLAGS += -proc cortex-m4 -fp vfpv4 -sreclength 80 -srec -map -library -nostdlib -interworking -thumb -g3 -msgstyle parseable -little 
LD_FLAGS += -proc cortex-m4 -fp vfpv4 -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -nostdlib -main __boot -map -map closure -map keep -srec -sreclength 80 -little 
CC_DEFINE += -D_DEBUG=1 -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
CX_DEFINE += -D_DEBUG=1 
AS_DEFINE += -D_DEBUG=1 -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
endif
ifeq ($(CONFIG),release)
CC_FLAGS += -opt level=4 -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -Cpp_Exceptions off -RTTI off -opt space -lang c99 
CX_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -cwd include -nosyspath -nolink -enc ascii -w illpragmas -w possible -w missingreturn -w extracomma -w empty -inline on -generic_symbol_names off -sdata 8 -enum int -char signed -opt space -lang c++ 
AS_FLAGS += -proc cortex-m4 -fp vfpv4 -little -msgstyle parseable -g -nosyspath 
AR_FLAGS += -proc cortex-m4 -fp vfpv4 -sreclength 80 -srec -map -library -nostdlib -interworking -thumb -g3 -msgstyle parseable -little 
LD_FLAGS += -proc cortex-m4 -fp vfpv4 -msgstyle parseable -g3 -thumb -interworking -lavender model=ewl ,print=int ,scan=int ,io=raw -nostdlib -main __boot -map -map closure -map keep -srec -sreclength 80 -little 
CC_DEFINE += -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
CX_DEFINE += 
AS_DEFINE += -D_EWL_FLOATING_POINT=1 -D__CWARM__=1 -D__CODEWARRIOR__=1 
endif

endif

