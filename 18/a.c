#include <sys/mman.h>

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
	int fd = open("in.txt", O_RDWR, 0777);

	off_t sz = lseek(fd, 0, SEEK_END);

	char* ptr = mmap(0, sz, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	char s[5];
	strncpy(s, ptr, 4);
	s[4] = '\0';
	printf("%s\n", s);
	for (int i = 0; i < 5; i++) {
		ptr[i] = 'y';
	}
	munmap(ptr, sz);
}