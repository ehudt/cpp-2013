#include <iostream>

using namespace std;

#define print(c) do { cout << (c) << endl; } while(0)


class A {
public:
	virtual void foo() { print ("A");}
};

class B : public A {
private:
	virtual void foo() {print ("B");}
};
const int t=6;
int main(void) {
	B b;
	A* a = &b;
	a->foo();
	B b2;
	print(b == b2);
	return 0;
}