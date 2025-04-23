#include <sys/types.h>

#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main() {
	char node[1000]; // url
	char service[1000]; // connection type

	scanf("%s%s", node, service);

	struct addrinfo hints = {
		.ai_family = AF_INET,
		.ai_socktype = SOCK_STREAM,
	};
	struct addrinfo* result;

	int err = getaddrinfo(node, service, &hints, &result);
	if (err != 0) {
		return 228;
	}
	for (struct addrinfo* a = result; a != NULL; a = a->ai_next) {
		// Works only for IPv4 because of .ai_family = AF_INET in hint
		struct sockaddr_in* ip4addr = (struct sockaddr_in*)a->ai_addr;
		printf("%s:%d\n", inet_ntoa(ip4addr->sin_addr), ntohs(ip4addr->sin_port));
	}
	freeaddrinfo(result);
}