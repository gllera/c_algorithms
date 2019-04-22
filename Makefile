CC=gcc

CFLAGS  = -Os -g -fno-common 
CFLAGS += -W -Wall -Wbad-function-cast -Wcast-align -Wcast-qual -Wchar-subscripts -Wmissing-prototypes -Wnested-externs -Wpointer-arith -Wredundant-decls -Wshadow -Wstrict-prototypes -Wwrite-strings -Wswitch-enum
CFLAGS += -D_FILE_OFFSET_BITS=64 

LDFLAGS = -lm

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

rax-test: rax-test.o rax.o
	$(CC) -o $@ $^ $(LDFLAGS)
