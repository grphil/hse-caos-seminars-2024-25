#include <sys/time.h>
#include <stdio.h>
#include <signal.h>
#include <stdbool.h>

void handler(int s) {
	printf("Timer\n");
}

int main() {
	struct sigaction sa;
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = handler;
	sigaction(SIGALRM, &sa, NULL);

	struct itimerval itv;
	itv.it_value.tv_sec = 1;
	itv.it_value.tv_usec = 0;
	itv.it_interval.tv_sec = 0;
	itv.it_interval.tv_usec = 500000;

	setitimer(ITIMER_REAL, &itv, NULL);

	while (true);
}