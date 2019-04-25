CC=gcc
DEBUG= -g -ggdb
CFLAGS= -O0 -Wall -W -std=c99
LDFLAGS= -lm

all: dir build/suffix_tree_tester

clean:
	@rm -rf build

dir:
	@mkdir -p build

build/%.o: %.c
	$(CC) -o $@ $< -c $(CFLAGS) $(DEBUG)

build/suffix_tree_tester: build/suffix_tree.o build/suffix_tree_tester.o
	$(CC) -o $@ $^ $(LDFLAGS) $(DEBUG)
