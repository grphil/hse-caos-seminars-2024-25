#include <stdio.h>
#include <stdint.h>

extern int pipe(size_t n, int a, ...);

int inc(int a) {
	printf("INC %d\n", a);
	return a + 1;
}

int dec(int a) {
	printf("DEC %d\n", a);
	return a - 1;
}

int mul2(int a) {
	printf("MUL2 %d\n", a);
	return a * 2;
}

int main() {
	int a = 3;
	int res = pipe(6, a, inc, dec, inc, dec, mul2, mul2);
	printf("%d\n", res);
}
