#include <stdlib.h>
#include <stdio.h>

int main() {
	fprintf(stderr, "%s\n", "228");

	FILE* a = fopen("out.txt", "w");
	double s[3] = {1, 2, 3};
	int x = 1;

	fprintf(a, "%s", "1234");
	fwrite(s, sizeof(s[0]), 3, a);
	fwrite(&x, sizeof(x), 1, a);
	fclose(a);
}