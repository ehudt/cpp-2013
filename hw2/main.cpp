#include "Container_t.h"
#include "Dlist_t.h"
#include "Array_t.h"
#include <iostream>

using namespace std;

void Dlist_t_test1();
void Array_tTest();

int main(void) {
	Dlist_t_test1();
	Array_tTest();
	cout << "All tests passed..." << endl;


	return 0;
}
