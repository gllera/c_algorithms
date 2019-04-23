CC=gcc
DEBUG?= -g -ggdb
CFLAGS?= -O2 -Wall -W -std=c99
LDFLAGS= -lm

all: dir suffix-tree-tester

dir:
	mkdir -p build

%.o: %.c
	$(CC) -o build/$@ $< -c $(CFLAGS) $(DEBUG)

suffix-tree-tester: suffix-tree-tester.o suffix-tree.o
	$(CC) -o build/$@ build/suffix-tree-tester.o build/suffix-tree.o $(LDFLAGS) $(DEBUG)