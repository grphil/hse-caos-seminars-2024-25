#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

volatile sig_atomic_t counter = 0;

void handler(int signo) {
	if (++counter < 4) {
		printf("recieved %d signals\n", counter);
	} else {
		printf("Finishing after signal %d\n", signo);
		exit(0);
	}
}

int main() {
	struct sigaction sa;
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = handler;

	sigaction(SIGINT, &sa, NULL);
	while (1) {
	}
}