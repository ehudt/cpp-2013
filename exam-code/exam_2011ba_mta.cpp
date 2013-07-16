#include <iostream>

using namespace std;

#define print(c) do { cout << c << endl; } while(0)

class C {
public:
	int x;
};

class A : public virtual C {};
class B : public virtual C {};

class D : public A, public B {};

void virtual_inhertiance() {
	D d;
	d.A::x = 9;
	d.B::x = 11;
	print(d.A::x);
	print(d.B::x);
	d.x = 7;
	print (d.x);
}

class X {
public:
	X(int x) : x(x) {}
	X(const X& other) : x(other.x) {}
	X& operator = (const X& rhs) {
		if (this != &rhs) {
			x = rhs.x;
		}
		return *this;
	}
	/*X operator + (const X& rhs) const {
		return X(x + rhs.x);
	}*/
	void * operator & () {
		return (void *)1;
	}
	friend X operator + (const X& lhs, const X& rhs) {
		return X(lhs) += rhs;
	}
	friend ostream& operator << (ostream& os, const X& x) {
		return os << x.x;
	}
	X& operator += (const X& rhs) {
		x += rhs.x;
		return *this;
	}
private:
	int x;
};

void operator_plus_eq() {
	X x(5);
	X y(2);
	print(x + y);
	print(x);
	print(y);
	x += y;
	print (x);
	print (&x);
}

template <class T>
T f() { return T(); }

template <class T>
void foo() { //f<int>(); 
}

class Kaki {
public:
	Kaki(int k) {print("Kaki CTOR");}
	Kaki(const Kaki& other) {print("Kaki Copy CTOR");}
	virtual ~Kaki() {}
};

void kaki() {
	Kaki k = Kaki(8);
	Kaki k2(8);
	Kaki j = k;
	j = Kaki(k);

}

int main(void) {
	//operator_plus_eq();	
	//foo<int>();
	kaki();
	return 0;
}