#include <stdio.h>
#include <stdint.h>

int main() {
	float x, y;
	scanf("%f%f", &x, &y);
	printf("%f\n", x * y);
	printf("%e\n", x * y);
	printf("%.10f\n", x * y);
	printf("%.10E\n", x * y);
	printf("%a\n", x * y);
	printf("%g\n", x * y);
}