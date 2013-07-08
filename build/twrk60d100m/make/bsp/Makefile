#----------------------------------------------------------
# setup variables
#----------------------------------------------------------
MQX_ROOTDIR             = $(abspath ../../../..)
LIBRARY_ROOTDIR         = $(MQX_ROOTDIR)/lib/$(BOARD).$(TOOL)
override TYPE           = library
override NAME           = bsp
override BOARD          = twrk60d100m
override POSTBUILD_CMD  = $(call GET_POSTBUILD_CMD,mqx/build/bat/bsp_twrk60d100m)
override LIBRARY_DIR    = $(LIBRARY_ROOTDIR)/$(CONFIG)/bsp
override LIBRARY_FILE   = $(LIBRARY_DIR)/bsp.$(LIBRARY_EXT)

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
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io
INCLUDE += $(MQX_ROOTDIR)/mqx/source/include
INCLUDE += $(MQX_ROOTDIR)/mqx/source/fio
INCLUDE += $(MQX_ROOTDIR)/config/twrk60d100m
INCLUDE += $(MQX_ROOTDIR)/config/common

#-----------------------------------------------------------
# adc
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/adc/kadc/adt_kpdb.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/adc/kadc/adc_mk60.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/adc/kadc/adc_kadc.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/adc/adc.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/adc/kadc
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/adc

#-----------------------------------------------------------
# cm
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/cm/cm.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/cm

#-----------------------------------------------------------
# config
#-----------------------------------------------------------
INCLUDE += $(MQX_ROOTDIR)/config/twrk60d100m

#-----------------------------------------------------------
# crc
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/crc/crc_kn.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/crc

#-----------------------------------------------------------
# enet
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/enet/phy/phy_ksz8041.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/enet/macnet/macnet_util.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/enet/macnet/macnet_stop.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/enet/macnet/macnet_send.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/enet/macnet/macnet_rejoin.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/enet/macnet/macnet_receive.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/enet/macnet/macnet_mk60.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/enet/macnet/macnet_mii.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/enet/macnet/macnet_join.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/enet/macnet/macnet_init.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/enet/macnet/macnet_1588.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/enet/enutil.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/enet/enstop.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/enet/enstat.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/enet/ensend.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/enet/enrecv.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/enet/enopen.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/enet/enmediactl.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/enet/enleave.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/enet/enjoin.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/enet/eninit.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/enet/enerr.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/enet/enclose.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/enet/enaddr.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/enet/phy
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/enet/macnet
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/enet

#-----------------------------------------------------------
# esdhc
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/esdhc/esdhc_mk60.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/esdhc/esdhc.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/esdhc

#-----------------------------------------------------------
# flashx
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/flashx/freescale/flash_mk60.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/flashx/freescale/flash_ftfl.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/flashx/flashx.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/flashx/freescale
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/flashx

#-----------------------------------------------------------
# flexcan
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/can/flexcan/kflexcan_int.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/can/flexcan/kflexcan.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/can/flexcan/flexcan_mk60.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/can/flexcan

#-----------------------------------------------------------
# gpio
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/gpio/kgpio/io_gpio_kgpio.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/gpio/io_gpio.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/gpio/kgpio
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/gpio

#-----------------------------------------------------------
# hwtimer
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/hwtimer/hwtimer_pit.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/hwtimer/hwtimer_kinetis.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/hwtimer/hwtimer.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/hwtimer

#-----------------------------------------------------------
# i2c
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/i2c/polled/i2c_pol_ki2c.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/i2c/polled/i2c_pol.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/i2c/int/i2c_int_ki2c.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/i2c/int/i2c_int.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/i2c/i2c_mk60.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/i2c/polled
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/i2c/int
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/i2c

#-----------------------------------------------------------
# init
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/bsp/twrk60d100m/init_usb.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/bsp/twrk60d100m/init_tchres.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/bsp/twrk60d100m/init_spi.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/bsp/twrk60d100m/init_sdcard.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/bsp/twrk60d100m/init_sci.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/bsp/twrk60d100m/init_sai.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/bsp/twrk60d100m/init_lpm.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/bsp/twrk60d100m/init_iodebug.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/bsp/twrk60d100m/init_i2c.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/bsp/twrk60d100m/init_hw.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/bsp/twrk60d100m/init_gpio.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/bsp/twrk60d100m/init_flashx.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/bsp/twrk60d100m/init_esdhc.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/bsp/twrk60d100m/init_enet.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/bsp/twrk60d100m/init_cfcard.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/bsp/twrk60d100m/init_adc.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/bsp/twrk60d100m/bsp_cm.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/include
INCLUDE += $(MQX_ROOTDIR)/mqx/source/bsp/twrk60d100m
INCLUDE += $(MQX_ROOTDIR)/config/common

#-----------------------------------------------------------
# init-common
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/bsp/twrk60d100m/vectors.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/bsp/twrk60d100m/mqx_main.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/bsp/twrk60d100m/mqx_init.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/bsp/twrk60d100m/init_bsp.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/enet
INCLUDE += $(MQX_ROOTDIR)/mqx/source/bsp/twrk60d100m

#-----------------------------------------------------------
# iodebug
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/debug/iodebug_asm.S
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/debug/iodebug.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/debug

#-----------------------------------------------------------
# iodun
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/io_dun/io_dun.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/io_dun

#-----------------------------------------------------------
# iomem
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/io_mem/io_mem.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/io_mem

#-----------------------------------------------------------
# ionull
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/io_null/io_null.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/io_null

#-----------------------------------------------------------
# iopipe
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/pipe/io_pipe.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/pipe

#-----------------------------------------------------------
# lpm
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/lpm/lpm_smc.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/lpm/lpm.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/lpm

#-----------------------------------------------------------
# lwgpio
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/lwgpio/lwgpio_kgpio.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/lwgpio/lwgpio.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/lwgpio

#-----------------------------------------------------------
# pcb
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/pcb/mqxa/pcb_mqxa.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/pcb/iop_inst.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/pcb/io_pcb2.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/pcb/io_pcb.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/pcb/mqxa
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/pcb

#-----------------------------------------------------------
# pccard
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/pccard/pccardflexbus.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/pccard

#-----------------------------------------------------------
# pcflash
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/pcflash/apcflash.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/pcflash

#-----------------------------------------------------------
# rtc
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/rtc/krtc.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/rtc

#-----------------------------------------------------------
# sai
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/sai/sai_mk60.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/sai/int/sai_int_ksai.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/sai/int/sai_int.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/sai/int
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/sai

#-----------------------------------------------------------
# sdcard
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/sdcard/sdcard_spi/sdcard_spi.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/sdcard/sdcard_esdhc/sdcard_esdhc.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/sdcard/sdcard.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/sdcard/sdcard_spi
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/sdcard/sdcard_esdhc
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/sdcard

#-----------------------------------------------------------
# serial
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/serial/serl_mk60.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/serial/polled/serl_pol_kuart.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/serial/polled/serl_pol.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/serial/io_sinit.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/serial/int/serl_int_kuart.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/serial/int/serl_int.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/serial

#-----------------------------------------------------------
# spi
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/spi/spi_mk60.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/spi/spi_dspi.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/spi/spi.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/spi

#-----------------------------------------------------------
# tchres
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/tchres/tchres.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/tchres

#-----------------------------------------------------------
# tfs
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/tfs/tfs.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/tfs

#-----------------------------------------------------------
# timer
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/timer/timer_qpit.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/timer/timer_lpt_kinetis.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/timer/timer_lpt.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/timer/timer_kinetis.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/timer

#-----------------------------------------------------------
# usb
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/usb/usb_mk60_device.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/usb/usb_mk60.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/usb/usb_install.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/io/usb


#----------------------------------------------------------
# include partial makefiles
#----------------------------------------------------------
include $(MQX_ROOTDIR)/build/common/make/global.mak
-include $(MQX_ROOTDIR)/build/$(BOARD)/make/tools/$(TOOL).mak
include $(MQX_ROOTDIR)/build/common/make/verify.mak
include $(MQX_ROOTDIR)/build/common/make/lib-process.mak
#----------------------------------------------------------
