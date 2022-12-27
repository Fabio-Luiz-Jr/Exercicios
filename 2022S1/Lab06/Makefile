CFLAGS = -std=c99 -Wall -Werror -Werror=vla -g

.PHONY: all clean

all: balloc

balloc: balloc.c balloc.h
	gcc $(CFLAGS) balloc.c -o balloc $(LDFLAGS)

clean:
	rm -f balloc