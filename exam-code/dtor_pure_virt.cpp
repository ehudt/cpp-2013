class A {
public:
	virtual ~A() = 0;
};

inline A::~A() {}

class B : public A {

};

int main(void) {
	B b;
	return 0;
}