#include <iostream>
using namespace std;

class Base {
public:
  Base() { foo(); }
  virtual void foo() = 0;// { cout << "base" << endl; } 
};

void Base::foo() { cout << "base" << endl; }

class Drv : public Base {
public:
  Drv() { foo(); }
  virtual void foo() { cout << "drv" << endl; }
};

int main(void) {
  Drv d;
  return 0;
}
