#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

ssize_t my_read(int fin, char* buf, size_t size) {
	ssize_t res;
	asm volatile (
		"syscall\n"
		: "=a" (res)
		: "a" (SYS_read)
		, "D" (fin)
		, "S" (buf)
		, "d" (size)
	);
	return res;
}

int main() {
	int fin = open("in.txt", O_RDONLY);
	char buf[5001];

	ssize_t rd = my_read(fin, buf, 5000);
	while (rd > 0) {
		buf[rd] = '\0';
		printf("SUCCESS %ld\n", rd);
		rd = my_read(fin, buf, 5000);
	}
	printf("FINISH\n");
	close(fin);
}