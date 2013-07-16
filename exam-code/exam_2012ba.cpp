#include <string>
#include <iostream>

using namespace std;

class NoHeap {
protected:
	static void* operator new(size_t sz) {
		return (void*)0;
	}
	static void* operator new[](size_t sz) {
		return (void*)0;
	}
};

class NoStack {
public:
	void Destroy() {
		delete this;
	}
protected:
	~NoStack() {}

};


int main(void) {
	NoStack ns;
	NoStack* pns = new NoStack();
	NoHeap nh;
	//NoHeap* pnh = new NoHeap();
	return 0;
}