#----------------------------------------------------------
# setup variables
#----------------------------------------------------------
MQX_ROOTDIR             = $(abspath ../../../..)
LIBRARY_ROOTDIR         = $(MQX_ROOTDIR)/lib/$(BOARD).$(TOOL)
override TYPE           = library
override NAME           = rtcs
override BOARD          = twrk60n512
override POSTBUILD_CMD  = $(call GET_POSTBUILD_CMD,rtcs/build/bat/rtcs_twrk60n512)
override LIBRARY_DIR    = $(LIBRARY_ROOTDIR)/$(CONFIG)/rtcs
override LIBRARY_FILE   = $(LIBRARY_DIR)/rtcs.$(LIBRARY_EXT)

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
INCLUDE += $(MQX_ROOTDIR)/mfs/source/include
INCLUDE += $(MQX_ROOTDIR)/mfs/source/generic
INCLUDE += $(MQX_ROOTDIR)/config/twrk60n512
INCLUDE += $(MQX_ROOTDIR)/config/common

#-----------------------------------------------------------
# apps
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/rtcs/source/apps/tftputil.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/apps/tftpsrv.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/apps/tftpacc.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/apps/tftp.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/apps/telnsrv.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/apps/telnetio.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/apps/telnet.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/apps/srecord.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/apps/srec32.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/apps/sockio.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/apps/sntp.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/apps/rtcssh.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/apps/rtcsload.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/apps/resolver.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/apps/loadts.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/apps/loadtc.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/apps/loadtb.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/apps/ftpd_msg.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/apps/ftpd_cmd.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/apps/ftpd.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/apps/ftpclnt.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/apps/ftpc_cmd.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/apps/ftpc.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/apps/eds.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/apps/echosrv.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/apps/dhcpsrv.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/apps/coff.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/apps/binfile.c

#-----------------------------------------------------------
# doc
#-----------------------------------------------------------

#-----------------------------------------------------------
# httpd
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/rtcs/source/httpd/httpd_task.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/httpd/httpd_supp.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/httpd/httpd_poll.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/httpd/httpd.c
INCLUDE += $(MQX_ROOTDIR)/rtcs/source/httpd

#-----------------------------------------------------------
# if
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/sstream.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/soudp.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/sotcp.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/sosock.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/soselset.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/soselall.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/sosel1.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/sosel0.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/solink.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/soip.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/soigmp.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/sockutil.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/select.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/sdgram.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/rtcsrand.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/rtcslog1.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/rtcslog0.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/rtcsinit.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/rtcshost.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/rtcsglob.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/rtcsdela.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/rtcscmd.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/rtcs.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/ping6.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/ping.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/iwcfg.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/ipcfg6.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/ipcfg.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/inet_pton.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/inet_ntop.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/inet.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/iftunnel.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/iftraps.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/ifstat.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/ifrem.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/ifppp.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/ifdns.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/ifdhcp.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/ifbootp.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/ifadd.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/ghbname.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/getnameinfo.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/getaddrinfo.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/dnsutil.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/dnsinit.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/dnshosts.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/if/arpcmd.c

#-----------------------------------------------------------
# include
#-----------------------------------------------------------
INCLUDE += $(MQX_ROOTDIR)/rtcs/source/include

#-----------------------------------------------------------
# media
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/rtcs/source/media/proxyarp.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/media/ipcpfsm.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/media/ipcp.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/media/ip6-e.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/media/ip-e.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/media/arpinit.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/media/arp.c

#-----------------------------------------------------------
# nat
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/rtcs/source/nat/sonat.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/nat/nattftp.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/nat/natftp.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/nat/natevent.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/nat/natdata.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/nat/natalg.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/nat/nat_apply.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/nat/nat.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/nat/ifnat.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/nat/ifdnat.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/nat/dnat.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/nat/alggen.c

#-----------------------------------------------------------
# os
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/rtcs/source/os/mqx25x/rtcstask.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/os/mqx25x/rtcssec.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/os/mqx25x/rtcspart.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/os/mqx25x/rtcsmsg.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/os/mqx25x/rtcsmsec.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/os/mqx25x/rtcsdate.c

#-----------------------------------------------------------
# ppp
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/rtcs/source/ppp/ppphdlc.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/ppp/pppglob.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/ppp/pppfsm.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/ppp/ppp.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/ppp/pkttx.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/ppp/pktrx.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/ppp/pap.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/ppp/md5step.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/ppp/md5.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/ppp/lcpif.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/ppp/lcp.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/ppp/hdlcio2.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/ppp/hdlcio.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/ppp/genmd5.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/ppp/gen16.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/ppp/chap.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/ppp/ccp.c

#-----------------------------------------------------------
# rpc
#-----------------------------------------------------------

#-----------------------------------------------------------
# snmp
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/rtcs/source/snmp/traps.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/snmp/trap_receivers.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/snmp/snmp.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/snmp/mqxmib.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/snmp/mib.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/snmp/1213.c

#-----------------------------------------------------------
# tcpip
#-----------------------------------------------------------
SOURCES += $(MQX_ROOTDIR)/rtcs/source/tcpip/udp.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/tcpip/timer.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/tcpip/ticker.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/tcpip/tcpip.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/tcpip/tcp_send.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/tcpip/tcp_rcv.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/tcpip/tcp_clos.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/tcpip/tcp_buf.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/tcpip/tcp.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/tcpip/rtcspcb.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/tcpip/route.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/tcpip/rip.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/tcpip/iputil.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/tcpip/iptunnel.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/tcpip/iproute.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/tcpip/ipradix.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/tcpip/iplocal.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/tcpip/ipif_rem.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/tcpip/ipif_add.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/tcpip/ip_reasm.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/tcpip/ip.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/tcpip/igmputil.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/tcpip/igmp.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/tcpip/icmp.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/tcpip/dhcputil.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/tcpip/dhcpclnt.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/tcpip/checksum6.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/tcpip/checksum.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/tcpip/bootp.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/tcpip/bootinit.c
SOURCES += $(MQX_ROOTDIR)/rtcs/source/tcpip/bootcomm.c

#-----------------------------------------------------------
# xdr
#-----------------------------------------------------------


#----------------------------------------------------------
# include partial makefiles
#----------------------------------------------------------
include $(MQX_ROOTDIR)/build/common/make/global.mak
-include $(MQX_ROOTDIR)/build/$(BOARD)/make/tools/$(TOOL).mak
include $(MQX_ROOTDIR)/build/common/make/verify.mak
include $(MQX_ROOTDIR)/build/common/make/lib-process.mak
#----------------------------------------------------------
