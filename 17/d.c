#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
	pid_t x = fork();
	if (x == 0) {
		int fd = open("./c.c", O_RDONLY, 0);
		if (fd == -1) {
			perror("can not open file");
			exit(-1);
		}
		dup2(fd, 0); // 0 file descriptor reads from fd
		close(fd);
		execlp("wc", "wc", "-l", NULL);
	}
	wait(NULL);
}