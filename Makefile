CC=gcc

CFLAGS  = -Os -g -fno-common 
CFLAGS += -W -Wall -Wbad-function-cast -Wcast-align -Wcast-qual -Wchar-subscripts -Wmissing-prototypes -Wnested-externs -Wpointer-arith -Wredundant-decls -Wshadow -Wstrict-prototypes -Wwrite-strings -Wswitch-enum
CFLAGS += -D_FILE_OFFSET_BITS=64 

rax.o: rax.c
	$(CC) $(CFLAGS) -o $@ -c $<
