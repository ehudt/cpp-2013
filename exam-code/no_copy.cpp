#include <iostream>

using namespace std;

#define print(c) do { cout << c << endl; } while(0)

class A{
public:
	A() {}
	A(const A& other);
	A& operator = (const A& rhs);
};

int main(void) {
	A a;
	A* pa = new A;
	delete pa;
	A b;
	b = a;
	return 0;
}