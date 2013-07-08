#----------------------------------------------------------
# internal host enviroment
# valid values: WINDOWS UNIX
#----------------------------------------------------------
# HOSTENV = UNIX
HOSTENV = WINDOWS

#----------------------------------------------------------
# set default path to toolchain
#----------------------------------------------------------
# ifeq ($(TOOL),cw10)
# TOOLCHAIN_ROOTDIR = C:/FREESC~1/CWMCUV~1.2
# endif
# ifeq ($(TOOL),uv4)
# TOOLCHAIN_ROOTDIR = C:/PROGRA~1/KEIL
# endif
# ifeq ($(TOOL),iar)
# TOOLCHAIN_ROOTDIR = C:/PROGRA~1/IARSYS~1/EMBEDD~1.4
# endif
# ifeq ($(TOOL),cw10gcc)
# TOOLCHAIN_ROOTDIR = C:/FREESC~1/CWMCUV~1.3
# endif
# ifeq ($(TOOL),gcc_cs)
# TOOLCHAIN_ROOTDIR = C:/PROGRA~1/CODESO~1/SOURCE~2
# endif
# ifeq ($(TOOL),ds5)
# TOOLCHAIN_ROOTDIR = C:/PROGRA~1/DS-5
# endif

#----------------------------------------------------------
# macro, convert slash to backslash
# $(1) - processed string
#----------------------------------------------------------
CONVERT2BACKSLASH = $(subst /,\,$(1))

#----------------------------------------------------------
# macro, convert backslash to slash
# $(1) - processed string
#----------------------------------------------------------
CONVERT2SLASH = $(subst \,/,$(1))

#----------------------------------------------------------
# macro, get linker command file from global variables
#----------------------------------------------------------
ifneq ($(LOAD),)
GET_BSP_LINKER_FILE = $(firstword $(wildcard $(LIBRARY_ROOTDIR)/$(CONFIG)/bsp/$(LOAD).*))
else
GET_BSP_LINKER_FILE = 
endif

#----------------------------------------------------------
# macro, get standard post-build command
# $(1) - batch file path, without extension
#----------------------------------------------------------
ifeq ($(HOSTENV),WINDOWS)
GET_POSTBUILD_CMD = $(MQX_ROOTDIR)/$(1).bat $(MQX_ROOTDIR) $(LIBRARY_DIR) $(TOOL)
endif
ifeq ($(HOSTENV),UNIX)
GET_POSTBUILD_CMD = $(MQX_ROOTDIR)/$(1).sh $(MQX_ROOTDIR) $(LIBRARY_DIR) $(TOOL)
endif

#----------------------------------------------------------
# macro, create recursive directory
# $(1) - path to directory
#----------------------------------------------------------
ifeq ($(HOSTENV),WINDOWS)
MKDIR = mkdir $(call CONVERT2BACKSLASH,$(1))
endif
ifeq ($(HOSTENV),UNIX)
MKDIR = mkdir -p $(1)
endif

#----------------------------------------------------------
# macro, force remove recursive directory
# $(1) - path to directory
#----------------------------------------------------------
ifeq ($(HOSTENV),WINDOWS)
RMDIR = rd /s /q $(call CONVERT2BACKSLASH,$(1))
endif
ifeq ($(HOSTENV),UNIX)
RMDIR = rm -rf $(1)
endif

#----------------------------------------------------------
# macro, list directory
# $(1) - path to directory
#----------------------------------------------------------
ifeq ($(HOSTENV),WINDOWS)
LSDIR = dir $(call CONVERT2BACKSLASH,$(1)) /w/b/s
endif
ifeq ($(HOSTENV),UNIX)
LSDIR = find $(1) -type f
endif

#----------------------------------------------------------
# macro, print message
# $(1) - message
#----------------------------------------------------------
ifeq ($(HOSTENV),WINDOWS)
PRINT = @echo $(1)
endif
ifeq ($(HOSTENV),UNIX)
PRINT = @echo $(1)
endif

