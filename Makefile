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

include scripts/subarch.include
ARCH 		?= arm
ifneq ($(SUBARCH),arm)
  CROSS_COMPILE	?= arm-linux-gnueabihf-
endif

CC		:= $(CROSS_COMPILE)gcc
CXX		:= $(CROSS_COMPILE)g++
AR		:= $(CROSS_COMPILE)ar
LD		:= $(CROSS_COMPILE)ld
CFLAGS		:= -Werror -Wmissing-prototypes -MMD -O3 -I./include
CXXFLAGS	:= -Werror -MMD -O3 -I./include
LDFLAGS		:= -lpthread
ifeq ($(DEBUG),1)
  CXXFLAGS += -DDEBUG
  CFLAGS += -DDEBUG
endif
CXXFLAGS += -D_REENTRANT
CFLAGS += -D_REENTRANT

# Qt5 options
LDFLAGS		+= -lQt5Widgets -lQt5Gui -lQt5Core -lGLESv2
CXXFLAGS	+= -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -isystem /usr/include/arm-linux-gnueabihf/qt5 -isystem /usr/include/arm-linux-gnueabihf/qt5/QtWidgets -isystem /usr/include/arm-linux-gnueabihf/qt5/QtGui -isystem /usr/include/arm-linux-gnueabihf/qt5/QtCore -I/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/linux-g++ -I./qt

PHONY := all
all: game

quiet_cmd_cxx = CXX     $@
      cmd_cxx = $(CXX) -o $@ $^ $(LDFLAGS)
game: qt/built-in.o
	$(call cmd,cxx)

export CC CXX AR LD CFLAGS CXXFLAGS LDFLAGS quiet
include scripts/Makefile.build

qt/built-in.o: FORCE
	@$(MAKE) -s $(build)=$(obj)/qt

# Make drivers
export KDIR ?= /work/achro-em/kernel
export CROSS_COMPILE

PHONY += drivers $(wildcard drivers/*)
drivers:
	@$(MAKE) -f drivers/Makefile

drivers/%:
	@$(MAKE) -f drivers/Makefile modtree=drivers $*

PHONY += clean
clean: rm-files := core **/*.d **/*.o **/*.ko game
clean:
	$(call cmd,rmfiles)
	@$(MAKE) -f drivers/Makefile modtree=drivers clean

PHONY += FORCE
FORCE:

.PHONY: $(PHONY)
