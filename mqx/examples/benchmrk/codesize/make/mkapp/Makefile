# root directory
override MQX_ROOTDIR = $(abspath ../../../../../..)

# libraries are taken from an alternate folder
override LIBRARY_ROOTDIR = $(MQX_ROOTDIR)/mqx/examples/benchmrk/codesize/output/lib/$(BOARD).$(MAPFMT)/$(CODESIZE_CFG)

# application is built to an alternate folder
override APPLICATION_DIR = $(MQX_ROOTDIR)/mqx/examples/benchmrk/codesize/output/app/$(BOARD).$(MAPFMT)/$(CODESIZE_CFG)_$(CODESIZE_TARGET)

# the first include search path for our own user_config.h
INCLUDE += $(MQX_ROOTDIR)/mqx/examples/benchmrk/codesize/config/$(BOARD)/$(CODESIZE_CFG)

# next our own application search path
INCLUDE += $(MQX_ROOTDIR)/mqx/examples/benchmrk/codesize

# also add the path for internal private headers - this is required by codesize application
INCLUDE += $(MQX_ROOTDIR)/mqx/source/include
INCLUDE += $(MQX_ROOTDIR)/mqx/source/psp/$(PSP_DIR)

# default configuration for codesize benchmark
CONFIG = release

# identify build (MAX, TYPICAL, SMALL, TINIEST)
CC_DEFINE += -DCSCFG_$(CODESIZE_TARGET)=1 

# master makefile
-include $(MQX_ROOTDIR)/mqx/examples/benchmrk/codesize/make/Makefile
