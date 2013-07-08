@echo off
path %PATH%;C:\MinGW\bin

rem Take parameters
set BOARD=%1
set PSPDIR=%2
set TOOL=%3
set LOAD=%4
set MAPFMT=%5


:build_bsp
echo #########@@@ Building for %BOARD% with %TOOL%: BSP typical 
mingw32-make.exe -C mkbsp BOARD=%BOARD% TOOL=%TOOL% CODESIZE_CFG=typical MAPFMT=%MAPFMT% build 
echo #########@@@ Building for %BOARD% with %TOOL%: BSP maximum 
mingw32-make.exe -C mkbsp BOARD=%BOARD% TOOL=%TOOL% CODESIZE_CFG=maximum MAPFMT=%MAPFMT% build 
echo #########@@@ Building for %BOARD% with %TOOL%: BSP small 
mingw32-make.exe -C mkbsp BOARD=%BOARD% TOOL=%TOOL% CODESIZE_CFG=small   MAPFMT=%MAPFMT% build 

:build_psp
echo #########@@@ Building for %BOARD% with %TOOL%: PSP typical 
mingw32-make.exe -C mkpsp BOARD=%BOARD% TOOL=%TOOL% CODESIZE_CFG=typical MAPFMT=%MAPFMT% build 
echo #########@@@ Building for %BOARD% with %TOOL%: PSP maximum 
mingw32-make.exe -C mkpsp BOARD=%BOARD% TOOL=%TOOL% CODESIZE_CFG=maximum MAPFMT=%MAPFMT% build 
echo #########@@@ Building for %BOARD% with %TOOL%: PSP small 
mingw32-make.exe -C mkpsp BOARD=%BOARD% TOOL=%TOOL% CODESIZE_CFG=small   MAPFMT=%MAPFMT% build 

:build_app
echo #########@@@ Building for %BOARD% with %TOOL%: APP typical_MAX 
mingw32-make.exe -C mkapp BOARD=%BOARD% TOOL=%TOOL% LOAD=%LOAD% PSP_DIR=%PSPDIR% CODESIZE_CFG=typical CODESIZE_TARGET=MAX MAPFMT=%MAPFMT% build 
echo #########@@@ Building for %BOARD% with %TOOL%: APP typical_SMALL 
mingw32-make.exe -C mkapp BOARD=%BOARD% TOOL=%TOOL% LOAD=%LOAD% PSP_DIR=%PSPDIR% CODESIZE_CFG=typical CODESIZE_TARGET=SMALL MAPFMT=%MAPFMT% build 
echo #########@@@ Building for %BOARD% with %TOOL%: APP typical_TYPICAL
mingw32-make.exe -C mkapp BOARD=%BOARD% TOOL=%TOOL% LOAD=%LOAD% PSP_DIR=%PSPDIR% CODESIZE_CFG=typical CODESIZE_TARGET=TYPICAL MAPFMT=%MAPFMT% build 
rem echo #########@@@ Building for %BOARD% with %TOOL%: APP typical_TINIEST 
rem mingw32-make.exe -C mkapp BOARD=%BOARD% TOOL=%TOOL% LOAD=%LOAD% PSP_DIR=%PSPDIR% CODESIZE_CFG=typical CODESIZE_TARGET=TINIEST MAPFMT=%MAPFMT% build 

echo #########@@@ Building for %BOARD% with %TOOL%: APP maximum_MAX 
mingw32-make.exe -C mkapp BOARD=%BOARD% TOOL=%TOOL% LOAD=%LOAD% PSP_DIR=%PSPDIR% CODESIZE_CFG=maximum CODESIZE_TARGET=MAX MAPFMT=%MAPFMT% build 
echo #########@@@ Building for %BOARD% with %TOOL%: APP maximum_SMALL 
mingw32-make.exe -C mkapp BOARD=%BOARD% TOOL=%TOOL% LOAD=%LOAD% PSP_DIR=%PSPDIR% CODESIZE_CFG=maximum CODESIZE_TARGET=SMALL MAPFMT=%MAPFMT% build 
echo #########@@@ Building for %BOARD% with %TOOL%: APP maximum_TYPICAL
mingw32-make.exe -C mkapp BOARD=%BOARD% TOOL=%TOOL% LOAD=%LOAD% PSP_DIR=%PSPDIR% CODESIZE_CFG=maximum CODESIZE_TARGET=TYPICAL MAPFMT=%MAPFMT% build 
rem echo #########@@@ Building for %BOARD% with %TOOL%: APP maximum_TINIEST 
rem mingw32-make.exe -C mkapp BOARD=%BOARD% TOOL=%TOOL% LOAD=%LOAD% PSP_DIR=%PSPDIR% CODESIZE_CFG=maximum CODESIZE_TARGET=TINIEST MAPFMT=%MAPFMT% build 

echo #########@@@ Building for %BOARD% with %TOOL%: APP small_MAX 
mingw32-make.exe -C mkapp BOARD=%BOARD% TOOL=%TOOL% LOAD=%LOAD% PSP_DIR=%PSPDIR% CODESIZE_CFG=small CODESIZE_TARGET=MAX MAPFMT=%MAPFMT% build 
echo #########@@@ Building for %BOARD% with %TOOL%: APP small_SMALL 
mingw32-make.exe -C mkapp BOARD=%BOARD% TOOL=%TOOL% LOAD=%LOAD% PSP_DIR=%PSPDIR% CODESIZE_CFG=small CODESIZE_TARGET=SMALL MAPFMT=%MAPFMT% build 
echo #########@@@ Building for %BOARD% with %TOOL%: APP small_TYPICAL
mingw32-make.exe -C mkapp BOARD=%BOARD% TOOL=%TOOL% LOAD=%LOAD% PSP_DIR=%PSPDIR% CODESIZE_CFG=small CODESIZE_TARGET=TYPICAL MAPFMT=%MAPFMT% build 
echo #########@@@ Building for %BOARD% with %TOOL%: APP small_TINIEST 
mingw32-make.exe -C mkapp BOARD=%BOARD% TOOL=%TOOL% LOAD=%LOAD% PSP_DIR=%PSPDIR% CODESIZE_CFG=small CODESIZE_TARGET=TINIEST MAPFMT=%MAPFMT% build 

:done
