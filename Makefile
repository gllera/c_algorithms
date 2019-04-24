CC=gcc
#DEBUG= -g -ggdb
CFLAGS= -O3 -Wall -W -std=c99
LDFLAGS= -lm

all: dir build/simple-suffix-tester

dir:
	@mkdir -p build

build/%.o: %.c
	$(CC) -o $@ $< -c $(CFLAGS) $(DEBUG)

build/simple-suffix-tester: build/simple-suffix.o build/simple-suffix-tester.o
	$(CC) -o $@ $^ $(LDFLAGS) $(DEBUG)
