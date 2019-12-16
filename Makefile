##########
DEBUG ?= 0
##########

# Use 'make V=1' to see the full commands
ifdef V
  quiet=
else
  quiet=quiet_
endif

# Use 'make -s' to suppress echoing of the commands
ifneq ($(findstring s,$(filter-out --%,$(MAKEFLAGS))),)
  quiet=silent_
endif

CC		:= $(CROSS_COMPILE)gcc
CXX		:= $(CROSS_COMPILE)g++
AR		:= $(CROSS_COMPILE)ar
LD		:= $(CROSS_COMPILE)ld
CFLAGS		:= -Werror -Wmissing-prototypes -MMD -O3 -I./include
CXXFLAGS	:= -Werror -Wmissing-prototypes -MMD -O3 -I./include
LDFLAGS		:= -lpthread -lQtCore -lQtGui
ifeq ($(DEBUG),1)
  CXXFLAGS += -DDEBUG
  CFLAGS += -DDEBUG
endif
CXXFLAGS += -D_REENTRANT
CFLAGS += -D_REENTRANT

PHONY := all
all: game

quiet_cmd_cxx = CXX     $@
      cmd_cxx = $(CXX) -o $@ $^ $(LDFLAGS)
game: qt/built-in.o
	$(call cmd,cxx)

drivers/%:
	@$(MAKE) -f drivers/Makefile

export CC AR LD CFLAGS LDFLAGS quiet
include scripts/Makefile.build

PHONY += clean
clean: rm-files := core **/*.d **/*.o **/*.ko game
clean:
	$(call cmd,rmfiles)

.PHONY: $(PHONY)
