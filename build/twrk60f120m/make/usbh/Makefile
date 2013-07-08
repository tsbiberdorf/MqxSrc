#----------------------------------------------------------
# setup variables
#----------------------------------------------------------
MQX_ROOTDIR             = $(abspath ../../../..)
LIBRARY_ROOTDIR         = $(MQX_ROOTDIR)/lib/$(BOARD).$(TOOL)
override TYPE           = library
override NAME           = usbh
override BOARD          = twrk60f120m
override POSTBUILD_CMD  = $(call GET_POSTBUILD_CMD,usb/host/build/bat/usbh_twrk60f120m)
override LIBRARY_DIR    = $(LIBRARY_ROOTDIR)/$(CONFIG)/usb
override LIBRARY_FILE   = $(LIBRARY_DIR)/usbh.$(LIBRARY_EXT)

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
SOURCES += $(MQX_ROOTDIR)/usb/host/source/classes/audio/usb_host_audio_intf.c
SOURCES += $(MQX_ROOTDIR)/usb/host/source/classes/audio/usb_host_audio.c
INCLUDE += $(MQX_ROOTDIR)/usb/host/source/classes/audio

#-----------------------------------------------------------
# cdc
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/usb/host/source/classes/cdc/usb_host_cdc_intf.c
SOURCES += $(MQX_ROOTDIR)/usb/host/source/classes/cdc/usb_host_cdc.c
INCLUDE += $(MQX_ROOTDIR)/usb/host/source/classes/cdc

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
SOURCES += $(MQX_ROOTDIR)/usb/host/source/host/ehci/ehci_utl.c
SOURCES += $(MQX_ROOTDIR)/usb/host/source/host/ehci/ehci_shut.c
SOURCES += $(MQX_ROOTDIR)/usb/host/source/host/ehci/ehci_main.c
SOURCES += $(MQX_ROOTDIR)/usb/host/source/host/ehci/ehci_iso.c
SOURCES += $(MQX_ROOTDIR)/usb/host/source/host/ehci/ehci_intr.c
SOURCES += $(MQX_ROOTDIR)/usb/host/source/host/ehci/ehci_cncl.c
SOURCES += $(MQX_ROOTDIR)/usb/host/source/host/ehci/ehci_bw.c
INCLUDE += $(MQX_ROOTDIR)/usb/host/source/host/ehci

#-----------------------------------------------------------
# hid
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/usb/host/source/classes/hid/usb_host_hid.c
INCLUDE += $(MQX_ROOTDIR)/usb/host/source/classes/hid

#-----------------------------------------------------------
# hub
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/usb/host/source/classes/hub/usb_host_hub_sm.c
SOURCES += $(MQX_ROOTDIR)/usb/host/source/classes/hub/usb_host_hub.c
INCLUDE += $(MQX_ROOTDIR)/usb/host/source/classes/hub

#-----------------------------------------------------------
# include
#-----------------------------------------------------------
INCLUDE += $(MQX_ROOTDIR)/usb/host/source/include

#-----------------------------------------------------------
# khci
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/usb/host/source/host/khci/khci.c
INCLUDE += $(MQX_ROOTDIR)/usb/host/source/host/khci

#-----------------------------------------------------------
# msd
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/usb/host/source/classes/msd/usb_host_msd_ufi.c
SOURCES += $(MQX_ROOTDIR)/usb/host/source/classes/msd/usb_host_msd_queue.c
SOURCES += $(MQX_ROOTDIR)/usb/host/source/classes/msd/usb_host_msd_bo.c
SOURCES += $(MQX_ROOTDIR)/usb/host/source/classes/msd/mfs/usbmfs.c
INCLUDE += $(MQX_ROOTDIR)/usb/host/source/classes/msd/mfs
INCLUDE += $(MQX_ROOTDIR)/usb/host/source/classes/msd

#-----------------------------------------------------------
# os
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/usb/host/source/rtos/mqx/usb_mqx.c
SOURCES += $(MQX_ROOTDIR)/usb/host/source/rtos/mqx/mqx_dll.c
INCLUDE += $(MQX_ROOTDIR)/usb/host/source/rtos/mqx

#-----------------------------------------------------------
# phdc
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/usb/host/source/classes/phdc/usb_host_phdc.c
INCLUDE += $(MQX_ROOTDIR)/usb/host/source/classes/phdc

#-----------------------------------------------------------
# printer
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/usb/host/source/classes/printer/usb_host_printer.c
INCLUDE += $(MQX_ROOTDIR)/usb/host/source/classes/printer

#-----------------------------------------------------------
# source
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/usb/host/source/host/host_snd.c
SOURCES += $(MQX_ROOTDIR)/usb/host/source/host/host_shut.c
SOURCES += $(MQX_ROOTDIR)/usb/host/source/host/host_rcv.c
SOURCES += $(MQX_ROOTDIR)/usb/host/source/host/host_main.c
SOURCES += $(MQX_ROOTDIR)/usb/host/source/host/host_dev_list.c
SOURCES += $(MQX_ROOTDIR)/usb/host/source/host/host_common.c
SOURCES += $(MQX_ROOTDIR)/usb/host/source/host/host_cnl.c
SOURCES += $(MQX_ROOTDIR)/usb/host/source/host/host_close.c
SOURCES += $(MQX_ROOTDIR)/usb/host/source/host/host_ch9.c


#----------------------------------------------------------
# include partial makefiles
#----------------------------------------------------------
include $(MQX_ROOTDIR)/build/common/make/global.mak
-include $(MQX_ROOTDIR)/build/$(BOARD)/make/tools/$(TOOL).mak
include $(MQX_ROOTDIR)/build/common/make/verify.mak
include $(MQX_ROOTDIR)/build/common/make/lib-process.mak
#----------------------------------------------------------
