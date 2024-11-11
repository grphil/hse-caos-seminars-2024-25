#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <stdbool.h>

void* min_element(
	void* arr, 
	size_t nitems, 
	size_t item_size, 
	bool (*comp)(void*, void*)
) {
	uint8_t* ptr = (uint8_t*)arr;
	void* mn = NULL;
	for (size_t i = 0; i < nitems; i++) {
		void* item_ptr = (void*)(ptr + i * item_size);
		if (mn == NULL || comp(item_ptr, mn)) {
			mn = item_ptr;
		}
	}
	return mn;
}

bool cmp(void* a, void* b) {
	return *(int*)a < *(int*)b;
}

int main() {
	int a[3] = {-1, 4, 2};
	int mn = *(int*)min_element(a, 3, sizeof(int), cmp);
	printf("%d\n", mn);
}