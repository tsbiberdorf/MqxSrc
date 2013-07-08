# root directory
override MQX_ROOTDIR = $(abspath ../../../../../..)

# libraries are built to an alternate folder
override LIBRARY_ROOTDIR = $(MQX_ROOTDIR)/mqx/examples/benchmrk/codesize/output/lib/$(BOARD).$(MAPFMT)/$(CODESIZE_CFG)

# the first include search path for our own user_config.h
INCLUDE += $(MQX_ROOTDIR)/mqx/examples/benchmrk/codesize/config/$(BOARD)/$(CODESIZE_CFG)

# default configuration for codesize benchmark
CONFIG = release

# master makefile
-include $(MQX_ROOTDIR)/build/$(BOARD)/make/psp/Makefile
