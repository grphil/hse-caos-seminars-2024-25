#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>

jmp_buf metka;

void f(int a) {
	printf("A %d\n", a);
	longjmp(metka, a + 1);
	// goto metka;
}

int main() {
	int c = 0;
// metka:
	int a = setjmp(metka);
	if (a < 5) {
		c++;
		printf("C %d\n", c);
		f(a);
	}
}
