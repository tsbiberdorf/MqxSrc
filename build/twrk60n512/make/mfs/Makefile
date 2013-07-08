#----------------------------------------------------------
# setup variables
#----------------------------------------------------------
MQX_ROOTDIR             = $(abspath ../../../..)
LIBRARY_ROOTDIR         = $(MQX_ROOTDIR)/lib/$(BOARD).$(TOOL)
override TYPE           = library
override NAME           = mfs
override BOARD          = twrk60n512
override POSTBUILD_CMD  = $(call GET_POSTBUILD_CMD,mfs/build/bat/mfs_twrk60n512)
override LIBRARY_DIR    = $(LIBRARY_ROOTDIR)/$(CONFIG)/mfs
override LIBRARY_FILE   = $(LIBRARY_DIR)/mfs.$(LIBRARY_EXT)

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
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/rtc
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/pipe
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/pcflash
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/pccard
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/pcb/mqxa
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/pcb
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/lwgpio
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/lpm
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/io_null
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/io_mem
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/io_dun
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/i2s/int
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/i2s
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/i2c/polled
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/i2c/int
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/i2c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/hwtimer
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/hmi/TSS/shared
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/hmi
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/gpio/kgpio
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/gpio
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/flashx/freescale
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/flashx
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/esdhc
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/enet/phy
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/enet/macnet
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/enet
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/debug
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/cm
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/can/flexcan
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/adc/kadc
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/adc
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io
INCLUDE += $(MQX_ROOTDIR)/mqx/source/include
INCLUDE += $(MQX_ROOTDIR)/mqx/source/fio
INCLUDE += $(MQX_ROOTDIR)/mqx/source/bsp/twrk60n512
INCLUDE += $(MQX_ROOTDIR)/config/twrk60n512
INCLUDE += $(MQX_ROOTDIR)/config/common

#-----------------------------------------------------------
# doc
#-----------------------------------------------------------

#-----------------------------------------------------------
# include
#-----------------------------------------------------------
INCLUDE += $(MQX_ROOTDIR)/mfs/source/include

#-----------------------------------------------------------
# source
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mfs/source/generic/part_mgr.c
SOURCES += $(MQX_ROOTDIR)/mfs/source/generic/mfs_write.c
SOURCES += $(MQX_ROOTDIR)/mfs/source/generic/mfs_valdev.c
SOURCES += $(MQX_ROOTDIR)/mfs/source/generic/mfs_time.c
SOURCES += $(MQX_ROOTDIR)/mfs/source/generic/mfs_search.c
SOURCES += $(MQX_ROOTDIR)/mfs/source/generic/mfs_rw.c
SOURCES += $(MQX_ROOTDIR)/mfs/source/generic/mfs_rename.c
SOURCES += $(MQX_ROOTDIR)/mfs/source/generic/mfs_read.c
SOURCES += $(MQX_ROOTDIR)/mfs/source/generic/mfs_parse.c
SOURCES += $(MQX_ROOTDIR)/mfs/source/generic/mfs_open.c
SOURCES += $(MQX_ROOTDIR)/mfs/source/generic/mfs_misc.c
SOURCES += $(MQX_ROOTDIR)/mfs/source/generic/mfs_lfn.c
SOURCES += $(MQX_ROOTDIR)/mfs/source/generic/mfs_init.c
SOURCES += $(MQX_ROOTDIR)/mfs/source/generic/mfs_handle.c
SOURCES += $(MQX_ROOTDIR)/mfs/source/generic/mfs_format.c
SOURCES += $(MQX_ROOTDIR)/mfs/source/generic/mfs_fat.c
SOURCES += $(MQX_ROOTDIR)/mfs/source/generic/mfs_directory.c
SOURCES += $(MQX_ROOTDIR)/mfs/source/generic/mfs_dir_entry.c
SOURCES += $(MQX_ROOTDIR)/mfs/source/generic/mfs_delete.c
SOURCES += $(MQX_ROOTDIR)/mfs/source/generic/mfs_data_sector.c
SOURCES += $(MQX_ROOTDIR)/mfs/source/generic/mfs_create.c
SOURCES += $(MQX_ROOTDIR)/mfs/source/generic/mfs_cluster.c
SOURCES += $(MQX_ROOTDIR)/mfs/source/generic/mfs_attribute.c
SOURCES += $(MQX_ROOTDIR)/mfs/source/generic/dir_read.c


#----------------------------------------------------------
# include partial makefiles
#----------------------------------------------------------
include $(MQX_ROOTDIR)/build/common/make/global.mak
-include $(MQX_ROOTDIR)/build/$(BOARD)/make/tools/$(TOOL).mak
include $(MQX_ROOTDIR)/build/common/make/verify.mak
include $(MQX_ROOTDIR)/build/common/make/lib-process.mak
#----------------------------------------------------------
