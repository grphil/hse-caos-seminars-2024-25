#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef struct {
	char* s;
	size_t size;
	size_t capacity;
} string;

string read_string() {
	string s = {
		.s = calloc(1, sizeof(char)),
		.size = 0,
		.capacity = 1,
	};

	char c;
	while ((c = getchar()) != EOF) {
		if (isspace(c)) {
			if (s.size > 0) {
				break;
			} else {
				continue;
			}
		}

		if (s.size == s.capacity - 1) {
			char* new_s = realloc(s.s, s.capacity * 2);
			s.s = new_s;
			s.capacity *= 2;
		}
		s.s[s.size] = c;
		s.size++;
	}
	s.s[s.size] = '\0';
	return s;
}

void remove_string(string* s) {
	free(s->s);
	s->s = NULL;
	s->size = 0;
	s->capacity = 0;
}

int main() {
	string a = read_string();
	string b = read_string();
	printf("%s\n%s\n", a.s, b.s);
	remove_string(&a);
	remove_string(&b);
}