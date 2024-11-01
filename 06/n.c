#include <stdio.h>
#include <string.h>

void make_good(char* s) {
	char* l = s;
	for (char* i = s; *i != '\0'; i++) {
		if (*i != 'z' && *i != 'Z') {
			*l = *i;
			l++;
		}
	}
	*l = '\0';
}

int main() {
	char s[1000];
	scanf("%s", s);
	printf("%zu\n", strlen(s));
	make_good(s);
	printf("%s %zu\n", s, strlen(s));
}