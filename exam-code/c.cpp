#ifdef __cplusplus
#include <cstdio>
#define GCC "G++"
#else
#include <stdio.h>
#define GCC "GCC"
#endif

int main(void) {
	printf(GCC ": %lu\n", sizeof('a'));
	return 0;
}