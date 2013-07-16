#include <string>
#include <iostream>
#include <exception>

using namespace std;

class X {};

void f() {
	try {
		//throw 5;
		try {
			throw X();
		} catch (X& x) {
			cout << "inner catch X&" << endl;
			throw;
		}
		throw (short)5;
	} catch (int ex) {
		cout << "int exception" << endl;
		//throw 6;
	} catch (X& x) {
		cout << "outer catch X&" << endl;
	} /*catch (X x) {
		cout << "outer catch X" << endl;
	} */catch (...) {
		cout << "rikavon" << endl;
	}
}

class Base {
public:
	virtual string what() const {
		return "Base::what()";
	}
};

class Drv : public Base {
public:
	virtual string what() const {
		return "Drv::what()";
	}
};

void g() {
	try {
		try {
			throw Drv();
		} catch (Base& b) {
			cout << "Inner Base& handler" << endl;
			cout << b.what() << endl;
			throw b;
			//throw;
		}
	} catch (Drv& d) {
		cout << "Outer Drv& handler" << endl;
		cout << d.what() << endl;
	} catch (Base& b) {
		cout << "Outer Base& handler" << endl;
		cout << b.what() << endl;
	}
}

typedef void(*PFV)();
/*PFV set_terminate(PFV);*/
PFV prev;


void zubi() { cout << "terminator" << endl; set_terminate(prev);}

int main(void) {
	//f();
	prev = set_terminate(zubi);
	throw "kaki";
	g();
	return 0;
}