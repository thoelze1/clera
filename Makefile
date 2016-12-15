
CC = gcc
CFLAGS = -lncurses

all: clera.c clera.h
	$(CC) $(CFLAGS) clera.c -o clera

clean:
	rm -f clera
