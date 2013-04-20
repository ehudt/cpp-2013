#include "../Dlist_t.h"
#include <iostream>
#include <cassert>

void Dlist_t_test1(){
	Dlist_t<int> list1;
	const int limit = 10;

	// Insert consecutive numbers and make sure that they are inserted in order
	for (int i = 0; i < limit; ++i) {
		assert(list1.count() == i);
		int *num = new int(i);
		if (i % 2) {
			assert(list1.append(*num, i - 1));
		}
		else {
			assert(list1.insert(*num));
		}
	}
	assert(list1.count() == limit);
	assert_range(list1);

	// do a find on all items in list1
	for (int i = 0; i < limit; ++i) {
		assert(*list1.find(i) == i);
	}

	// copy list1 into list 2 and check that they're equal
	Dlist_t<int>* list2p = new Dlist_t<int>(list1);
	assert(list2p->count() == list1.count());
	assert_equal(list1, *list2p);
	assert_range(*list2p);

	// remove all from list2
	for (int i = 0; i < list2p->count(); ++i) {
		assert(*list2p->remove(i) == i);
	}
	assert(list2p->count() == 0);

	// copy list1 into list2 again
	*list2p = list1;
	assert(list2p->count() == list1.count());
	assert_equal(list1, *list2p);
	assert_range(*list2p);

	// don't delete manually - DTOR takes care of that
	delete list2p;

	Dlist_t<int> list3;
	assert(list3.insert(*(new int(limit - 1))));
	for (int i = limit - 2; i >= 0; --i) {
		assert(list3.prepend(*(new int(i)), 0));
	}
	assert(list3.count() == limit);
	assert_range(list3);
	assert_equal(list1, list3);
	for (int i = 0; i < limit; ++i) {
		assert(list3.removeAndDelete(i));
	}
	assert(list3.count() == 0);


	// Append a new entry in the middle and try and find it
	int new_num = limit * 2;
	int* extra = new int(new_num);
	assert(list1.append(*extra, limit / 3));
	int* extra_find = list1.find(new_num);
	assert(extra_find);
	assert(extra == extra_find);
	assert(list1.count() == limit + 1);

	// clean up
	list1.removeAllAndDelete();
	assert(list1.count() == 0);
}

template <class T>
void assert_equal(Dlist_t<T>& list1, Dlist_t<T>& list2) {
	list1.reset();
	list2.reset();
	assert(list1.count() == list2.count());
	T* p1 = list1.next();
	T* p2 = list2.next();
	for (int i = 0; i < list1.count(); ++i) {
		assert(p1);
		assert(p2);
		assert(*p1 == *p2);
		p1 = list1.next();
		p2 = list2.next();
	}
	assert(p1 == 0);
	assert(p2 == 0);
	list1.reset();
	list2.reset();
}

template <class T>
void assert_range(Dlist_t<T>& list) {
	list.reset();
	T* p = list.next();
	for (int i = 0; i < list.count(); ++i) {
		assert(p) && assert (i == *p);
		p = list.next();
	}
	assert(p == 0);
	p = list.prev();
	for (int i = list.count() - 1; i >= 0; --i) {
		assert(p) && assert (i == *p);
		p = list.prev();
	}
	assert(p == 0);
	for (int i = 0; i < list.count() / 2; ++i) {
		list.next();
	}
	reset();
	assert(*list.next() == 0);
	assert(*list.next() == 1);
	list.reset();
}
