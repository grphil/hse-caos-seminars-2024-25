#include <ctype.h>
#include <stdio.h>

int main() {
	int res = 0;
	int c;

	printf("%d\n", EOF);

	while ((c = getchar()) != EOF) {
		if (isspace(c)) {
			res++;
		}
	}

	printf("%d\n", res);
}