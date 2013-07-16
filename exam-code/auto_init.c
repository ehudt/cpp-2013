#include <stdio.h>

struct SomeStruct {
	int n;
	char* s;
};

int main(void) {
	struct SomeStruct ss;
	printf("%d, %p\n", ss.n, ss.s);
	return 0;
}