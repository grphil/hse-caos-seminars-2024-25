#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	int a = 1;
	pid_t x = fork();
	if (x == 0) {
		a = 2;
		printf("child\n");
		exit(0);
	} else {
		wait(NULL);
		printf("parent, child %d\n", x);
		printf("%d\n", a);
	}
}