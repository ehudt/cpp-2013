#include <iostream>
#include <string> 
#include <cstdio>

using namespace std;
#define print(c) do { cout << c << endl; } while(0)

class File {
public:
	virtual ~File() {
		print ("File-DTOR");
		if (!fclose(fp)) {
			int res = remove(m_name.c_str());
			if (res == 0) print("FILE REMOVED!!!");
			else print ("CAN'T REMOVE FILE!!!");
		}
	}
	File(const char* name, const char* mode) {
		m_name = name;
		m_mode = mode;
		fp = fopen(m_name.c_str(), m_mode.c_str());
	}

	void write() {
		int n = fwrite("Hello world", 1, 11, fp);
		if (n > 0) {
			print ("write file");
		} else {
			print ("write error");
		}
	}
private:
	string m_name;
	string m_mode;
	FILE* fp;
};

class DrvFile : public File {
public:
	DrvFile(const char* name, const char* mode) : File(name, mode) {}
	void write() { print("Drv Write"); }
};

void printFile(File fl) {
	cout << endl;
	fl.write();
	DrvFile* dPtr = dynamic_cast<DrvFile*>(&fl);
	if (dPtr == 0) print ("Base File");
	else print ("Drv File");
}

int main(void) {
	File file1("TAU_1.txt", "w+");
	printFile(file1);
	printFile(file1);
	DrvFile file2("TAU_2.txt", "w+");
	printFile(file2);
	return 0;
}