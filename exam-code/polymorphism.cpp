#include <string>
#include <iostream>
using namespace std;

class B;

class A {
public:
	A(int x) : x(x) {}
	virtual bool operator == (const A& rhs) const {
		cout << "A.operator== (A&)" << endl;
		return x == rhs.x;
	}
	/*virtual bool operator == (const B& rhs) const {
		cout << "A.operator== (B&)" << endl;
		return false;
	}*/
private:
	int x;
};

class B : public A {
public:
	B(int x, int y) : A(x), y(y) {}
	virtual bool operator == (const A& rhs) const {
		cout << "B.operator== (A&)" << endl;
		return false;
	}
	virtual bool operator == (const B& rhs) const {
		cout << "B.operator== (B&)" << endl;
		return A::operator==(rhs) && y == rhs.y;
	}
private:
	int y;
};

int main(void) {
	A a(5);
	B b(5, 16);
	B b2(5, 16);
	B b3(5, 7);
	B b4(1, 16);
	A* a2 = &b;
	/*cout << (a == b) << endl;
	cout << (b == a) << endl;
	cout << (*a2 == a) << endl;*/
	cout << (b == b2) << endl; // true
	cout << (b == b3) << endl; // false
	cout << (b == b4) << endl; // false
	cout << (a == b) << endl; //false
	return 0;
}