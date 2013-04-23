#include "../Array_t.h"
#include <cassert>
#include <iostream>

using namespace std;

void Array_tTest(){
	Array_t<int> array1;
	const int limit = 17;

	for (int i = 0; i < limit; ++i) {
			assert(array1.count() == i);
			int *num = new int(i);
			if (i % 3 == 1) {
				assert(array1.append(*num, i - 1));
			}
			else {
				assert(array1.insert(*num));
			}
		}

	int *j = new int(100);
	int *l = new int(103);
	array1.prepend(*j, 3);
	assert(array1.count() == limit+1);
	assert(array1.find(100)==j);
	array1.prepend(*l, 3);
	assert(array1.remove(103));
	assert(array1.count() == limit+1);
	assert(array1.removeAndDelete(100));
	assert(array1.count() == limit);

	Array_t<int> array2 = array1;
	assert(array2.count()==array1.count());
	assert(array1[3] == array2[3]);

	int *k = new int(102);
	array2.insert(*k);
	array2 = array1;
	assert(array2.count()==array1.count());
	for (int i = 0; i < array1.count(); i++){
		assert(array1[i]==array2[i]);
	}
	delete k;
	delete l;
	array1.removeAllAndDelete();
}

