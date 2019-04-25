CC=gcc
DEBUG= -g -ggdb
CFLAGS= -O0 -Wall -W -std=c99
LDFLAGS= -lm

all: dir build/suffix-tree-tester

dir:
	@mkdir -p build

build/%.o: %.c
	$(CC) -o $@ $< -c $(CFLAGS) $(DEBUG)

build/suffix-tree-tester: build/suffix-tree.o build/suffix-tree-tester.o
	$(CC) -o $@ $^ $(LDFLAGS) $(DEBUG)
