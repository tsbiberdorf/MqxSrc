@echo off

rem convert path to backslash format
set MQXROOTDIR=%1
set MQXROOTDIR=%MQXROOTDIR:/=\%
set OUTPUTDIR=%2
set OUTPUTDIR=%OUTPUTDIR:/=\%
set TOOL=%3


rem copy common files
IF NOT EXIST %OUTPUTDIR% mkdir %OUTPUTDIR%
copy %MQXROOTDIR%\config\common\small_ram_config.h %OUTPUTDIR%\small_ram_config.h /Y
copy %MQXROOTDIR%\mqx\source\include\charq.h %OUTPUTDIR%\charq.h /Y
copy %MQXROOTDIR%\mqx\source\include\eds.h %OUTPUTDIR%\eds.h /Y
copy %MQXROOTDIR%\mqx\source\include\edserial.h %OUTPUTDIR%\edserial.h /Y
copy %MQXROOTDIR%\mqx\source\include\event.h %OUTPUTDIR%\event.h /Y
copy %MQXROOTDIR%\mqx\source\include\fio.h %OUTPUTDIR%\fio.h /Y
copy %MQXROOTDIR%\mqx\source\include\gen_rev.h %OUTPUTDIR%\gen_rev.h /Y
copy %MQXROOTDIR%\mqx\source\include\io.h %OUTPUTDIR%\io.h /Y
copy %MQXROOTDIR%\mqx\source\include\io_rev.h %OUTPUTDIR%\io_rev.h /Y
copy %MQXROOTDIR%\mqx\source\include\ioctl.h %OUTPUTDIR%\ioctl.h /Y
copy %MQXROOTDIR%\mqx\source\include\ipc.h %OUTPUTDIR%\ipc.h /Y
copy %MQXROOTDIR%\mqx\source\include\ipc_pcb.h %OUTPUTDIR%\ipc_pcb.h /Y
copy %MQXROOTDIR%\mqx\source\include\ipc_pcbv.h %OUTPUTDIR%\ipc_pcbv.h /Y
copy %MQXROOTDIR%\mqx\source\include\klog.h %OUTPUTDIR%\klog.h /Y
copy %MQXROOTDIR%\mqx\source\include\log.h %OUTPUTDIR%\log.h /Y
copy %MQXROOTDIR%\mqx\source\include\lwevent.h %OUTPUTDIR%\lwevent.h /Y
copy %MQXROOTDIR%\mqx\source\include\lwlog.h %OUTPUTDIR%\lwlog.h /Y
copy %MQXROOTDIR%\mqx\source\include\lwmem.h %OUTPUTDIR%\lwmem.h /Y
copy %MQXROOTDIR%\mqx\source\include\lwmsgq.h %OUTPUTDIR%\lwmsgq.h /Y
copy %MQXROOTDIR%\mqx\source\include\lwsem.h %OUTPUTDIR%\lwsem.h /Y
copy %MQXROOTDIR%\mqx\source\include\lwtimer.h %OUTPUTDIR%\lwtimer.h /Y
copy %MQXROOTDIR%\mqx\source\include\message.h %OUTPUTDIR%\message.h /Y
copy %MQXROOTDIR%\mqx\source\include\mmu.h %OUTPUTDIR%\mmu.h /Y
copy %MQXROOTDIR%\mqx\source\include\mqx.h %OUTPUTDIR%\mqx.h /Y
copy %MQXROOTDIR%\mqx\source\include\mqx_cnfg.h %OUTPUTDIR%\mqx_cnfg.h /Y
copy %MQXROOTDIR%\mqx\source\include\mqx_cpudef.h %OUTPUTDIR%\mqx_cpudef.h /Y
copy %MQXROOTDIR%\mqx\source\include\mqx_inc.h %OUTPUTDIR%\mqx_inc.h /Y
copy %MQXROOTDIR%\mqx\source\include\mqx_ioc.h %OUTPUTDIR%\mqx_ioc.h /Y
copy %MQXROOTDIR%\mqx\source\include\mqx_macros.h %OUTPUTDIR%\mqx_macros.h /Y
copy %MQXROOTDIR%\mqx\source\include\mqx_str.h %OUTPUTDIR%\mqx_str.h /Y
copy %MQXROOTDIR%\mqx\source\include\mutex.h %OUTPUTDIR%\mutex.h /Y
copy %MQXROOTDIR%\mqx\source\include\name.h %OUTPUTDIR%\name.h /Y
copy %MQXROOTDIR%\mqx\source\include\partition.h %OUTPUTDIR%\partition.h /Y
copy %MQXROOTDIR%\mqx\source\include\pcb.h %OUTPUTDIR%\pcb.h /Y
copy %MQXROOTDIR%\mqx\source\include\posix.h %OUTPUTDIR%\posix.h /Y
copy %MQXROOTDIR%\mqx\source\include\queue.h %OUTPUTDIR%\queue.h /Y
copy %MQXROOTDIR%\mqx\source\include\sem.h %OUTPUTDIR%\sem.h /Y
copy %MQXROOTDIR%\mqx\source\include\timer.h %OUTPUTDIR%\timer.h /Y
copy %MQXROOTDIR%\mqx\source\include\watchdog.h %OUTPUTDIR%\watchdog.h /Y
copy %MQXROOTDIR%\mqx\source\psp\cortex_m\cortex.h %OUTPUTDIR%\cortex.h /Y
copy %MQXROOTDIR%\mqx\source\psp\cortex_m\cpu\kinetis_fcan.h %OUTPUTDIR%\kinetis_fcan.h /Y
copy %MQXROOTDIR%\mqx\source\psp\cortex_m\cpu\MK60F15.h %OUTPUTDIR%\MK60F15.h /Y
copy %MQXROOTDIR%\mqx\source\psp\cortex_m\kinetis.h %OUTPUTDIR%\kinetis.h /Y
copy %MQXROOTDIR%\mqx\source\psp\cortex_m\kinetis_mpu.h %OUTPUTDIR%\kinetis_mpu.h /Y
copy %MQXROOTDIR%\mqx\source\psp\cortex_m\nvic.h %OUTPUTDIR%\nvic.h /Y
copy %MQXROOTDIR%\mqx\source\psp\cortex_m\psp.h %OUTPUTDIR%\psp.h /Y
copy %MQXROOTDIR%\mqx\source\psp\cortex_m\psp_abi.h %OUTPUTDIR%\psp_abi.h /Y
copy %MQXROOTDIR%\mqx\source\psp\cortex_m\psp_comp.h %OUTPUTDIR%\psp_comp.h /Y
copy %MQXROOTDIR%\mqx\source\psp\cortex_m\psp_cpu.h %OUTPUTDIR%\psp_cpu.h /Y
copy %MQXROOTDIR%\mqx\source\psp\cortex_m\psp_cpudef.h %OUTPUTDIR%\psp_cpudef.h /Y
copy %MQXROOTDIR%\mqx\source\psp\cortex_m\psp_math.h %OUTPUTDIR%\psp_math.h /Y
copy %MQXROOTDIR%\mqx\source\psp\cortex_m\psp_rev.h %OUTPUTDIR%\psp_rev.h /Y
copy %MQXROOTDIR%\mqx\source\psp\cortex_m\psp_supp.h %OUTPUTDIR%\psp_supp.h /Y
copy %MQXROOTDIR%\mqx\source\psp\cortex_m\psp_time.h %OUTPUTDIR%\psp_time.h /Y
copy %MQXROOTDIR%\mqx\source\psp\cortex_m\psptypes.h %OUTPUTDIR%\psptypes.h /Y
copy %MQXROOTDIR%\mqx\source\tad\tad.h %OUTPUTDIR%\tad.h /Y


goto tool_%TOOL%

rem cw10 files
:tool_cw10
copy %MQXROOTDIR%\mqx\source\psp\cortex_m\compiler\cw\asm_mac.h %OUTPUTDIR%\asm_mac.h /Y
copy %MQXROOTDIR%\mqx\source\psp\cortex_m\compiler\cw\comp.h %OUTPUTDIR%\comp.h /Y
goto copy_end

rem iar files
:tool_iar
copy %MQXROOTDIR%\mqx\source\psp\cortex_m\compiler\iar\asm_mac.h %OUTPUTDIR%\asm_mac.h /Y
copy %MQXROOTDIR%\mqx\source\psp\cortex_m\compiler\iar\comp.h %OUTPUTDIR%\comp.h /Y
goto copy_end

rem cw10gcc files
:tool_cw10gcc
copy %MQXROOTDIR%\mqx\source\psp\cortex_m\compiler\gcc_cw\asm_mac.h %OUTPUTDIR%\asm_mac.h /Y
copy %MQXROOTDIR%\mqx\source\psp\cortex_m\compiler\gcc_cw\comp.h %OUTPUTDIR%\comp.h /Y
goto copy_end

rem uv4 files
:tool_uv4
copy %MQXROOTDIR%\mqx\source\psp\cortex_m\compiler\rv\asm_mac.h %OUTPUTDIR%\asm_mac.h /Y
copy %MQXROOTDIR%\mqx\source\psp\cortex_m\compiler\rv\comp.h %OUTPUTDIR%\comp.h /Y
goto copy_end

:copy_end

