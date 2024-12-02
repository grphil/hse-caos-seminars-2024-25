#include <stdio.h>

int main() {
	FILE* a = fopen("in.txt", "r");
	char buf[1000];
	fscanf(a, "%s", buf);
	printf("%s\n", buf);
}