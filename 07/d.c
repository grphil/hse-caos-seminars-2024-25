#include <unistd.h>
#include <stdio.h>

int main() {
	int* a = sbrk(10 * sizeof(int));
	for (int i = 0; i < 10; i++) {
		scanf("%d", a + i);
	}

	for (int i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}
}