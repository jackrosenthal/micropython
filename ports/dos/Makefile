include ../../py/mkenv.mk

CROSS = 0

# qstr definitions (must come before including py.mk)
QSTR_DEFS = qstrdefsport.h

# MicroPython feature configurations
MICROPY_ROM_TEXT_COMPRESSION ?= 1

# include py core make definitions
include $(TOP)/py/py.mk

export WATCOM ?= /opt/watcom
export INCLUDE ?= $(WATCOM)/h

export PATH := $(WATCOM)/binl64:$(PATH)
export CC = owcc
LD = $(WATCOM)/binl64/wlink
CFLAGS ?= -b=dos -march=i86 -std=c99 -I. -I$(TOP) -I$(BUILD)

SRC_C = \
	main.c \
	dos.c \
	shared/readline/readline.c \
	shared/runtime/pyexec.c \
	shared/runtime/stdout_helpers.c

SRC_QSTR += shared/readline/readline.c shared/runtime/pyexec.c

OBJ += $(PY_CORE_O) $(addprefix $(BUILD)/, $(SRC_C:.c=.o))

all: $(BUILD)/mp.exe

$(BUILD)/mp.exe: $(OBJ)
	$(ECHO) "LINK $@"
	$(Q)$(LD) system dos name $@ $(foreach obj,$^,file $(obj))

include $(TOP)/py/mkrules.mk
