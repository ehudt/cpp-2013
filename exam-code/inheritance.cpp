#include <iostream>

using namespace std;
#define print(c) do { cout << c << endl; } while(0)

class A {
public:
	void foo(){ print("A::foo()"); }
};

class B_pub : public A {};

class B_pro : protected A {
public:
	void bar() { print("B::bar()"); }
};

class C_pro : public B_pro {
public:
	void foobar() { 
		print ("C_pro::foobar();");
		A::foo();
	}
};


class B_priv : private A {
public:
	void foobar2000() { 
		print("B_priv::foobar2000()");
		foo();
	}
};

class C_priv : public B_priv {};



int main(void) {
	B_pub b1;
	b1.foo();

	C_pro c1;
	c1.foobar();
	c1.bar();

	C_priv c2;
	c2.foobar2000();
	return 0;
}