#include "../memPage_t.h"
#include <assert.h>

#define	NULL	0

int main(){
	int s1[] = {1,2,3,4,5,6};
	memPage_t::setNewPageSize(20);
	memPage_t p2;
	assert(p2.getCapacity() == 20);
	assert(p2.isEmpty());
	assert(p2.write(s1, sizeof(s1)) == 20);
	assert(p2.getSize()==p2.getPosition());
	assert(p2.setPosition(0) == 0);
	assert(p2.write(NULL, 500) == -1);
	assert(p2.getPosition() == 0);
	assert(p2.write(s1, -12) == -1);
	assert(p2.getPosition() == 0);
	assert(p2.read(NULL, 13) == -1);
	assert(p2.getPosition() == 0);
	assert(p2.read(s1, -5) == -1);
	assert(p2.getPosition() == 0);

}
