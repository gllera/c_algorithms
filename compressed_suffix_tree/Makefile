CC=gcc
DEBUG= -g -ggdb
CFLAGS= -O0 -Wall -W -std=c99
LDFLAGS= -lm

all: dir build/rax_tester

clean:
	@rm -rf build

dir:
	@mkdir -p build

build/%.o: %.c
	$(CC) -o $@ $< -c $(CFLAGS) $(DEBUG)

build/rax_tester: build/rax.o build/rax_tester.o
	$(CC) -o $@ $^ $(LDFLAGS) $(DEBUG)
