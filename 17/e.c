#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
	int fd[2];
	pipe(fd);
	if (!fork()) {
		/*
		shared_ptr 1;
		shared_ptr fd;

		dup2(fd, 1) - 1 = fd;
		close(fd) - 1 remains
		*/
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]); // dupplicated fd remains unclosed
		execlp("ls", "ls", "./", NULL);
		// We never go here unless execpl can not run
		exit(-1);
	}
	close(fd[1]);
	if (!fork()) {
		dup2(fd[0], 0);
		close(fd[0]);
		execlp("wc", "wc", "-l", NULL);
		exit(-1);
	}
	close(fd[0]);
	wait(NULL);
	wait(NULL);
}