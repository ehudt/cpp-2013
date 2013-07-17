#include <iostream>

using namespace std;

#define print(c) do { cout << c << endl; } while(0)

class A {
public:
	A(int a) : a(a) {}
	virtual ~A() {}
	virtual A& operator =(const A& rhs) {
		if (this != &rhs) {
			a = rhs.a;
		}
		return *this;
	}
protected:
	int a;
};

class B : public A {
public:
	B(int a, int b) : A(a), b(b) {}
	friend ostream& operator << (ostream& os, const B& b) { return os << b.a << ", " << b.b << endl; }
	virtual B& operator =(const B& rhs) {
		if (this != &rhs) {
			a = rhs.a;
			b = rhs.b;
		}
		return *this;
	}
private:
	int b;
};

int main(void) {
	B b1(1, 2);
	B b2(3, 4);
	A* a1 = &b1;
	A* a2 = &b2;
	//*a1 = *a2;
	//(*a1).operator = (*a2);
	(*a1).operator = (b2);
	//*(&b1) = *(&b2);
	print(b1);
	print(b2);
	return 0;
}