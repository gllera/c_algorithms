SUBDIRS := $(wildcard ./*/.)
SUBDIRS := $(patsubst %/.,%,$(SUBDIRS))

all: build($(SUBDIRS))
clean: clean($(SUBDIRS))

build(%):
	@$(MAKE) -C $%
clean(%):
	@$(MAKE) -C $% clean