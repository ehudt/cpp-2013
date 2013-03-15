#include "memPool_t.h"
#include <assert.h>

int main(){
	memPool_t::setNewPageSize(12);
	memPool_t p;
	int x = 450;
	assert(p.isEmpty());
	assert(p.getSize()==0);
	assert(p.write(&x, sizeof(x)) == 4);
	assert(p.getSize() == 4);
	assert(p.setPosition(5000)==-1);
	assert(p.getPosition() == 4);
	for (int i = 0; i < 5; ++i){
		p.write(&i, sizeof(i));
	}

	assert(p.getSize() == 24);
	assert(p.getPosition() == 24);
	assert(p.getPageCount() ==2);




}