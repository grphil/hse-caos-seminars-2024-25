#include <stdio.h>
#include <stdint.h>
#include <string.h>

// ulimit -s unlimited увеличить размер стека

int main() {
	int n;
	scanf("%d", &n);
	char s[n + 1];
	scanf("%s", s);
	printf("%s %zd\n", s, strlen(s));
}