CC       ?= gcc
LDFLAGS  ?= -lm

ifndef CFLAGS
CFLAGS   += -std=c99 -g -O0
CFLAGS   += -W -Wall -Wbad-function-cast -Wcast-align -Wcast-qual -Wchar-subscripts -Wmissing-prototypes -Wnested-externs -Wpointer-arith -Wredundant-decls -Wshadow -Wstrict-prototypes -Wwrite-strings -Wswitch-enum -fno-common
endif

BUILDDIR ?= bin
PROJECT  ?= $(notdir $(CURDIR))
SOURCES  ?= $(wildcard *.c)
DEPS     ?= $(patsubst %.c,$(BUILDDIR)/%.o,$(SOURCES))

.INTERMEDIATE: $(DEPS)

run: $(BUILDDIR) $(BUILDDIR)/$(PROJECT)

clean:
	rm -rf $(BUILDDIR)

$(BUILDDIR):
	@mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.o: %.c
	$(CC) -o $@ $< -c $(CFLAGS)

$(BUILDDIR)/%: $(DEPS)
	$(CC) -o $@ $^ $(LDFLAGS)
