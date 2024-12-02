#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	int fin = open("in.txt", O_RDONLY);
	char buf[5001];

	ssize_t rd = read(fin, buf, 5000);
	while (rd > 0) {
		buf[rd] = '\0';
		printf("SUCCESS %ld\n", rd);
		rd = read(fin, buf, 5000);
	}
	printf("FINISH\n");
	close(fin);
}