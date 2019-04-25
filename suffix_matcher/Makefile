CC=gcc
DEBUG= -g -ggdb
CFLAGS= -Og -Wall -W -std=c99
LDFLAGS= -lm

all: dir build/suffix_matcher_tester

dir:
	@mkdir -p build

build/%.o: %.c
	$(CC) -o $@ $< -c $(CFLAGS) $(DEBUG)

build/suffix_matcher_tester: build/suffix_matcher.o build/suffix_matcher_tester.o
	$(CC) -o $@ $^ $(LDFLAGS) $(DEBUG)
