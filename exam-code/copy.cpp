#include <iostream>
 
struct C {
  C() {std::cout << "CTOR\n";}
  C(const C&) { std::cout << "A copy was made.\n"; }
};
 
C f() {
	std::cout<< "inside";
	C obj = C();
  return obj;
}
 
int main() {
  std::cout << "Hello World!\n";
  std::cout<< "outside";
  C obj = f();
  C obj2 = obj;
}