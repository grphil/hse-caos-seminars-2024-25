#include <stdio.h>
#include <stdlib.h>

#include <time.h>

int main() {
	struct tm tt;
	scanf("%d-%d-%d %d:%d:%d", &tt.tm_year, &tt.tm_mon, &tt.tm_mday, &tt.tm_hour, &tt.tm_min, &tt.tm_sec);
	tt.tm_year -= 1900;
	tt.tm_mon -= 1;
	time_t curr_time = mktime(&tt);
	printf("%lu", curr_time);
}