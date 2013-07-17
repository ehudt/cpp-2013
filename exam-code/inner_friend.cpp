#include <iostream>

using namespace std;

#define print(c) do { cout << c << endl; } while(0)


class A {
public:

	A() : c('d') {}
	friend ostream& operator << (ostream& os, const A& a) { return os << a.c; }
private:
	char c;
};


int main(void) {
	A b;
	cout << b;
	::operator<<(cout,(const A&)b);
	return 0;
}