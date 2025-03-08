#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

volatile sig_atomic_t a = 0;

void handler(int signo) {
	a++;
}

int main() {
	sigset_t signals, signals2;
	sigemptyset(&signals);
	sigaddset(&signals, SIGINT);
	sigprocmask(SIG_BLOCK, &signals, NULL);

	struct sigaction sa;
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = handler;

	sigaction(SIGINT, &sa, NULL);
	while (1) {
		sigsuspend(&signals2);
		printf("%d\n", a);
	}
}

