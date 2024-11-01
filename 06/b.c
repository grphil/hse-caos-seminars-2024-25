#include <stdio.h>
#include <stdint.h>

int main() {
	uint32_t a, b;
	scanf("%o%o", &a, &b);
	printf("%u\n", a + b);
	printf("%05u\n", a + b);
	printf("%10u\n", a + b);
}