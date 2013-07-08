
#----------------------------------------------------------
# build all available libraries
#----------------------------------------------------------
help:
	@echo "use 'build' or 'clean' target"


#----------------------------------------------------------
# build all available libraries
#----------------------------------------------------------
build:
	$(MAKE) -C usbd build CONFIG=$(CONFIG) TOOL=$(TOOL)
	$(MAKE) -C rtcs build CONFIG=$(CONFIG) TOOL=$(TOOL)
	$(MAKE) -C bsp build CONFIG=$(CONFIG) TOOL=$(TOOL)
	$(MAKE) -C shell build CONFIG=$(CONFIG) TOOL=$(TOOL)
	$(MAKE) -C psp build CONFIG=$(CONFIG) TOOL=$(TOOL)
	$(MAKE) -C usbh build CONFIG=$(CONFIG) TOOL=$(TOOL)
	$(MAKE) -C mfs build CONFIG=$(CONFIG) TOOL=$(TOOL)


#----------------------------------------------------------
# clean all available libraries
#----------------------------------------------------------
clean:
	$(MAKE) -C usbd clean CONFIG=$(CONFIG) TOOL=$(TOOL)
	$(MAKE) -C rtcs clean CONFIG=$(CONFIG) TOOL=$(TOOL)
	$(MAKE) -C bsp clean CONFIG=$(CONFIG) TOOL=$(TOOL)
	$(MAKE) -C shell clean CONFIG=$(CONFIG) TOOL=$(TOOL)
	$(MAKE) -C psp clean CONFIG=$(CONFIG) TOOL=$(TOOL)
	$(MAKE) -C usbh clean CONFIG=$(CONFIG) TOOL=$(TOOL)
	$(MAKE) -C mfs clean CONFIG=$(CONFIG) TOOL=$(TOOL)


