#include <stdio.h>
#include <dlfcn.h>

int main() {
	char fstr[100];
	int a, b;
	scanf("%s %d %d", fstr, &a, &b);

	void* lib = dlopen("aa", RTLD_NOW);

	if (lib == 0) {
		perror("dlopen");
		return 1;
	}

	int (*f)(int, int);

	f = dlsym(lib, fstr);

	if (f == NULL) {
		perror("No func found");
		return 1;
	}

	int c = f(a, b);
	printf("%d\n", c);
}