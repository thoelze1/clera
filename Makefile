CC = gcc
CFLAGS = -lncurses

all: clera.c clera.h
	$(CC) clera.c -o clera $(CFLAGS)

clean:
	rm -f clera
