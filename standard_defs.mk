CC       ?= gcc
CFLAGS   ?= -O0 -Wall -W -std=c99 -g -ggdb
LDFLAGS  ?= -lm

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
