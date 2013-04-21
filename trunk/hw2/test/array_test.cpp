#include "../Array_t.h"
#include <cassert>


void Array_tTest(){
	Array_t<int> array1;
	const int limit = 10;
/*	int* i = new int(5);
	int* j = new int(3);
	int* l = new int(2);

array1.insert(*i);
	assert(array1.find(*i)!=NULL);
	assert(array1.count()==1);
	array1.append(*j, 0);
	cout << array1[0] << ' ' << array1[1] << ' '<< array1.count() << "\n";
	assert(array1.insert(*l));
	assert(array1.removeAndDelete(*l));
	cout << array1[0] << ' ' << array1[1]  << ' ' << array1.count() << "\n";
 */

	for (int i = 0; i < limit; ++i) {
			assert(array1.count() == i);
			int *num = new int(i);
			if (i % 2) {
				assert(array1.append(*num, i - 1));
			}
			else {
				assert(array1.insert(*num));
			}
		}
		assert(array1.count() == limit);
		array1.removeAllAndDelete();
}
