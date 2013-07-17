#include <iostream>
#include <string> 

using namespace std;
#define print(c) do { cout << c << endl; } while(0)


class A {
public:
	virtual ~A() {}
	virtual void foo() { print ("A::foo()");}  // Comment out this line for great magic!
	virtual void foo() const { print ("A::foo() const");}
};

class B : public A {
public:
	virtual void foo() {print ("B::foo()"); }
	virtual void foo() const {print ("B::foo() const"); }
};

void func(const A& a) {
	a.foo();
	A& a_ = const_cast<A&>(a);
	a_.foo();
}

int main(void) {
	//A a;
	//a.foo();
	//func(a);
	B b;
	//b.foo();
	func(b);
	return 0;
}