#include "../memPage_t.h"
#include <assert.h>

int main(){
	memPage_t p1;
	int y;
	int x = 357;

	assert(p1.getSize() == 0);
	assert(p1.getCapacity() == 1024);
	assert(p1.isEmpty());
	assert(p1.write(&x, sizeof(x)) == sizeof(x));
	assert(p1.getPosition() == sizeof(x));
	assert(p1.setPosition(1000) == -1);
	assert(p1.getPosition() == sizeof(x));
	assert(p1.read(&y, sizeof(y), 0) == sizeof(y));
	assert(y == x);
	assert(p1.setPosition(3) == 3);
	assert(p1.getPosition() == 3);

	char s1[] = "arbelzingerhagevgever";
	char* s2 = new char[sizeof(s1)+1];

	assert(p1.write(s1, sizeof(s1),4) == sizeof(s1));
	assert(p1.getPosition() == 26);
	assert(p1.setPosition(4) == 4);
	assert(p1.read(s2, sizeof(s1)) == sizeof(s1));
	while (p1.write(s1,sizeof(s1)) > 0) { continue; }
	assert(p1.isFull());
	assert(p1.getCapacity() == p1.getSize());

	memPage_t::setNewPageSize(20);
	memPage_t p2;
	assert(p2.getCapacity() == 20);
	assert(p2.isEmpty());
	assert(p2.write(s1, sizeof(s1)) == 20);
	assert(p2.getSize()==p2.getPosition());
	delete[] s2;

// Add set/get next tests and read/write extremes
}