/*
 * to.c - Redirect stdin to file
 *
 * Reads from standard input and writes to specified file.
 * Creates file if it doesn't exist, truncates if it does.
 * Similar to shell redirection: cat > file.txt
 *
 * Usage: 
 *   echo "text" | ./to output.txt
 *   ./to output.txt < input.txt
 *   cat large.txt | ./to backup.txt
 *
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define B 1024

int main(int argc, char *argv[]) {

	if (argc < 2) {
		printf("Usage: %s <filename>\n", argv[0]);
		return 1;
	}

	int r, fd;
	char buf[B];

	fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0666); //0666 -> rw-rw-rw

	if (fd < 0) {
		perror("File open");
		return 1;
	}

	while (( r = read(STDIN_FILENO, buf, sizeof(buf))) > 0) {   // 0 = STDIN_FILENO
		write(fd, buf, r);
	}

	close(fd);
	return 0;
}
