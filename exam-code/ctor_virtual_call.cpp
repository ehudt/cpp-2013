#include <iostream>

using namespace std;

#define print(c) do { cout << c << endl; } while(0)

class A {
public:

	virtual ~A() {}
	A() {foo();}
	virtual void foo() = 0;
};

//void A::foo()  {print("Base::foo()");}

class B : public A {
public:
	B() : A() {foo();}
	virtual void foo() {print("Drv::foo()");}

};

int main(void) {
	B b;
	return 0;
}