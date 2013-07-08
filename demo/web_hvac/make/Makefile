#----------------------------------------------------------
# setup required variables 
#----------------------------------------------------------
MQX_ROOTDIR         = $(abspath ../../..)
LIBRARY_ROOTDIR     = $(MQX_ROOTDIR)/lib/$(BOARD).$(TOOL)
APPLICATION_DIR     = $(MQX_ROOTDIR)/demo/web_hvac/make/$(BOARD).$(TOOL)/$(CONFIG)_$(LOADNAME)
APPLICATION_FILE    = $(APPLICATION_DIR)/$(NAME).$(APPLICATION_EXT)
LINKER_FILE         = $(call GET_BSP_LINKER_FILE)
override TYPE       = application
override NAME       = web_hvac

#----------------------------------------------------------
# add libraries/include
#----------------------------------------------------------
LIBRARIES += $(LIBRARY_ROOTDIR)/$(CONFIG)/usb/usbh.$(LIBRARY_EXT)
LIBRARIES += $(LIBRARY_ROOTDIR)/$(CONFIG)/bsp/bsp.$(LIBRARY_EXT)
LIBRARIES += $(LIBRARY_ROOTDIR)/$(CONFIG)/mfs/mfs.$(LIBRARY_EXT)
LIBRARIES += $(LIBRARY_ROOTDIR)/$(CONFIG)/shell/shell.$(LIBRARY_EXT)
LIBRARIES += $(LIBRARY_ROOTDIR)/$(CONFIG)/rtcs/rtcs.$(LIBRARY_EXT)
LIBRARIES += $(LIBRARY_ROOTDIR)/$(CONFIG)/psp/psp.$(LIBRARY_EXT)
INCLUDE += $(LIBRARY_ROOTDIR)/$(CONFIG)/usb
INCLUDE += $(LIBRARY_ROOTDIR)/$(CONFIG)/shell
INCLUDE += $(LIBRARY_ROOTDIR)/$(CONFIG)/rtcs
INCLUDE += $(LIBRARY_ROOTDIR)/$(CONFIG)/psp
INCLUDE += $(LIBRARY_ROOTDIR)/$(CONFIG)/mfs
INCLUDE += $(LIBRARY_ROOTDIR)/$(CONFIG)/bsp/Sources
INCLUDE += $(LIBRARY_ROOTDIR)/$(CONFIG)/bsp/Generated_Code
INCLUDE += $(LIBRARY_ROOTDIR)/$(CONFIG)/bsp
INCLUDE += $(LIBRARY_ROOTDIR)/$(CONFIG)/

#----------------------------------------------------------
# add application sources/include
#----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/demo/web_hvac/Command_Lists.c
SOURCES += $(MQX_ROOTDIR)/demo/web_hvac/HVAC_IO.c
SOURCES += $(MQX_ROOTDIR)/demo/web_hvac/HVAC_Shell_Commands.c
SOURCES += $(MQX_ROOTDIR)/demo/web_hvac/HVAC_Task.c
SOURCES += $(MQX_ROOTDIR)/demo/web_hvac/HVAC_Util.c
SOURCES += $(MQX_ROOTDIR)/demo/web_hvac/Logging_Task.c
SOURCES += $(MQX_ROOTDIR)/demo/web_hvac/RTCS.c
SOURCES += $(MQX_ROOTDIR)/demo/web_hvac/Shell_Task.c
SOURCES += $(MQX_ROOTDIR)/demo/web_hvac/Switch_Task.c
SOURCES += $(MQX_ROOTDIR)/demo/web_hvac/Tasks.c
SOURCES += $(MQX_ROOTDIR)/demo/web_hvac/USB_File.c
SOURCES += $(MQX_ROOTDIR)/demo/web_hvac/USB_Task.c
SOURCES += $(MQX_ROOTDIR)/demo/web_hvac/cgi_hvac.c
SOURCES += $(MQX_ROOTDIR)/demo/web_hvac/cgi_index.c
SOURCES += $(MQX_ROOTDIR)/demo/web_hvac/tfs_data.c
SOURCES += $(MQX_ROOTDIR)/demo/web_hvac/usb_classes.c
INCLUDE += $(MQX_ROOTDIR)/demo/web_hvac

#----------------------------------------------------------
# include partial makefiles
#----------------------------------------------------------
include $(MQX_ROOTDIR)/build/common/make/global.mak
-include $(MQX_ROOTDIR)/build/$(BOARD)/make/tools/$(TOOL).mak
include $(MQX_ROOTDIR)/build/common/make/verify.mak
include $(MQX_ROOTDIR)/build/common/make/app-process.mak
#----------------------------------------------------------
