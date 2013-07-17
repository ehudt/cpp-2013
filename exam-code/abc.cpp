#include <iostream>

using namespace std;
#define print(c) do { cout << c << endl; } while(0)

class ABC {
public:
	virtual ~ABC() = 0;
	virtual void foo() = 0;
};

ABC::~ABC() {}
void ABC::foo() {print("ABC::foo()");}

class A : public ABC {
public:
	void foo() {print("A::foo()"); ABC::foo();} // Must have this or we get error
};

int main(void) {
	A a;
	a.foo();
	return 0;
}