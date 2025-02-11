#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int fd1[2];
int fd2[2];

void cl() {
	for (int i = 0; i < 2; i++) {
		close(fd1[i]);
		close(fd2[i]);
	}
}

int main() {
	pipe(fd1);
	pipe(fd2);
	// child 1 < fd1[0] > fd2[1]
	// child 2 < fd2[0] > fd1[1]

	if (!fork()) {
		dup2(fd1[0], 0);
		dup2(fd2[1], 1);
		cl();
		execlp("./bs", "bs", NULL);
		exit(-1);
	}
	if (!fork()) {
		dup2(fd2[0], 0);
		dup2(fd1[1], 1);
		cl();
		execlp("./binsearch", "binsearch", NULL);
		exit(-1);
	}
	cl();
	wait(NULL);
	wait(NULL);
}