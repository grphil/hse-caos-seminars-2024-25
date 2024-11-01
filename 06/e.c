#include <stdio.h>
#include <stdint.h>
#include <string.h>

// ulimit -s unlimited увеличить размер стека

int main() {
	size_t n;
	scanf("%zd", &n);

	int pasc[n][n];
	for (size_t i = 0; i < n; i++) {
		pasc[0][i] = 0;
		pasc[i][0] = 1;
	}
	int mx = 0;
	for (size_t i = 1; i < n; i++) {
		for (size_t j = 1; j < n; j++) {
			pasc[i][j] = pasc[i - 1][j] + pasc[i - 1][j - 1];
			if (pasc[i][j] > mx) {
				mx = pasc[i][j];
			}
		}
	}
	int len = 0;
	while (mx > 0) {
		mx /= 10;
		len++;
	}

	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j <= i; j++) {
			printf("%*d", len, pasc[i][j]);
		}
		printf("\n");
	}
}