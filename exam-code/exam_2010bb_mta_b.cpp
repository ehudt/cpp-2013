#include <iostream>
using namespace std;

class A {
public:
	A()  { cout << "A::A()" << endl; }
	~A() { 
		cout << "A::~A()" << this << endl; 
		//throw "A::exception";
	}
};

class B {
public:
	B(A& a)  { 
		cout << "B::B()" << endl; 
		throw a;//"B::exception";
	}
	~B() { cout << "B::~B()"; }
};

int main() {
	try {
		cout << "Entering try..." << endl;
		A	objectA;
		B	objectB(objectA);
		cout << "Exiting try..." << endl;
	} catch ( A& ex) {
		cout << "catch block" << endl;
		//cout << ex << endl;
	}
	return 0;
}
