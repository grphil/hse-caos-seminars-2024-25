#include <stdio.h>

extern int calculate_rec_depth();

int rec(int n) {
	if (n == 0) {
		return calculate_rec_depth();
	} else {
		rec(n - 1);
	}
}

int main() {
	int a;
	scanf("%d", &a);
	printf("%d\n", rec(a));
}