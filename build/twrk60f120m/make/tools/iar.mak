#------------------------------------------------------------
# use specific TOOLCHAIN_ROOTDIR if not set in global.mak
#------------------------------------------------------------
#TOOLCHAIN_ROOTDIR = C:/PROGRA~1/IARSYS~1/EMBEDD~1.0

#------------------------------------------------------------
# toolchain settings
#------------------------------------------------------------
AS = $(TOOLCHAIN_ROOTDIR)/ARM/BIN/iasmarm.exe 
CC = $(TOOLCHAIN_ROOTDIR)/ARM/BIN/iccarm.exe 
CX = $(TOOLCHAIN_ROOTDIR)/ARM/BIN/iccarm.exe 
AR = $(TOOLCHAIN_ROOTDIR)/ARM/BIN/iarchive.exe 
LD = $(TOOLCHAIN_ROOTDIR)/ARM/BIN/ilinkarm.exe 

#------------------------------------------------------------
# toolchain macros
# $(1) - output file path
# $(2) - list of object files
# $(3) - file contains list of object files
#------------------------------------------------------------
AS_PROCESS = $(AS) $(2) -o $(1) $(AS_DEFINE) $(AS_FLAGS) $(addprefix -I,$(INCLUDE))
CC_PROCESS = $(CC) $(2) -o $(1) $(CC_DEFINE) $(CC_FLAGS) $(addprefix -I,$(INCLUDE)) --dependencies=m $(DEPENDS_DIR)
CX_PROCESS = $(CX) $(2) -o $(1) $(CX_DEFINE) $(CX_FLAGS) $(addprefix -I,$(INCLUDE)) --dependencies=m $(DEPENDS_DIR)
AR_PROCESS = $(AR) $(AR_FLAGS) --create -f $(3) -o $(1)
LD_PROCESS = $(LD) --map $(basename $(1)).map $(LIBRARIES) $(RT_LIBRARIES) $(LD_FLAGS) --config $(LINKER_FILE) -f $(3) -o $(1)


#------------------------------------------------------------
# tool extensions 
#------------------------------------------------------------
LIBRARY_EXT     = a
APPLICATION_EXT = out

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



#------------------------------------------------------------
# libraries tool options 
#------------------------------------------------------------
ifeq ($(TYPE),library)

### 'debug' configuration
ifeq ($(CONFIG),debug)
ifeq ($(NAME),psp)
CC_FLAGS += -On --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_inline --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --use_c++_inline --silent 
CX_FLAGS += -On --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --ec++ 
AS_FLAGS += --cpu Cortex-M4 --fpu VFPv4_sp -s -M'<>' -w+ -r -j -S 
AR_FLAGS += 
LD_FLAGS += --entry __iar_program_start 
CC_DEFINE += -DMQX_DISABLE_CONFIG_CHECK=1 -D_DEBUG=1 
CX_DEFINE += -D_DEBUG=1 
AS_DEFINE += -D_DEBUG=1 
endif
ifeq ($(NAME),shell)
CC_FLAGS += -On --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_inline --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --use_c++_inline --silent 
CX_FLAGS += -On --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --ec++ 
AS_FLAGS += --cpu Cortex-M4 --fpu VFPv4_sp -s -M'<>' -w+ -r -j -S 
AR_FLAGS += 
LD_FLAGS += --entry __iar_program_start 
CC_DEFINE += -D_DEBUG=1 
CX_DEFINE += -D_DEBUG=1 
AS_DEFINE += -D_DEBUG=1 
endif
ifeq ($(NAME),usbd)
CC_FLAGS += -On --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_inline --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --use_c++_inline --silent 
CX_FLAGS += -On --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --ec++ 
AS_FLAGS += --cpu Cortex-M4 --fpu VFPv4_sp -s -M'<>' -w+ -r -j -S 
AR_FLAGS += 
LD_FLAGS += --entry __iar_program_start 
CC_DEFINE += -D_DEBUG=1 
CX_DEFINE += -D_DEBUG=1 
AS_DEFINE += -D_DEBUG=1 
endif
ifeq ($(NAME),usbh)
CC_FLAGS += -On --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_inline --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --use_c++_inline --silent 
CX_FLAGS += -On --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --ec++ 
AS_FLAGS += --cpu Cortex-M4 --fpu VFPv4_sp -s -M'<>' -w+ -r -j -S 
AR_FLAGS += 
LD_FLAGS += --entry __iar_program_start 
CC_DEFINE += -D_DEBUG=1 
CX_DEFINE += -D_DEBUG=1 
AS_DEFINE += -D_DEBUG=1 
endif
ifeq ($(NAME),mfs)
CC_FLAGS += -On --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_inline --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --use_c++_inline --silent 
CX_FLAGS += -On --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --ec++ 
AS_FLAGS += --cpu Cortex-M4 --fpu VFPv4_sp -s -M'<>' -w+ -r -j -S 
AR_FLAGS += 
LD_FLAGS += --entry __iar_program_start 
CC_DEFINE += -D_DEBUG=1 
CX_DEFINE += -D_DEBUG=1 
AS_DEFINE += -D_DEBUG=1 
endif
ifeq ($(NAME),bsp)
CC_FLAGS += -On --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_inline --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --use_c++_inline --silent 
CX_FLAGS += -On --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --ec++ 
AS_FLAGS += --cpu Cortex-M4 --fpu VFPv4_sp -s -M'<>' -w+ -r -j -S 
AR_FLAGS += 
LD_FLAGS += --entry __iar_program_start 
CC_DEFINE += -D_DEBUG=1 
CX_DEFINE += -D_DEBUG=1 
AS_DEFINE += -D_DEBUG=1 
endif
ifeq ($(NAME),rtcs)
CC_FLAGS += -On --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_inline --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --use_c++_inline --silent 
CX_FLAGS += -On --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --ec++ 
AS_FLAGS += --cpu Cortex-M4 --fpu VFPv4_sp -s -M'<>' -w+ -r -j -S 
AR_FLAGS += 
LD_FLAGS += --entry __iar_program_start 
CC_DEFINE += -D_DEBUG=1 
CX_DEFINE += -D_DEBUG=1 
AS_DEFINE += -D_DEBUG=1 
endif
endif

### 'release' configuration
ifeq ($(CONFIG),release)
ifeq ($(NAME),psp)
CC_FLAGS += -Oh --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_inline --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --use_c++_inline --silent 
CX_FLAGS += -Oh --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --ec++ 
AS_FLAGS += --cpu Cortex-M4 --fpu VFPv4_sp -s -M'<>' -w+ -r -j -S 
AR_FLAGS += 
LD_FLAGS += --entry __iar_program_start 
CC_DEFINE += -DMQX_DISABLE_CONFIG_CHECK=1 
CX_DEFINE += 
AS_DEFINE += 
endif
ifeq ($(NAME),shell)
CC_FLAGS += -Oh --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_inline --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --use_c++_inline --silent 
CX_FLAGS += -Oh --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --ec++ 
AS_FLAGS += --cpu Cortex-M4 --fpu VFPv4_sp -s -M'<>' -w+ -r -j -S 
AR_FLAGS += 
LD_FLAGS += --entry __iar_program_start 
CC_DEFINE += 
CX_DEFINE += 
AS_DEFINE += 
endif
ifeq ($(NAME),usbd)
CC_FLAGS += -Oh --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_inline --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --use_c++_inline --silent 
CX_FLAGS += -Oh --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --ec++ 
AS_FLAGS += --cpu Cortex-M4 --fpu VFPv4_sp -s -M'<>' -w+ -r -j -S 
AR_FLAGS += 
LD_FLAGS += --entry __iar_program_start 
CC_DEFINE += 
CX_DEFINE += 
AS_DEFINE += 
endif
ifeq ($(NAME),usbh)
CC_FLAGS += -Oh --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_inline --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --use_c++_inline --silent 
CX_FLAGS += -Oh --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --ec++ 
AS_FLAGS += --cpu Cortex-M4 --fpu VFPv4_sp -s -M'<>' -w+ -r -j -S 
AR_FLAGS += 
LD_FLAGS += --entry __iar_program_start 
CC_DEFINE += 
CX_DEFINE += 
AS_DEFINE += 
endif
ifeq ($(NAME),mfs)
CC_FLAGS += -Oh --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_inline --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --use_c++_inline --silent 
CX_FLAGS += -Oh --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --ec++ 
AS_FLAGS += --cpu Cortex-M4 --fpu VFPv4_sp -s -M'<>' -w+ -r -j -S 
AR_FLAGS += 
LD_FLAGS += --entry __iar_program_start 
CC_DEFINE += 
CX_DEFINE += 
AS_DEFINE += 
endif
ifeq ($(NAME),bsp)
CC_FLAGS += -Oh --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_inline --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --use_c++_inline --silent 
CX_FLAGS += -Oh --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --ec++ 
AS_FLAGS += --cpu Cortex-M4 --fpu VFPv4_sp -s -M'<>' -w+ -r -j -S 
AR_FLAGS += 
LD_FLAGS += --entry __iar_program_start 
CC_DEFINE += 
CX_DEFINE += 
AS_DEFINE += 
endif
ifeq ($(NAME),rtcs)
CC_FLAGS += -Oh --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_inline --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --use_c++_inline --silent 
CX_FLAGS += -Oh --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --ec++ 
AS_FLAGS += --cpu Cortex-M4 --fpu VFPv4_sp -s -M'<>' -w+ -r -j -S 
AR_FLAGS += 
LD_FLAGS += --entry __iar_program_start 
CC_DEFINE += 
CX_DEFINE += 
AS_DEFINE += 
endif
endif

endif

#------------------------------------------------------------
# applications tool options 
#------------------------------------------------------------
ifeq ($(TYPE),application)

ifeq ($(CONFIG),debug)
CC_FLAGS += -On --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_inline --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --use_c++_inline --silent 
CX_FLAGS += -Oh --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --ec++ 
AS_FLAGS += --cpu Cortex-M4 --fpu VFPv4_sp -s -M'<>' -w+ -r -j -S 
AR_FLAGS += 
LD_FLAGS += --entry __iar_program_start 
CC_DEFINE += -D_DEBUG=1 
CX_DEFINE += -D_DEBUG=1 
AS_DEFINE += -D_DEBUG=1 
endif
ifeq ($(CONFIG),release)
CC_FLAGS += -Oh --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_inline --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --use_c++_inline --silent 
CX_FLAGS += -Oh --cpu=Cortex-M4 --fpu=VFPv4_sp --diag_suppress Pa039,Pe068,Pe069,Pa082,Pe177,Pe186,Pe550 --no_cse --no_unroll --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug --endian=little -e --ec++ 
AS_FLAGS += --cpu Cortex-M4 --fpu VFPv4_sp -s -M'<>' -w+ -r -j -S 
AR_FLAGS += 
LD_FLAGS += --entry __iar_program_start 
CC_DEFINE += 
CX_DEFINE += 
AS_DEFINE += 
endif

endif

