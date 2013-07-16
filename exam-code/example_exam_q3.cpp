#include <string>
#include <iostream>

using namespace std;

class String {
public:
	String() : pStr(0) {}
	virtual ~String() { delete[] pStr; }
	String(const String& other) {
		pStr = new char[strlen(other.pStr) + 1];
		strcpy(pStr, other.pStr);
	}
	String(const char* str) { 
		pStr = new char[strlen(str) + 1];
		strcpy(pStr, str);
	}
	String& operator = (const String& rhs) {
		if (this != &rhs) {
			delete[] pStr;
			pStr = new char[strlen(rhs.pStr) + 1];
			strcpy(pStr, rhs.pStr);
		}
		return *this;
	}
	bool operator == (const String& rhs) const {
		return strcmp(pStr, rhs.pStr) == 0;
	}
	char& operator [](unsigned index) {
		return pStr[index];
	}
	char operator [](unsigned index) const {
		return pStr[index];
	}
private:
	char* pStr;
};

int main(void) {
	String s ("Hello");
	s[1] = 'E';
	cout << s[1] << endl;
}