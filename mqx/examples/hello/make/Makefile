#----------------------------------------------------------
# setup required variables 
#----------------------------------------------------------
MQX_ROOTDIR         = $(abspath ../../../..)
LIBRARY_ROOTDIR     = $(MQX_ROOTDIR)/lib/$(BOARD).$(TOOL)
APPLICATION_DIR     = $(MQX_ROOTDIR)/mqx/examples/hello/make/$(BOARD).$(TOOL)/$(CONFIG)_$(LOADNAME)
APPLICATION_FILE    = $(APPLICATION_DIR)/$(NAME).$(APPLICATION_EXT)
LINKER_FILE         = $(call GET_BSP_LINKER_FILE)
override TYPE       = application
override NAME       = hello

#----------------------------------------------------------
# add libraries/include
#----------------------------------------------------------
LIBRARIES += $(LIBRARY_ROOTDIR)/$(CONFIG)/bsp/bsp.$(LIBRARY_EXT)
LIBRARIES += $(LIBRARY_ROOTDIR)/$(CONFIG)/psp/psp.$(LIBRARY_EXT)
INCLUDE += $(LIBRARY_ROOTDIR)/$(CONFIG)/psp
INCLUDE += $(LIBRARY_ROOTDIR)/$(CONFIG)/bsp/Sources
INCLUDE += $(LIBRARY_ROOTDIR)/$(CONFIG)/bsp/Generated_Code
INCLUDE += $(LIBRARY_ROOTDIR)/$(CONFIG)/bsp
INCLUDE += $(LIBRARY_ROOTDIR)/$(CONFIG)/

#----------------------------------------------------------
# add application sources/include
#----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/examples/hello/hello.c

#----------------------------------------------------------
# include partial makefiles
#----------------------------------------------------------
include $(MQX_ROOTDIR)/build/common/make/global.mak
-include $(MQX_ROOTDIR)/build/$(BOARD)/make/tools/$(TOOL).mak
include $(MQX_ROOTDIR)/build/common/make/verify.mak
include $(MQX_ROOTDIR)/build/common/make/app-process.mak
#----------------------------------------------------------
