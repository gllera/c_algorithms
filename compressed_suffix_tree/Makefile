CC=gcc

CFLAGS   = -Os -g -fno-common
CFLAGS  += -W -Wall
CFLAGS  += -D_FILE_OFFSET_BITS=64
CFLAGSW += -Wbad-function-cast -Wcast-align -Wcast-qual -Wchar-subscripts -Wmissing-prototypes -Wnested-externs -Wpointer-arith -Wredundant-decls -Wshadow -Wstrict-prototypes -Wwrite-strings -Wswitch-enum

LDFLAGS = -lm

rax-test: rax-test.o rax.o
	$(CC) -o $@ $^ $(LDFLAGS)

rax.o: rax.c
	$(CC) $(CFLAGS) $(CFLAGSW) -o $@ -c $<

rax-test.o: rax-test.c
	$(CC) $(CFLAGS) -o $@ -c $<

