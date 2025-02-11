#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	int a = 1;
	pid_t x = fork();
	if (x == 0) {
		execlp("ls", "ls", "-lh", "./", NULL);
		exit(-1);
	}
	wait(NULL);
}