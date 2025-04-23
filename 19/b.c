#include <stdio.h>
#include <stdlib.h>

#include <time.h>

int main() {
	time_t tt = time(NULL);
	struct tm* t = localtime(&tt);
	printf("%d-%02d-%02d\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
}