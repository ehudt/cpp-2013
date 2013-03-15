#include "memPage_t.h"
#include <assert.h>

int main(){
	memPage_t::setNewPageSize(10);
	memPage_t *mp1 = new memPage_t;
	memPage_t::setNewPageSize(1024);
	memPage_t mp2;
	mp1->setNext(&mp2);
	assert(mp1->getNext() == &mp2);

	char s1[] = "Now this is the story all about how\n"
				"My life got flipped, turned upside down\n"
				"And I'd like to take a minute just sit right there\n"
				"I'll tell you how I became the prince of a town called Bel-air";
	assert(mp1->write(s1, sizeof(s1)) == 10);
	char s2[200] = {0};
	assert(mp1->setPosition(2) == 2);
	assert(mp1->read(s2, 200) == 8);
	assert(mp2.write("ehud", 5) == 5);
	assert(mp2.setPosition(0) == 0);
	assert(mp2.read(s2, 200) == 5);
	delete mp1;
	return 0;
}