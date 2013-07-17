#include <iostream>

using namespace std;
#define print(c) do { cout << c << endl; } while(0)


class A {
public:
	virtual ~A(){}
};

int main(void) {
	A* a = new A;
	int** v = reinterpret_cast<int **>(&a);
	print(*v);
	print(*(v + 1));
	print(*(v + 2));
	delete a;
}