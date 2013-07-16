#include <iostream>
using namespace std;

class Foo{
public:
	int a() const {return 5;}
	virtual int b() const {return 6;}
};

int main(void) {
	Foo* f = 0;
	cout << f->a() << endl;
	cout << f->b() << endl;
	return 0;
}