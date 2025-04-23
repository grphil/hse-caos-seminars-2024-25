#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

int create_listener(char* service) {
	struct addrinfo hints = {
		.ai_family = AF_INET,
		.ai_socktype = SOCK_STREAM,
		.ai_flags = AI_PASSIVE,
	};
	struct addrinfo* result;

	int err = getaddrinfo(NULL, service, &hints, &result);
	if (err != 0) {
		exit(228);
	}

	int sock = -1;
	for (struct addrinfo* a = result; a != NULL; a = a->ai_next) {
		sock = socket(a->ai_family, a->ai_socktype, 0);
		if (sock < 0) {
			continue;
		}

		if (bind(sock, a->ai_addr, a->ai_addrlen) < 0) {
			close(sock);
			sock = -1;
			continue;
		}

		if (listen(sock, SOMAXCONN) < 0) {
			close(sock);
			sock = -1;
			continue;
		}
		break;
	}

	freeaddrinfo(result);
	return sock;
}

int main(int argc, char** argv) {
	int sock = create_listener(argv[1]);
	if (sock < 0) {
		return 228;
	}

	while (true) {
		struct sockaddr_in ss; // DO not write like this
		socklen_t sz = sizeof(ss);
		int afd = accept(sock, (void*)&ss, &sz);

		int pid = fork();
		if (pid == 0) {
			FILE* fin = fdopen(dup(afd), "r");
			FILE* fout = fdopen(afd, "w");

			for (int i = 0; i < 3; i++) {
				int x;
				fscanf(fin, "%d", &x);

				printf("recieved from %s:%d number %d, sending %d\n",
					inet_ntoa(ss.sin_addr), ntohs(ss.sin_port),
					x,
					x + 1
				);

				fprintf(fout, "%d\n", x + 1);
				fflush(fout);
			}

			fclose(fin);
			fclose(fout);
			exit(0);
		}
		close(afd);
	}
}