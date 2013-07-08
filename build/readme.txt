The <MQX>/build folder has been newly introduced in MQX 4.0 and will be expanded
more in the upcoming versions. In version 4.0 this folder contains the makefiles
for command-line build of MQX libraries. In future versions, also the build 
projects for various IDEs will be moved to this folder. The ultimate goal is to
separate the MQX source code from the build projects for all MQX components. All
library build projects will be moved in this folder in MQX 4.1 version.

This folder contains makefiles in following structure: 

Note: The mass build projects for IDEs - IAR, UV4 Keil, CW10.3 are located in <mqx_install_dir>/config/<tool_name>. See FSL_MQX_getting_started.pdf for detailed desctiption. 


build
+---common
|   +---make        ... shared Makefiles with global settings, variables and paths
+---<board1>        ... board-specific folder
|   +---make        ... folder contains mass-build Makefile for all libraries
|       +---tools   ... tool-specific global settings, variables and paths
|       +---bsp     ... BSP Library Makefile
|       +---psp     ... PSP Library Makefile
|       +---mfs     ... MFS Library Makefile
|       +---rtcs    ... RTCS Library Makefile
|       +---shell   ... Shell Library Makefile
|       +---usbd    ... USB Device Library Makefile
|       +---usbh    ... USB Host Library Makefile
+---<board2>  
    +---make
        ...

*** MAKE usage ***
  - Navigate to the <mqx_install_dir>/build/<board>/make directory 
  - Run the following command to build MQX libraries using the GCC from CW10.3 toolchain
    C:\MinGW\bin\mingw32-make.exe build TOOL=gcc_cw CONFIG=debug 

Note: 
  - Please use the mingw32-make version 3.8.2 or higher. Download the latest version from http://sourceforge.net/projects/mingw/. 
  - Prior the build you should specify the path (TOOLCHAIN_ROOTDIR variable) to your build tools in the <mqx_install_dir>/build/common/make/global.mak
