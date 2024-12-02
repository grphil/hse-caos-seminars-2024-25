#include <immintrin.h>
#include <stdio.h>
#include <limits.h>

// #pragma GCC target("avx2")

int GetMin(const int* a, size_t n) {
	// __m256i - тип данных, хранящий 256 битов
	// _mm<data_size>_<instruction>_<type>
	// types:
	__m256i min_avx = _mm256_set1_epi32(INT_MAX);
	size_t i = 0;
	for (; i + 8 <= n; i += 8) {
		__m256i curr_block = _mm256_lddqu_si256((const __m256i*)(a + i));
		min_avx = _mm256_min_epi32(min_avx, curr_block);
	}
	int mn = INT_MAX;
	for (; i < n; i++) {
		if (mn > a[i]) {
			mn = a[i];
		}
	}
	int mmn[8];
	_mm256_storeu_si256((__m256i*)(mmn), min_avx);
	for (int i = 0; i < 8; i++) {
		if (mn > mmn[i]) {
			mn = mmn[i];
		}
	}
	return mn;
}

int main() {
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	int r = GetMin(a, n);
	printf("%d\n", r);
}