#----------------------------------------------------------
# setup variables
#----------------------------------------------------------
MQX_ROOTDIR             = $(abspath ../../../..)
LIBRARY_ROOTDIR         = $(MQX_ROOTDIR)/lib/$(BOARD).$(TOOL)
override TYPE           = library
override NAME           = psp
override BOARD          = twrk60d100m
override POSTBUILD_CMD  = $(call GET_POSTBUILD_CMD,mqx/build/bat/psp_twrk60d100m)
override LIBRARY_DIR    = $(LIBRARY_ROOTDIR)/$(CONFIG)/psp
override LIBRARY_FILE   = $(LIBRARY_DIR)/psp.$(LIBRARY_EXT)

#-----------------------------------------------------------
# cw10 sources/include
#-----------------------------------------------------------
ifeq ($(TOOL),cw10)
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/compiler/cw/comp.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/compiler/cw
endif
#-----------------------------------------------------------
# cw10gcc sources/include
#-----------------------------------------------------------
ifeq ($(TOOL),cw10gcc)
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/compiler/gcc_cw/comp.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/compiler/gcc_cw
endif
#-----------------------------------------------------------
# iar sources/include
#-----------------------------------------------------------
ifeq ($(TOOL),iar)
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/compiler/iar/comp.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/compiler/iar/kernel_symbols.S
INCLUDE += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/compiler/iar
endif
#-----------------------------------------------------------
# uv4 sources/include
#-----------------------------------------------------------
ifeq ($(TOOL),uv4)
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/compiler/rv/comp.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/compiler/rv/linker_symbols.S
INCLUDE += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/compiler/rv
endif


#-----------------------------------------------------------
# cross library include
#-----------------------------------------------------------
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
INCLUDE += $(MQX_ROOTDIR)/mqx/source/include
INCLUDE += $(MQX_ROOTDIR)/mqx/source/bsp/twrk60d100m
INCLUDE += $(MQX_ROOTDIR)/config/twrk60d100m
INCLUDE += $(MQX_ROOTDIR)/config/common

#-----------------------------------------------------------
# architecture
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/stack_st.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/stack_de.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/stack_bu.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/sc_irdyq.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/psp_usti.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/psp_tkti.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/psp_tixd.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/psp_tius.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/psp_tisu.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/psp_tise.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/psp_tips.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/psp_tipr.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/psp_tiol.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/psp_tins.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/psp_tinm.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/psp_tims.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/psp_timn.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/psp_tihr.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/psp_tida.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/psp_tiad.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/psp_supp.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/psp_seti.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/psp_psti.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/psp_nsti.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/psp_mstiq.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/psp_msti.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/psp_miti.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/psp_mat3.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/psp_mat2.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/psp_mat1.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/psp_iinit.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/psp_hoti.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/psp_gelms.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/psp_dati.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/nvic.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/mem_zero.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/mem_copy.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/kinetis_mpu.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/ipsum.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/int_xcpt.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/int_vtab.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/int_unx.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/int_pvta.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/int_kisr.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/int_inst.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/int_gkis.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/cortex.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/core/M4/dispatch.S
SOURCES += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/core/M4/boot.S
INCLUDE += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/cpu
INCLUDE += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m/core/M4
INCLUDE += $(MQX_ROOTDIR)/mqx/source/psp/cortex_m

#-----------------------------------------------------------
# config
#-----------------------------------------------------------
INCLUDE += $(MQX_ROOTDIR)/config/twrk60d100m
INCLUDE += $(MQX_ROOTDIR)/config/common

#-----------------------------------------------------------
# doc
#-----------------------------------------------------------

#-----------------------------------------------------------
# event
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/event.c

#-----------------------------------------------------------
# fio
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_write.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_vpr.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_util.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_sscan.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_spr.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_scanl.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_scanf.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_read.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_pntf.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_misc.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_ioctl.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_fung.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_ftell.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_fstat.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_fseek.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_fscan.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_fputs.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_fputc.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_fprt.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_fp.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_fopen.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_fgets.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_fgetl.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_fgetc.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_fflsh.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_ferr.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_feof.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_fclos.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_dopr.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/fio/io_clre.c

#-----------------------------------------------------------
# include
#-----------------------------------------------------------
INCLUDE += $(MQX_ROOTDIR)/mqx/source/include

#-----------------------------------------------------------
# io
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/io_uinst.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/io_shand.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/io_instx.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/io_inst.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/io_init.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/io/io_ghand.c

#-----------------------------------------------------------
# ipc
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/ipc.c

#-----------------------------------------------------------
# kernel
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/time_tables.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/time.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/taskq.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/task.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/sched.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/mqx.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/mem.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/lwsem.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/int.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/idletask.c

#-----------------------------------------------------------
# klog
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/klog.c

#-----------------------------------------------------------
# log
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/log.c

#-----------------------------------------------------------
# lwevent
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/lwevent.c

#-----------------------------------------------------------
# lwlog
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/lwlog.c

#-----------------------------------------------------------
# lwmem
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/lwmem.c

#-----------------------------------------------------------
# lwmsg
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/lwmsgq.c

#-----------------------------------------------------------
# lwtimer
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/lwtimer.c

#-----------------------------------------------------------
# message
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/msgq.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/msgpool.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/msg.c

#-----------------------------------------------------------
# mutex
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/mutex.c

#-----------------------------------------------------------
# name
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/name.c

#-----------------------------------------------------------
# part
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/partition.c

#-----------------------------------------------------------
# queue
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/queue.c

#-----------------------------------------------------------
# sem
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/sem.c

#-----------------------------------------------------------
# specific
#-----------------------------------------------------------

#-----------------------------------------------------------
# string
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/string/strnlen.c
SOURCES += $(MQX_ROOTDIR)/mqx/source/string/str_utos.c

#-----------------------------------------------------------
# tad
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/tad/tad.c
INCLUDE += $(MQX_ROOTDIR)/mqx/source/tad

#-----------------------------------------------------------
# timer
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/timer.c

#-----------------------------------------------------------
# watchdog
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/mqx/source/kernel/watchdog.c


#----------------------------------------------------------
# include partial makefiles
#----------------------------------------------------------
include $(MQX_ROOTDIR)/build/common/make/global.mak
-include $(MQX_ROOTDIR)/build/$(BOARD)/make/tools/$(TOOL).mak
include $(MQX_ROOTDIR)/build/common/make/verify.mak
include $(MQX_ROOTDIR)/build/common/make/lib-process.mak
#----------------------------------------------------------
