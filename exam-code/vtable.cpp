#include <iostream>

using namespace std;
#define print(c) do { cout << c << endl; } while(0)


class A {
public:
	virtual ~A(){}
};

int main(void) {
	A* a = new A;
	a->__vptr;
	delete a;
}