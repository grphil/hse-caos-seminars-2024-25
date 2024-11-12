#include <stdio.h>

extern float minsq(float a, float b);

int main() {
	float a, b;
	scanf("%f%f", &a, &b);
	float c = minsq(a, b);
	printf("%f\n", c);
}