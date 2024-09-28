#include <stdio.h>

int A;
extern void inc_a();

int main() {
	scanf("%d", &A);
	inc_a();
	printf("%d\n", A);
}

int a;


int f() {
	a = 1 + 1;
	return a;
}

int main() {
	a = 228 + 282;
	int b = a;
	f();
	a = b
}