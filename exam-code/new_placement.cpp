#include <iostream>

using namespace std;

class X_t {
public:
	X_t() {a = 655;}
private:
	int a;
};

class Y_t {
public:
	Y_t() {d = 5; c = '7';}
private:
	double d;
	char c;
};


void new_placement() {
	char* buffer = new char[100];
	X_t* x = new(buffer) X_t;
	Y_t* y = new(buffer + sizeof(*x)) Y_t;
	cout << x << endl;
	cout << y << endl;
	cout << sizeof(X_t) << endl;
	cout << sizeof(*y) << endl;
	y->~Y_t();
	x->~X_t();
	delete[] buffer;
}

int main(void) {
	
	return 0;
}