CC=gcc
DEBUG= -g -ggdb
CFLAGS= -Og -Wall -W -std=c99
LDFLAGS= -lm

all: dir build/suffix-matcher-tester

dir:
	@mkdir -p build

build/%.o: %.c
	$(CC) -o $@ $< -c $(CFLAGS) $(DEBUG)

build/suffix-matcher-tester: build/suffix-matcher.o build/suffix-matcher-tester.o
	$(CC) -o $@ $^ $(LDFLAGS) $(DEBUG)
