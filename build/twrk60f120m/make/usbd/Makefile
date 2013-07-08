#----------------------------------------------------------
# setup variables
#----------------------------------------------------------
MQX_ROOTDIR             = $(abspath ../../../..)
LIBRARY_ROOTDIR         = $(MQX_ROOTDIR)/lib/$(BOARD).$(TOOL)
override TYPE           = library
override NAME           = usbd
override BOARD          = twrk60f120m
override POSTBUILD_CMD  = $(call GET_POSTBUILD_CMD,usb/device/build/bat/usbd_twrk60f120m)
override LIBRARY_DIR    = $(LIBRARY_ROOTDIR)/$(CONFIG)/usb
override LIBRARY_FILE   = $(LIBRARY_DIR)/usbd.$(LIBRARY_EXT)

#-----------------------------------------------------------
# cw10 sources/include
#-----------------------------------------------------------
ifeq ($(TOOL),cw10)
INCLUDE += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/compiler/cw
endif
#-----------------------------------------------------------
# cw10gcc sources/include
#-----------------------------------------------------------
ifeq ($(TOOL),cw10gcc)
INCLUDE += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/compiler/gcc_cw
endif
#-----------------------------------------------------------
# iar sources/include
#-----------------------------------------------------------
ifeq ($(TOOL),iar)
INCLUDE += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/compiler/iar
endif
#-----------------------------------------------------------
# uv4 sources/include
#-----------------------------------------------------------
ifeq ($(TOOL),uv4)
INCLUDE += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/compiler/rv
endif


#-----------------------------------------------------------
# cross library include
#-----------------------------------------------------------
INCLUDE += $(MQX_ROOTDIR)/mqx/source/tad
INCLUDE += $(MQX_ROOTDIR)/mqx/source/string
INCLUDE += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/cpu
INCLUDE += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/core/M4
INCLUDE += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m
INCLUDE += $(MQX_ROOTDIR)/mqx/source/kernel
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/usb_dcd/polled
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/usb_dcd/int
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/usb_dcd
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/usb
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/timer
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/tfs
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/tchres
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/spi
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/serial/polled
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/serial/int
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/serial
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/sdcard/sdcard_spi
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/sdcard/sdcard_esdhc
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/sdcard
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/sai/int
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/sai
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/rtc
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/pipe
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/pcflash
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/pccard
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/pcb/mqxa
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/pcb
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/nandflash/nfc
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/nandflash/nand_devices
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/nandflash
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/lwgpio
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/lpm
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/io_null
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/io_mem
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/io_dun
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/i2c/polled
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/i2c/int
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/i2c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/hwtimer
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/gpio/kgpio
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/gpio
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/flashx/freescale
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/flashx
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/esdhc
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/enet/phy
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/enet/macnet
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/enet
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/debug
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/crc
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/cm
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/can/flexcan
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/adc/kadc
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/adc
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io
INCLUDE += $(MQX_ROOTDIR)/mqx/source/include
INCLUDE += $(MQX_ROOTDIR)/mqx/source/fio
INCLUDE += $(MQX_ROOTDIR)/mqx/source/bsp/twrk60f120m
INCLUDE += $(MQX_ROOTDIR)/config/twrk60f120m
INCLUDE += $(MQX_ROOTDIR)/config/common

#-----------------------------------------------------------
# audio
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/usb/device/source/classes/audio/usb_audio.c
INCLUDE += $(MQX_ROOTDIR)/usb/device/source/classes/include

#-----------------------------------------------------------
# cdc
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/usb/device/source/classes/cdc/usb_cdc_pstn.c
SOURCES += $(MQX_ROOTDIR)/usb/device/source/classes/cdc/usb_cdc.c
INCLUDE += $(MQX_ROOTDIR)/usb/device/source/classes/include

#-----------------------------------------------------------
# class
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/usb/device/source/classes/common/usb_class.c
INCLUDE += $(MQX_ROOTDIR)/usb/device/source/classes/include

#-----------------------------------------------------------
# common
#-----------------------------------------------------------
INCLUDE += $(MQX_ROOTDIR)/usb/common/include

#-----------------------------------------------------------
# doc
#-----------------------------------------------------------

#-----------------------------------------------------------
# ehci
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/usb/device/source/device/ehci/ehci_dev_main.c
SOURCES += $(MQX_ROOTDIR)/usb/device/source/device/ehci/callback_ehci.c
INCLUDE += $(MQX_ROOTDIR)/usb/host/source/host/ehci
INCLUDE += $(MQX_ROOTDIR)/usb/device/source/include/ehci

#-----------------------------------------------------------
# framework
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/usb/device/source/classes/common/usb_framework.c
INCLUDE += $(MQX_ROOTDIR)/usb/device/source/classes/include

#-----------------------------------------------------------
# hid
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/usb/device/source/classes/hid/usb_hid.c
INCLUDE += $(MQX_ROOTDIR)/usb/device/source/classes/include

#-----------------------------------------------------------
# include
#-----------------------------------------------------------
INCLUDE += $(MQX_ROOTDIR)/usb/device/source/include
INCLUDE += $(MQX_ROOTDIR)/usb/device/source/classes/include

#-----------------------------------------------------------
# khci
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/usb/device/source/device/khci/khci_dev_main.c
SOURCES += $(MQX_ROOTDIR)/usb/device/source/device/khci/callback_khci.c
INCLUDE += $(MQX_ROOTDIR)/usb/host/source/host/khci
INCLUDE += $(MQX_ROOTDIR)/usb/device/source/include/khci

#-----------------------------------------------------------
# msd
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/usb/device/source/classes/msd/usb_msc_scsi.c
SOURCES += $(MQX_ROOTDIR)/usb/device/source/classes/msd/usb_msc.c
INCLUDE += $(MQX_ROOTDIR)/usb/device/source/classes/include

#-----------------------------------------------------------
# os
#-----------------------------------------------------------
INCLUDE += $(MQX_ROOTDIR)/usb/device/source/include/rtos

#-----------------------------------------------------------
# phdc
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/usb/device/source/classes/phdc/usb_phdc.c
INCLUDE += $(MQX_ROOTDIR)/usb/device/source/classes/include

#-----------------------------------------------------------
# source
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/usb/device/source/device/dev_utl.c
SOURCES += $(MQX_ROOTDIR)/usb/device/source/device/dev_shut.c
SOURCES += $(MQX_ROOTDIR)/usb/device/source/device/dev_send.c
SOURCES += $(MQX_ROOTDIR)/usb/device/source/device/dev_recv.c
SOURCES += $(MQX_ROOTDIR)/usb/device/source/device/dev_main.c
SOURCES += $(MQX_ROOTDIR)/usb/device/source/device/dev_ep_deinit.c
SOURCES += $(MQX_ROOTDIR)/usb/device/source/device/dev_cncl.c


#----------------------------------------------------------
# include partial makefiles
#----------------------------------------------------------
include $(MQX_ROOTDIR)/build/common/make/global.mak
-include $(MQX_ROOTDIR)/build/$(BOARD)/make/tools/$(TOOL).mak
include $(MQX_ROOTDIR)/build/common/make/verify.mak
include $(MQX_ROOTDIR)/build/common/make/lib-process.mak
#----------------------------------------------------------
