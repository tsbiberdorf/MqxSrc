@echo off

rem convert path to backslash format
set MQXROOTDIR=%1
set MQXROOTDIR=%MQXROOTDIR:/=\%
set OUTPUTDIR=%2
set OUTPUTDIR=%OUTPUTDIR:/=\%
set TOOL=%3


rem copy common files
IF NOT EXIST %OUTPUTDIR% mkdir %OUTPUTDIR%
copy %MQXROOTDIR%\shell\source\include\sh_enet.h %OUTPUTDIR%\sh_enet.h /Y
copy %MQXROOTDIR%\shell\source\include\sh_mfs.h %OUTPUTDIR%\sh_mfs.h /Y
copy %MQXROOTDIR%\shell\source\include\sh_rtcs.h %OUTPUTDIR%\sh_rtcs.h /Y
copy %MQXROOTDIR%\shell\source\include\shell.h %OUTPUTDIR%\shell.h /Y


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

