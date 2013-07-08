#------------------------------------------------------------
# use specific TOOLCHAIN_ROOTDIR if not set in global.mak
#------------------------------------------------------------
#TOOLCHAIN_ROOTDIR = C:/PROGRA~1/KEIL2

#------------------------------------------------------------
# toolchain settings
#------------------------------------------------------------
AS = $(TOOLCHAIN_ROOTDIR)/ARM/BIN40/armasm.exe 
CC = $(TOOLCHAIN_ROOTDIR)/ARM/BIN40/armcc.exe 
CX = $(TOOLCHAIN_ROOTDIR)/ARM/BIN40/armcc.exe 
AR = $(TOOLCHAIN_ROOTDIR)/ARM/BIN40/armar.exe 
LD = $(TOOLCHAIN_ROOTDIR)/ARM/BIN40/armlink.exe 

#------------------------------------------------------------
# toolchain macros
# $(1) - output file path
# $(2) - list of object files
# $(3) - file contains list of object files
#------------------------------------------------------------
AS_PROCESS = $(AS) $(AS_FLAGS) --cpreproc_opts='$(AS_DEFINE)' $(addprefix -I,$(INCLUDE)) $(2) -o $(1) 
CC_PROCESS = $(CC) $(CC_FLAGS) $(CC_DEFINE) $(addprefix -I,$(INCLUDE)) -c $(2) -o $(1) 
CX_PROCESS = $(CX) $(CX_FLAGS) $(CX_DEFINE) $(addprefix -I,$(INCLUDE)) -c $(2) -o $(1) 
AR_PROCESS = $(AR) $(AR_FLAGS) -r $(1) --via=$(3) 
LD_PROCESS = $(LD) $(LD_FLAGS) --list=$(basename $(1)).map --via=$(3) --scatter=$(LINKER_FILE) \
$(LIBRARIES) \
$(LIBRARY_ROOTDIR)/$(CONFIG)/psp/psp.lib\(linker_symbols.o\) \
$(LIBRARY_ROOTDIR)/$(CONFIG)/bsp/bsp.lib\(vectors.o\) \
-o $1



LD_FLAGS += --libpath=$(TOOLCHAIN_ROOTDIR)/ARM/RV31/LIB/

#------------------------------------------------------------
# tool extensions 
#------------------------------------------------------------
LIBRARY_EXT     = lib
APPLICATION_EXT = axf

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
INCLUDE += $(TOOLCHAIN_ROOTDIR)/ARM/INC/Freescale/Kinetis
INCLUDE += $(TOOLCHAIN_ROOTDIR)/ARM/CMSIS/Include
INCLUDE += $(TOOLCHAIN_ROOTDIR)/ARM/RV31/INC



#------------------------------------------------------------
# libraries tool options 
#------------------------------------------------------------
ifeq ($(TYPE),library)

### 'debug' configuration
ifeq ($(CONFIG),debug)
ifeq ($(NAME),psp)
CC_FLAGS += -O0 --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --c99 -g 
CX_FLAGS += --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --cpp -g 
AS_FLAGS += --cpu Cortex-M4 --apcs=interwork --cpreproc --xref --li -g 
AR_FLAGS += 
LD_FLAGS += --cpu Cortex-M4 --remove --keep linker_symbols.o\(KERNEL_DATA_START\) --keep linker_symbols.o\(KERNEL_DATA_END\) --keep linker_symbols.o\(BOOT_STACK\) --keep vectors.o\(.vectors_rom\) --autoat --xref --summary_stderr --info summarysizes --map --callgraph --symbols --info sizes --info totals --info unused --info veneers --strict --diag_suppress=L6314W 
CC_DEFINE += -DMQX_DISABLE_CONFIG_CHECK=1 -D_DEBUG=1 
CX_DEFINE += -D_DEBUG=1 
AS_DEFINE += -D,_DEBUG=1 
endif
ifeq ($(NAME),shell)
CC_FLAGS += -O0 --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --c99 -g 
CX_FLAGS += --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --cpp -g 
AS_FLAGS += --cpu Cortex-M4 --apcs=interwork --cpreproc --xref --li -g 
AR_FLAGS += 
LD_FLAGS += --cpu Cortex-M4 --remove --keep linker_symbols.o\(KERNEL_DATA_START\) --keep linker_symbols.o\(KERNEL_DATA_END\) --keep linker_symbols.o\(BOOT_STACK\) --keep vectors.o\(.vectors_rom\) --autoat --xref --summary_stderr --info summarysizes --map --callgraph --symbols --info sizes --info totals --info unused --info veneers --strict --diag_suppress=L6314W 
CC_DEFINE += -D_DEBUG=1 
CX_DEFINE += -D_DEBUG=1 
AS_DEFINE += -D,_DEBUG=1 
endif
ifeq ($(NAME),usbd)
CC_FLAGS += -O0 --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --c99 -g 
CX_FLAGS += --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --cpp -g 
AS_FLAGS += --cpu Cortex-M4 --apcs=interwork --cpreproc --xref --li -g 
AR_FLAGS += 
LD_FLAGS += --cpu Cortex-M4 --remove --keep linker_symbols.o\(KERNEL_DATA_START\) --keep linker_symbols.o\(KERNEL_DATA_END\) --keep linker_symbols.o\(BOOT_STACK\) --keep vectors.o\(.vectors_rom\) --autoat --xref --summary_stderr --info summarysizes --map --callgraph --symbols --info sizes --info totals --info unused --info veneers --strict --diag_suppress=L6314W 
CC_DEFINE += -D_DEBUG=1 
CX_DEFINE += -D_DEBUG=1 
AS_DEFINE += -D,_DEBUG=1 
endif
ifeq ($(NAME),usbh)
CC_FLAGS += -O0 --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --c99 -g 
CX_FLAGS += --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --cpp -g 
AS_FLAGS += --cpu Cortex-M4 --apcs=interwork --cpreproc --xref --li -g 
AR_FLAGS += 
LD_FLAGS += --cpu Cortex-M4 --remove --keep linker_symbols.o\(KERNEL_DATA_START\) --keep linker_symbols.o\(KERNEL_DATA_END\) --keep linker_symbols.o\(BOOT_STACK\) --keep vectors.o\(.vectors_rom\) --autoat --xref --summary_stderr --info summarysizes --map --callgraph --symbols --info sizes --info totals --info unused --info veneers --strict --diag_suppress=L6314W 
CC_DEFINE += -D_DEBUG=1 
CX_DEFINE += -D_DEBUG=1 
AS_DEFINE += -D,_DEBUG=1 
endif
ifeq ($(NAME),mfs)
CC_FLAGS += -O0 --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --c99 -g 
CX_FLAGS += --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --cpp -g 
AS_FLAGS += --cpu Cortex-M4 --apcs=interwork --cpreproc --xref --li -g 
AR_FLAGS += 
LD_FLAGS += --cpu Cortex-M4 --remove --keep linker_symbols.o\(KERNEL_DATA_START\) --keep linker_symbols.o\(KERNEL_DATA_END\) --keep linker_symbols.o\(BOOT_STACK\) --keep vectors.o\(.vectors_rom\) --autoat --xref --summary_stderr --info summarysizes --map --callgraph --symbols --info sizes --info totals --info unused --info veneers --strict --diag_suppress=L6314W 
CC_DEFINE += -D_DEBUG=1 
CX_DEFINE += -D_DEBUG=1 
AS_DEFINE += -D,_DEBUG=1 
endif
ifeq ($(NAME),bsp)
CC_FLAGS += -O0 --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --c99 -g 
CX_FLAGS += --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --cpp -g 
AS_FLAGS += --cpu Cortex-M4 --apcs=interwork --cpreproc --xref --li -g 
AR_FLAGS += 
LD_FLAGS += --cpu Cortex-M4 --remove --keep linker_symbols.o\(KERNEL_DATA_START\) --keep linker_symbols.o\(KERNEL_DATA_END\) --keep linker_symbols.o\(BOOT_STACK\) --keep vectors.o\(.vectors_rom\) --autoat --xref --summary_stderr --info summarysizes --map --callgraph --symbols --info sizes --info totals --info unused --info veneers --strict --diag_suppress=L6314W 
CC_DEFINE += -D_DEBUG=1 
CX_DEFINE += -D_DEBUG=1 
AS_DEFINE += -D,_DEBUG=1 
endif
ifeq ($(NAME),rtcs)
CC_FLAGS += -O0 --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --c99 -g 
CX_FLAGS += --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --cpp -g 
AS_FLAGS += --cpu Cortex-M4 --apcs=interwork --cpreproc --xref --li -g 
AR_FLAGS += 
LD_FLAGS += --cpu Cortex-M4 --remove --keep linker_symbols.o\(KERNEL_DATA_START\) --keep linker_symbols.o\(KERNEL_DATA_END\) --keep linker_symbols.o\(BOOT_STACK\) --keep vectors.o\(.vectors_rom\) --autoat --xref --summary_stderr --info summarysizes --map --callgraph --symbols --info sizes --info totals --info unused --info veneers --strict --diag_suppress=L6314W 
CC_DEFINE += -D_DEBUG=1 
CX_DEFINE += -D_DEBUG=1 
AS_DEFINE += -D,_DEBUG=1 
endif
endif

### 'release' configuration
ifeq ($(CONFIG),release)
ifeq ($(NAME),psp)
CC_FLAGS += -O3 --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --c99 -g 
CX_FLAGS += --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --cpp -g 
AS_FLAGS += --cpu Cortex-M4 --apcs=interwork --cpreproc --xref --li -g 
AR_FLAGS += 
LD_FLAGS += --cpu Cortex-M4 --remove --keep linker_symbols.o\(KERNEL_DATA_START\) --keep linker_symbols.o\(KERNEL_DATA_END\) --keep linker_symbols.o\(BOOT_STACK\) --keep vectors.o\(.vectors_rom\) --autoat --xref --summary_stderr --info summarysizes --map --callgraph --symbols --info sizes --info totals --info unused --info veneers --strict --diag_suppress=L6314W 
CC_DEFINE += -DMQX_DISABLE_CONFIG_CHECK=1 
CX_DEFINE += 
AS_DEFINE += 
endif
ifeq ($(NAME),shell)
CC_FLAGS += -O3 --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --c99 -g 
CX_FLAGS += --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --cpp -g 
AS_FLAGS += --cpu Cortex-M4 --apcs=interwork --cpreproc --xref --li -g 
AR_FLAGS += 
LD_FLAGS += --cpu Cortex-M4 --remove --keep linker_symbols.o\(KERNEL_DATA_START\) --keep linker_symbols.o\(KERNEL_DATA_END\) --keep linker_symbols.o\(BOOT_STACK\) --keep vectors.o\(.vectors_rom\) --autoat --xref --summary_stderr --info summarysizes --map --callgraph --symbols --info sizes --info totals --info unused --info veneers --strict --diag_suppress=L6314W 
CC_DEFINE += 
CX_DEFINE += 
AS_DEFINE += 
endif
ifeq ($(NAME),usbd)
CC_FLAGS += -O3 --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --c99 -g 
CX_FLAGS += --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --cpp -g 
AS_FLAGS += --cpu Cortex-M4 --apcs=interwork --cpreproc --xref --li -g 
AR_FLAGS += 
LD_FLAGS += --cpu Cortex-M4 --remove --keep linker_symbols.o\(KERNEL_DATA_START\) --keep linker_symbols.o\(KERNEL_DATA_END\) --keep linker_symbols.o\(BOOT_STACK\) --keep vectors.o\(.vectors_rom\) --autoat --xref --summary_stderr --info summarysizes --map --callgraph --symbols --info sizes --info totals --info unused --info veneers --strict --diag_suppress=L6314W 
CC_DEFINE += 
CX_DEFINE += 
AS_DEFINE += 
endif
ifeq ($(NAME),usbh)
CC_FLAGS += -O3 --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --c99 -g 
CX_FLAGS += --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --cpp -g 
AS_FLAGS += --cpu Cortex-M4 --apcs=interwork --cpreproc --xref --li -g 
AR_FLAGS += 
LD_FLAGS += --cpu Cortex-M4 --remove --keep linker_symbols.o\(KERNEL_DATA_START\) --keep linker_symbols.o\(KERNEL_DATA_END\) --keep linker_symbols.o\(BOOT_STACK\) --keep vectors.o\(.vectors_rom\) --autoat --xref --summary_stderr --info summarysizes --map --callgraph --symbols --info sizes --info totals --info unused --info veneers --strict --diag_suppress=L6314W 
CC_DEFINE += 
CX_DEFINE += 
AS_DEFINE += 
endif
ifeq ($(NAME),mfs)
CC_FLAGS += -O3 --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --c99 -g 
CX_FLAGS += --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --cpp -g 
AS_FLAGS += --cpu Cortex-M4 --apcs=interwork --cpreproc --xref --li -g 
AR_FLAGS += 
LD_FLAGS += --cpu Cortex-M4 --remove --keep linker_symbols.o\(KERNEL_DATA_START\) --keep linker_symbols.o\(KERNEL_DATA_END\) --keep linker_symbols.o\(BOOT_STACK\) --keep vectors.o\(.vectors_rom\) --autoat --xref --summary_stderr --info summarysizes --map --callgraph --symbols --info sizes --info totals --info unused --info veneers --strict --diag_suppress=L6314W 
CC_DEFINE += 
CX_DEFINE += 
AS_DEFINE += 
endif
ifeq ($(NAME),bsp)
CC_FLAGS += -O3 --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --c99 -g 
CX_FLAGS += --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --cpp -g 
AS_FLAGS += --cpu Cortex-M4 --apcs=interwork --cpreproc --xref --li -g 
AR_FLAGS += 
LD_FLAGS += --cpu Cortex-M4 --remove --keep linker_symbols.o\(KERNEL_DATA_START\) --keep linker_symbols.o\(KERNEL_DATA_END\) --keep linker_symbols.o\(BOOT_STACK\) --keep vectors.o\(.vectors_rom\) --autoat --xref --summary_stderr --info summarysizes --map --callgraph --symbols --info sizes --info totals --info unused --info veneers --strict --diag_suppress=L6314W 
CC_DEFINE += 
CX_DEFINE += 
AS_DEFINE += 
endif
ifeq ($(NAME),rtcs)
CC_FLAGS += -O3 --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --c99 -g 
CX_FLAGS += --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --cpp -g 
AS_FLAGS += --cpu Cortex-M4 --apcs=interwork --cpreproc --xref --li -g 
AR_FLAGS += 
LD_FLAGS += --cpu Cortex-M4 --remove --keep linker_symbols.o\(KERNEL_DATA_START\) --keep linker_symbols.o\(KERNEL_DATA_END\) --keep linker_symbols.o\(BOOT_STACK\) --keep vectors.o\(.vectors_rom\) --autoat --xref --summary_stderr --info summarysizes --map --callgraph --symbols --info sizes --info totals --info unused --info veneers --strict --diag_suppress=L6314W 
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
CC_FLAGS += -O0 --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --c99 -g 
CX_FLAGS += --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --cpp -g 
AS_FLAGS += --cpu Cortex-M4 --apcs=interwork --cpreproc --xref --li -g 
AR_FLAGS += 
LD_FLAGS += --cpu Cortex-M4 --remove --keep linker_symbols.o\(KERNEL_DATA_START\) --keep linker_symbols.o\(KERNEL_DATA_END\) --keep linker_symbols.o\(BOOT_STACK\) --keep vectors.o\(.vectors_rom\) --autoat --xref --summary_stderr --info summarysizes --map --callgraph --symbols --info sizes --info totals --info unused --info veneers --strict --diag_suppress=L6314W 
CC_DEFINE += -D_DEBUG=1 
CX_DEFINE += -D_DEBUG=1 
AS_DEFINE += -D,_DEBUG=1 
endif
ifeq ($(CONFIG),release)
CC_FLAGS += -O3 --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --c99 -g 
CX_FLAGS += --cpu Cortex-M4 --library_interface=armcc --library_type=standardlib --apcs=interwork --split_sections --li --cpp -g 
AS_FLAGS += --cpu Cortex-M4 --apcs=interwork --cpreproc --xref --li -g 
AR_FLAGS += 
LD_FLAGS += --cpu Cortex-M4 --remove --keep linker_symbols.o\(KERNEL_DATA_START\) --keep linker_symbols.o\(KERNEL_DATA_END\) --keep linker_symbols.o\(BOOT_STACK\) --keep vectors.o\(.vectors_rom\) --autoat --xref --summary_stderr --info summarysizes --map --callgraph --symbols --info sizes --info totals --info unused --info veneers --strict --diag_suppress=L6314W 
CC_DEFINE += 
CX_DEFINE += 
AS_DEFINE += 
endif

endif

