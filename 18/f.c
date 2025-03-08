#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/signalfd.h>
#include <sys/wait.h>

void child() {
	sigset_t ss;
	sigemptyset(&ss);
	sigaddset(&ss, SIGUSR1);

	int sfd = signalfd(-1, &ss, 0);

	for (int i = 0; i < 5; i++) {
		struct signalfd_siginfo si;
		read(sfd, &si, sizeof(si));
		printf("%d\n", i + 1);
		fflush(stdout);
	}
}

int main() {
	int pid = fork();
	if (pid == 0) {
		child();
		return 0;
	}

	for (int i = 0; i < 5; i++) {
		kill(pid, SIGUSR1);
	}

	wait(NULL);
}