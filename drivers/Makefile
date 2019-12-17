modtree ?= .

mods := bus_spartan6/
mods += class_fpga/

mods += driver_buzzer/

ifdef obj
  include $(obj)/Makefile
endif

$(mods:/=):
	$(MAKE) -C $(KDIR) M=$(modtree) obj=$@ modules

clean: _clean_$(mods)

_clean_%:
	$(MAKE) -C $(KDIR) M=$(modtree)/$* clean

.PHONY: clean $(addprefix _clean_, $(mods))
