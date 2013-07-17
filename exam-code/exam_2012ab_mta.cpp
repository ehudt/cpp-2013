#include <cmath>
#include <iostream>

using namespace std;

class Point
{
public:
	Point(double x = 0, double y = 0) { cout << "I shit on you " << x << " " << y << endl; }
private:
	double m_X, m_Y;
};

class Base {
public:
	void func(float f) { cout << "Base func" << endl; }
};

class Derived : public Base {
public:
	void func(string i) { cout << "Derived func" << endl; }
	void func(float f) { Base::func(f); }
};

void timtum() {
	double a, r, x, y;
	cout << a << " " << r << " " << x << " " << y << " " << endl;
	Point p = (x + r * cos(a), y + r * sin(a));
	Derived d;
	d.func(3.14);
	/*try {
		throw;
	} catch (...) {
		cout << "caught" << endl;
	}*/
}

void func(int i) { cout << "int" << endl;}
void func(char);
template <class T> class X
{
public:
	void foo(T t) { func(t);}
};
void func(char c) {cout << "char" << endl;}

int main(void) {
	//X<char> x;
	//x.foo('a');
	timtum();
	return 0;
}