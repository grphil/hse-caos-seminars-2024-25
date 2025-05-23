#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int signo) {
	printf("Finishing after signal %d\n", signo);
	// exit(0);
}

int main() {

	struct sigaction sa;
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = handler;

	sigaction(SIGINT, &sa, NULL);
	while (1) {
		int x;
		scanf("%d", &x);
		printf("%d", x);
		scanf("%d", &x);
		printf("%d\n", x);
	}
}