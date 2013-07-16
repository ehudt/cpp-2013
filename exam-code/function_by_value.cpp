#include <iostream>
#include <string> 

using namespace std;
#define print(c) do { cout << c << endl; } while(0)

class A {
public:
	virtual ~A() {}
private:
	int a;
};

class B : public A {
private:
	int b;
};

void foo(A a) {
	B* b = dynamic_cast<B*>(&a);
	if (b) print("Derived");
	else print("Base");
}

int main(void) {
	B b;
	A a;
	foo(a);
	foo(b);
	return 0;
}