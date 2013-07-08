#!/bin/sh

# expect forward slash paths
MQXROOTDIR="${1}"
OUTPUTDIR="${2}"
TOOL="${3}"


# copy common files
mkdir -p "${OUTPUTDIR}"
cp -f "${MQXROOTDIR}/rtcs/source/httpd/httpd.h" "${OUTPUTDIR}/httpd.h"
cp -f "${MQXROOTDIR}/rtcs/source/httpd/httpd_cnfg.h" "${OUTPUTDIR}/httpd_cnfg.h"
cp -f "${MQXROOTDIR}/rtcs/source/httpd/httpd_mqx.h" "${OUTPUTDIR}/httpd_mqx.h"
cp -f "${MQXROOTDIR}/rtcs/source/httpd/httpd_supp.h" "${OUTPUTDIR}/httpd_supp.h"
cp -f "${MQXROOTDIR}/rtcs/source/httpd/httpd_types.h" "${OUTPUTDIR}/httpd_types.h"
cp -f "${MQXROOTDIR}/rtcs/source/httpd/httpd_wrapper.h" "${OUTPUTDIR}/httpd_wrapper.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/addrinfo.h" "${OUTPUTDIR}/addrinfo.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/arp.h" "${OUTPUTDIR}/arp.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/arpif.h" "${OUTPUTDIR}/arpif.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/asn1.h" "${OUTPUTDIR}/asn1.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/bootp.h" "${OUTPUTDIR}/bootp.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/ccp.h" "${OUTPUTDIR}/ccp.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/chap.h" "${OUTPUTDIR}/chap.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/checksum.h" "${OUTPUTDIR}/checksum.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/dhcp.h" "${OUTPUTDIR}/dhcp.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/dhcpsrv.h" "${OUTPUTDIR}/dhcpsrv.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/dns.h" "${OUTPUTDIR}/dns.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/fcs16.h" "${OUTPUTDIR}/fcs16.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/ftp.h" "${OUTPUTDIR}/ftp.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/ftpc.h" "${OUTPUTDIR}/ftpc.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/ftpd.h" "${OUTPUTDIR}/ftpd.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/ftpd_msg.h" "${OUTPUTDIR}/ftpd_msg.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/icmp.h" "${OUTPUTDIR}/icmp.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/icmp6.h" "${OUTPUTDIR}/icmp6.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/icmp6_prv.h" "${OUTPUTDIR}/icmp6_prv.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/igmp.h" "${OUTPUTDIR}/igmp.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/ip-e.h" "${OUTPUTDIR}/ip-e.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/ip.h" "${OUTPUTDIR}/ip.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/ip6.h" "${OUTPUTDIR}/ip6.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/ip6_if.h" "${OUTPUTDIR}/ip6_if.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/ip6_prv.h" "${OUTPUTDIR}/ip6_prv.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/ip6_trace.h" "${OUTPUTDIR}/ip6_trace.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/ipc_udp.h" "${OUTPUTDIR}/ipc_udp.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/ipcfg.h" "${OUTPUTDIR}/ipcfg.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/ipcp.h" "${OUTPUTDIR}/ipcp.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/ipradix.h" "${OUTPUTDIR}/ipradix.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/iptunnel.h" "${OUTPUTDIR}/iptunnel.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/iwcfg.h" "${OUTPUTDIR}/iwcfg.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/lcp.h" "${OUTPUTDIR}/lcp.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/md5.h" "${OUTPUTDIR}/md5.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/nat.h" "${OUTPUTDIR}/nat.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/nat_session.h" "${OUTPUTDIR}/nat_session.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/natvers.h" "${OUTPUTDIR}/natvers.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/nd6.h" "${OUTPUTDIR}/nd6.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/pap.h" "${OUTPUTDIR}/pap.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/ppp.h" "${OUTPUTDIR}/ppp.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/pppfsm.h" "${OUTPUTDIR}/pppfsm.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/ppphdlc.h" "${OUTPUTDIR}/ppphdlc.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/rip.h" "${OUTPUTDIR}/rip.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/route.h" "${OUTPUTDIR}/route.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/rtcs.h" "${OUTPUTDIR}/rtcs.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/rtcs25x.h" "${OUTPUTDIR}/rtcs25x.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/rtcs_in.h" "${OUTPUTDIR}/rtcs_in.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/rtcscfg.h" "${OUTPUTDIR}/rtcscfg.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/rtcshdlc.h" "${OUTPUTDIR}/rtcshdlc.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/rtcslog.h" "${OUTPUTDIR}/rtcslog.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/rtcspcb.h" "${OUTPUTDIR}/rtcspcb.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/rtcsrtos.h" "${OUTPUTDIR}/rtcsrtos.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/rtcstime.h" "${OUTPUTDIR}/rtcstime.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/rtcsvers.h" "${OUTPUTDIR}/rtcsvers.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/select.h" "${OUTPUTDIR}/select.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/snmp.h" "${OUTPUTDIR}/snmp.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/snmpcfg.h" "${OUTPUTDIR}/snmpcfg.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/socket.h" "${OUTPUTDIR}/socket.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/tcp.h" "${OUTPUTDIR}/tcp.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/tcpip.h" "${OUTPUTDIR}/tcpip.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/telnet.h" "${OUTPUTDIR}/telnet.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/tftp.h" "${OUTPUTDIR}/tftp.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/ticker.h" "${OUTPUTDIR}/ticker.h"
cp -f "${MQXROOTDIR}/rtcs/source/include/udp.h" "${OUTPUTDIR}/udp.h"


# cw10 files
if [ "${TOOL}" = "cw10" ]; then
:
fi
# iar files
if [ "${TOOL}" = "iar" ]; then
:
fi
# cw10gcc files
if [ "${TOOL}" = "cw10gcc" ]; then
:
fi
# uv4 files
if [ "${TOOL}" = "uv4" ]; then
:
fi

