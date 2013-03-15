#include "memPool_t.h"
#include <assert.h>
#include <string.h>

int main() {
	memPool_t::setNewPageSize(16);
	memPool_t *pool = new memPool_t(5);
	assert(pool->getPageCount() == 5);
	assert(pool->getCapacity() == 5 * 16);
	assert(pool->getSize() == 0);
	assert(pool->isEmpty());
	assert(pool->getPosition() == 0);
	int arr1[100] = {0};
	for (int i = 0; i < 100; ++i) {
		arr1[i] = 100 - i;
	}
	assert(pool->write(arr1, sizeof(arr1)) == sizeof(arr1));
	assert(pool->getPosition() == sizeof(arr1) + 1);
	assert(pool->getSize() == pool->getPosition());
	int arr2[100] = {0};
	assert(pool->setPosition(0) == 0);
	assert(pool->read(arr2, 1024) == sizeof(arr1));
	for (int i = 0; i < 100; ++i) {
		if (arr2[i] != 100 - i) assert(1 == 0);
	}
	char s1[] = "Calling a destructor explicitly is seldom necessary. However, it can be useful to perform cleanup of objects placed at absolute addresses."
	assert(pool->write(s1, sizeof(s1), 0) == sizeof(s1));
	char *s2 = new char[sizeof(s1)];
	assert(pool->read(s2, 5000, 0) == sizeof(s1));
	assert(strcmp(s1, s2) == 0);
	delete[] s2;
	delete pool;

}