#include <iostream>
#include <list>
using namespace std;

class A {
public:
	A(int a = 11) : a(a) {}

	int a;
};

class B : public A {
public:
	B(int a = 5, int b = 17) : A(5), b(17) {}

	int b;
};

int main(void) {
	A a(11);
	B b;
	list<A> lst;
	lst.push_back(a);
	lst.push_back(b);
	for (list<A>::iterator it = lst.begin(); it != lst.end(); ++it) {
		cout << (*it).a << endl;
	}
	B& b2 = dynamic_cast<B>(lst.back());
	cout << b2.b << endl;
	return 0;
}