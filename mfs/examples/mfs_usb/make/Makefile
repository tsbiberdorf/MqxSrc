#----------------------------------------------------------
# setup required variables 
#----------------------------------------------------------
MQX_ROOTDIR         = $(abspath ../../../..)
LIBRARY_ROOTDIR     = $(MQX_ROOTDIR)/lib/$(BOARD).$(TOOL)
APPLICATION_DIR     = $(MQX_ROOTDIR)/mfs/examples/mfs_usb/make/$(BOARD).$(TOOL)/$(CONFIG)_$(LOADNAME)
APPLICATION_FILE    = $(APPLICATION_DIR)/$(NAME).$(APPLICATION_EXT)
LINKER_FILE         = $(call GET_BSP_LINKER_FILE)
override TYPE       = application
override NAME       = mfs_usb

#----------------------------------------------------------
# add libraries/include
#----------------------------------------------------------
LIBRARIES += $(LIBRARY_ROOTDIR)/$(CONFIG)/bsp/bsp.$(LIBRARY_EXT)
LIBRARIES += $(LIBRARY_ROOTDIR)/$(CONFIG)/psp/psp.$(LIBRARY_EXT)
LIBRARIES += $(LIBRARY_ROOTDIR)/$(CONFIG)/usb/usbh.$(LIBRARY_EXT)
LIBRARIES += $(LIBRARY_ROOTDIR)/$(CONFIG)/mfs/mfs.$(LIBRARY_EXT)
LIBRARIES += $(LIBRARY_ROOTDIR)/$(CONFIG)/shell/shell.$(LIBRARY_EXT)
INCLUDE += $(LIBRARY_ROOTDIR)/$(CONFIG)/usb
INCLUDE += $(LIBRARY_ROOTDIR)/$(CONFIG)/shell
INCLUDE += $(LIBRARY_ROOTDIR)/$(CONFIG)/psp
INCLUDE += $(LIBRARY_ROOTDIR)/$(CONFIG)/mfs
INCLUDE += $(LIBRARY_ROOTDIR)/$(CONFIG)/bsp/Sources
INCLUDE += $(LIBRARY_ROOTDIR)/$(CONFIG)/bsp/Generated_Code
INCLUDE += $(LIBRARY_ROOTDIR)/$(CONFIG)/bsp
INCLUDE += $(LIBRARY_ROOTDIR)/$(CONFIG)/

#----------------------------------------------------------
# add application sources/include
#----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mfs/examples/mfs_usb/Command_Lists.c
SOURCES += $(MQX_ROOTDIR)/mfs/examples/mfs_usb/Shell_Task.c
SOURCES += $(MQX_ROOTDIR)/mfs/examples/mfs_usb/Tasks.c
SOURCES += $(MQX_ROOTDIR)/mfs/examples/mfs_usb/USB_File.c
SOURCES += $(MQX_ROOTDIR)/mfs/examples/mfs_usb/USB_Task.c
SOURCES += $(MQX_ROOTDIR)/mfs/examples/mfs_usb/usb_classes.c
INCLUDE += $(MQX_ROOTDIR)/mfs/examples/mfs_usb

#----------------------------------------------------------
# include partial makefiles
#----------------------------------------------------------
include $(MQX_ROOTDIR)/build/common/make/global.mak
-include $(MQX_ROOTDIR)/build/$(BOARD)/make/tools/$(TOOL).mak
include $(MQX_ROOTDIR)/build/common/make/verify.mak
include $(MQX_ROOTDIR)/build/common/make/app-process.mak
#----------------------------------------------------------
