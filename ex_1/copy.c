/*
 * copy.c - Copy file using pipe and child processes
 *
 * Demonstrates inter-process communication using pipes.
 * Child process reads source file (via ./from), parent process
 * writes to destination file (via ./to). Data flows through pipe.
 *
 * Flow: ./from (reads file) -> pipe -> ./to (writes file)
 *
 * Usage: ./copy source.txt dest.txt
 */

#include <stdio.h>
#include <unistd.h>

#define B 1024

int main(int argc, char *argv[]) {

	if (argc < 3) {
		printf("Usage: %s <source> <destination>\n", argv[0]);
		return 1;
	}

	int p[2], pid; // p[0] -> pipe read end, p[1] -> pipe write end  

	if (pipe(p) < 0) {
		perror("pipe");
		return 1;
	}

	pid = fork();

	if (pid > 0) {
		dup2(p[1], STDOUT_FILENO); // stdout to pipe
		close(p[0]);
		close(p[1]);
		execlp("./from", "from", argv[1], NULL);
		perror("from exec");
		return 1;
	} else {
		dup2(p[0], STDIN_FILENO); // stdin to pipe
		close(p[1]);
		close(p[0]);
		execlp("./to", "to", argv[2], NULL);
		perror("to exec");
		return 1;
	}

	return 0;
}
