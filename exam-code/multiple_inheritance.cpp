#include <iostream>

using namespace std;
#define print(c) do { cout << c << endl; } while(0)

class A {
public:
	virtual void foo(){}
};


class B {
public:
	virtual void foo(){}
};

class C: public A, public B {
public:
	using A::foo;
};

int main(void) {
	C c;
	c.foo();
	return 0;
}