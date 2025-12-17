CC=gcc

all: from to copy

from: from.c
	$(CC) -o from from.c

to: to.c
	$(CC) -o to to.c

copy: copy.c
	$(CC) -o copy copy.c

clean:
	rm -f from to copy *.o
