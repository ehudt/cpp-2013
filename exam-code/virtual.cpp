#include <iostream>

using namespace std;

#define print(c) do { cout << c << endl; } while(0)

//#define NON_VIRT_BASE

class A {
public:
#ifndef NON_VIRT_BASE
	virtual ~A() {print("virtual A::~A()");}
#else
	~A() {print("A::~A()");}
#endif
private:
	int a;
};


class B : public A {
public:
	~B() {print("B::~B()");}
private:
	int b;
};

int main(void) {
	A* b = new B;
	delete b;
}