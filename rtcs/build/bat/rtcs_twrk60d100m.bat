@echo off

rem convert path to backslash format
set MQXROOTDIR=%1
set MQXROOTDIR=%MQXROOTDIR:/=\%
set OUTPUTDIR=%2
set OUTPUTDIR=%OUTPUTDIR:/=\%
set TOOL=%3


rem copy common files
IF NOT EXIST %OUTPUTDIR% mkdir %OUTPUTDIR%
copy %MQXROOTDIR%\rtcs\source\httpd\httpd.h %OUTPUTDIR%\httpd.h /Y
copy %MQXROOTDIR%\rtcs\source\httpd\httpd_cnfg.h %OUTPUTDIR%\httpd_cnfg.h /Y
copy %MQXROOTDIR%\rtcs\source\httpd\httpd_mqx.h %OUTPUTDIR%\httpd_mqx.h /Y
copy %MQXROOTDIR%\rtcs\source\httpd\httpd_supp.h %OUTPUTDIR%\httpd_supp.h /Y
copy %MQXROOTDIR%\rtcs\source\httpd\httpd_types.h %OUTPUTDIR%\httpd_types.h /Y
copy %MQXROOTDIR%\rtcs\source\httpd\httpd_wrapper.h %OUTPUTDIR%\httpd_wrapper.h /Y
copy %MQXROOTDIR%\rtcs\source\include\addrinfo.h %OUTPUTDIR%\addrinfo.h /Y
copy %MQXROOTDIR%\rtcs\source\include\arp.h %OUTPUTDIR%\arp.h /Y
copy %MQXROOTDIR%\rtcs\source\include\arpif.h %OUTPUTDIR%\arpif.h /Y
copy %MQXROOTDIR%\rtcs\source\include\asn1.h %OUTPUTDIR%\asn1.h /Y
copy %MQXROOTDIR%\rtcs\source\include\bootp.h %OUTPUTDIR%\bootp.h /Y
copy %MQXROOTDIR%\rtcs\source\include\ccp.h %OUTPUTDIR%\ccp.h /Y
copy %MQXROOTDIR%\rtcs\source\include\chap.h %OUTPUTDIR%\chap.h /Y
copy %MQXROOTDIR%\rtcs\source\include\checksum.h %OUTPUTDIR%\checksum.h /Y
copy %MQXROOTDIR%\rtcs\source\include\dhcp.h %OUTPUTDIR%\dhcp.h /Y
copy %MQXROOTDIR%\rtcs\source\include\dhcpsrv.h %OUTPUTDIR%\dhcpsrv.h /Y
copy %MQXROOTDIR%\rtcs\source\include\dns.h %OUTPUTDIR%\dns.h /Y
copy %MQXROOTDIR%\rtcs\source\include\fcs16.h %OUTPUTDIR%\fcs16.h /Y
copy %MQXROOTDIR%\rtcs\source\include\ftp.h %OUTPUTDIR%\ftp.h /Y
copy %MQXROOTDIR%\rtcs\source\include\ftpc.h %OUTPUTDIR%\ftpc.h /Y
copy %MQXROOTDIR%\rtcs\source\include\ftpd.h %OUTPUTDIR%\ftpd.h /Y
copy %MQXROOTDIR%\rtcs\source\include\ftpd_msg.h %OUTPUTDIR%\ftpd_msg.h /Y
copy %MQXROOTDIR%\rtcs\source\include\icmp.h %OUTPUTDIR%\icmp.h /Y
copy %MQXROOTDIR%\rtcs\source\include\icmp6.h %OUTPUTDIR%\icmp6.h /Y
copy %MQXROOTDIR%\rtcs\source\include\icmp6_prv.h %OUTPUTDIR%\icmp6_prv.h /Y
copy %MQXROOTDIR%\rtcs\source\include\igmp.h %OUTPUTDIR%\igmp.h /Y
copy %MQXROOTDIR%\rtcs\source\include\ip-e.h %OUTPUTDIR%\ip-e.h /Y
copy %MQXROOTDIR%\rtcs\source\include\ip.h %OUTPUTDIR%\ip.h /Y
copy %MQXROOTDIR%\rtcs\source\include\ip6.h %OUTPUTDIR%\ip6.h /Y
copy %MQXROOTDIR%\rtcs\source\include\ip6_if.h %OUTPUTDIR%\ip6_if.h /Y
copy %MQXROOTDIR%\rtcs\source\include\ip6_prv.h %OUTPUTDIR%\ip6_prv.h /Y
copy %MQXROOTDIR%\rtcs\source\include\ip6_trace.h %OUTPUTDIR%\ip6_trace.h /Y
copy %MQXROOTDIR%\rtcs\source\include\ipc_udp.h %OUTPUTDIR%\ipc_udp.h /Y
copy %MQXROOTDIR%\rtcs\source\include\ipcfg.h %OUTPUTDIR%\ipcfg.h /Y
copy %MQXROOTDIR%\rtcs\source\include\ipcp.h %OUTPUTDIR%\ipcp.h /Y
copy %MQXROOTDIR%\rtcs\source\include\ipradix.h %OUTPUTDIR%\ipradix.h /Y
copy %MQXROOTDIR%\rtcs\source\include\iptunnel.h %OUTPUTDIR%\iptunnel.h /Y
copy %MQXROOTDIR%\rtcs\source\include\iwcfg.h %OUTPUTDIR%\iwcfg.h /Y
copy %MQXROOTDIR%\rtcs\source\include\lcp.h %OUTPUTDIR%\lcp.h /Y
copy %MQXROOTDIR%\rtcs\source\include\md5.h %OUTPUTDIR%\md5.h /Y
copy %MQXROOTDIR%\rtcs\source\include\nat.h %OUTPUTDIR%\nat.h /Y
copy %MQXROOTDIR%\rtcs\source\include\nat_session.h %OUTPUTDIR%\nat_session.h /Y
copy %MQXROOTDIR%\rtcs\source\include\natvers.h %OUTPUTDIR%\natvers.h /Y
copy %MQXROOTDIR%\rtcs\source\include\nd6.h %OUTPUTDIR%\nd6.h /Y
copy %MQXROOTDIR%\rtcs\source\include\pap.h %OUTPUTDIR%\pap.h /Y
copy %MQXROOTDIR%\rtcs\source\include\ppp.h %OUTPUTDIR%\ppp.h /Y
copy %MQXROOTDIR%\rtcs\source\include\pppfsm.h %OUTPUTDIR%\pppfsm.h /Y
copy %MQXROOTDIR%\rtcs\source\include\ppphdlc.h %OUTPUTDIR%\ppphdlc.h /Y
copy %MQXROOTDIR%\rtcs\source\include\rip.h %OUTPUTDIR%\rip.h /Y
copy %MQXROOTDIR%\rtcs\source\include\route.h %OUTPUTDIR%\route.h /Y
copy %MQXROOTDIR%\rtcs\source\include\rtcs.h %OUTPUTDIR%\rtcs.h /Y
copy %MQXROOTDIR%\rtcs\source\include\rtcs25x.h %OUTPUTDIR%\rtcs25x.h /Y
copy %MQXROOTDIR%\rtcs\source\include\rtcs_in.h %OUTPUTDIR%\rtcs_in.h /Y
copy %MQXROOTDIR%\rtcs\source\include\rtcscfg.h %OUTPUTDIR%\rtcscfg.h /Y
copy %MQXROOTDIR%\rtcs\source\include\rtcshdlc.h %OUTPUTDIR%\rtcshdlc.h /Y
copy %MQXROOTDIR%\rtcs\source\include\rtcslog.h %OUTPUTDIR%\rtcslog.h /Y
copy %MQXROOTDIR%\rtcs\source\include\rtcspcb.h %OUTPUTDIR%\rtcspcb.h /Y
copy %MQXROOTDIR%\rtcs\source\include\rtcsrtos.h %OUTPUTDIR%\rtcsrtos.h /Y
copy %MQXROOTDIR%\rtcs\source\include\rtcstime.h %OUTPUTDIR%\rtcstime.h /Y
copy %MQXROOTDIR%\rtcs\source\include\rtcsvers.h %OUTPUTDIR%\rtcsvers.h /Y
copy %MQXROOTDIR%\rtcs\source\include\select.h %OUTPUTDIR%\select.h /Y
copy %MQXROOTDIR%\rtcs\source\include\snmp.h %OUTPUTDIR%\snmp.h /Y
copy %MQXROOTDIR%\rtcs\source\include\snmpcfg.h %OUTPUTDIR%\snmpcfg.h /Y
copy %MQXROOTDIR%\rtcs\source\include\socket.h %OUTPUTDIR%\socket.h /Y
copy %MQXROOTDIR%\rtcs\source\include\tcp.h %OUTPUTDIR%\tcp.h /Y
copy %MQXROOTDIR%\rtcs\source\include\tcpip.h %OUTPUTDIR%\tcpip.h /Y
copy %MQXROOTDIR%\rtcs\source\include\telnet.h %OUTPUTDIR%\telnet.h /Y
copy %MQXROOTDIR%\rtcs\source\include\tftp.h %OUTPUTDIR%\tftp.h /Y
copy %MQXROOTDIR%\rtcs\source\include\ticker.h %OUTPUTDIR%\ticker.h /Y
copy %MQXROOTDIR%\rtcs\source\include\udp.h %OUTPUTDIR%\udp.h /Y


goto tool_%TOOL%

rem cw10 files
:tool_cw10
goto copy_end

rem iar files
:tool_iar
goto copy_end

rem cw10gcc files
:tool_cw10gcc
goto copy_end

rem uv4 files
:tool_uv4
goto copy_end

:copy_end

