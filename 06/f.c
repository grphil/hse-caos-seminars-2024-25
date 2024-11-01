#include <stdio.h>

// ulimit -s unlimited увеличить размер стека

int main() {
	FILE* fin = fopen("in.txt", "r");
	FILE* fout = fopen("out.txt", "w"); //w+

	freopen("in.txt", "r", stdin);

	int a, b;
	fscanf(fin, "%d%d", &a, &b);

	fprintf(fout, "%d\n", a + b);
	fprintf(stderr, "%d\n", a + b);

	fclose(fin);
	fclose(fout);
}