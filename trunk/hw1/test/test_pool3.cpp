#include "memPool_t.h"
#include <assert.h>
#include <string.h>

int main() {
	memPool_t::setNewPageSize(1024);
	memPool_t *pool = new memPool_t(5);
	assert(pool->getPageCount() == 5);
	assert(pool->getCapacity() == 5 * 1024);
	assert(pool->getSize() == 0);
	assert(pool->isEmpty());
	assert(pool->getPosition() == 0);
	int arr1[10000] = {0};
	for (int i = 0; i < 10000; ++i) {
		arr1[i] = 10000 - i;
	}
	assert(pool->write(arr1, sizeof(arr1)) == sizeof(arr1));
	assert(pool->getPosition() == sizeof(arr1));
	assert(pool->getSize() == pool->getPosition());
	int arr2[10000] = {0};
	assert(pool->setPosition(0) == 0);
	assert(pool->getSize() == sizeof(arr1));
	assert(pool->read(arr2, 100000) == sizeof(arr1));
	for (int i = 0; i < 10000; ++i) {
		if (arr2[i] != 10000 - i) assert(1 == 0);
	}
	delete pool;
	memPool_t::setNewPageSize(4);
	pool = new memPool_t();
	for (int i = 0; i < 111; ++i) {
		assert(pool->write(&i, sizeof(i)) == sizeof(i));
	}
	assert(pool->getPageCount() == 111);
	delete pool;
}
