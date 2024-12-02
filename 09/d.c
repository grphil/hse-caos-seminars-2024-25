#include <stdint.h>
#include <stdio.h>

void mul(uint64_t a, uint64_t b, uint64_t* rl, uint64_t* rh) {
	asm volatile (
		".intel_syntax noprefix\n"
		"mul rcx\n"
		".att_syntax prefix\n"
		: "=a" (*rl)
		, "=d" (*rh)
		: "a" (a)
		, "c" (b)
	);
}

int main() {
	uint64_t a, b, rl, rh;
	scanf("%llu%llu", &a, &b);
	mul(a, b, &rl, &rh);
	printf("%llu %llu\n", rl, rh);
}