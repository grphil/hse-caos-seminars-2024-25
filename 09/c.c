#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

enum {
	BUF_SIZE = 4096,
};

typedef struct {
	int fd;
	char buf[BUF_SIZE];
	size_t size;
	size_t pos;
} F;

F* ropen(char* path) {
	int fd = open(path, O_RDONLY);
	if (fd == -1) {
		return NULL;
	}
	F* f = calloc(1, sizeof(F));
	f->fd = fd;
	return f;
}

void rclose(F* f) {
	close(f->fd);
	free(f);
}

bool readBuf(F* f) {
	ssize_t n = read(f->fd, f->buf, BUF_SIZE);
	if (n <= 0) {
		return false;
	}
	f->size = n;
	f->pos = 0;
	return true;
}

char rget(F* f) {
	if (f->size == f->pos) {
		if (!readBuf(f)) {
			return '\0';
		}
	}
	return f->buf[f->pos++];
}

bool seek(F* f, size_t size) {
	off_t n = lseek(f->fd, size, SEEK_SET);
	if (n == -1) {
		return false;
	}
	return readBuf(f);
}

int main() {
	F* f = ropen("in.txt");
	char c;
	while ((c = rget(f)) != '\0') {
		fprintf(stderr, "%c", c);
	}
	printf("\n");
	seek(f, 2);
	while ((c = rget(f)) != '\0') {
		fprintf(stderr, "%c", c);
	}
	rclose(f);


}