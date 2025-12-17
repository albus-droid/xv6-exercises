/*
 * from.c - Display file contents to stdout
 *
 * Simple implementation of cat utility using UNIX system calls.
 * Reads a file in chunks and writes to standard output.
 *
 * Usage: ./from <filename>
 */ 

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define B 1024
int main(int argc, char *argv[]) {

	if (argc < 2) {
		printf("Usage %s: <filename>\n", argv[0]);
		return 1;
	}

	int r, fd;
	char buf[B];

	fd = open(argv[1], O_RDONLY);

	if (fd < 0) {
		perror("File open");
		return 1;
	}
	
	while ((r = read(fd, buf, sizeof(buf))) > 0) {
		write(STDOUT_FILENO, buf, r);  // STDOUT_FILENO = 1
	}

	close(fd);
	return 0;
}
