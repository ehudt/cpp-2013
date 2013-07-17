#include <iostream>

using namespace std;

#define print(c) do { cout << c << endl; } while(0)



class A {
public:
	A(int x, int y) {}
};
class B{int x;};
int main(void) {
	A* arr1[10]; // 10 pointers to A
	A** arr2 = new A *[10]; // Dynamic array of 10 As
	B arr3[10];
	print (sizeof(arr1));
	print(typeid(arr1).name());
	print (sizeof(arr2));
	print(typeid(arr2).name());
	print (sizeof(arr3));
	print(typeid(arr3).name());
	delete arr2;
	return 0;
}