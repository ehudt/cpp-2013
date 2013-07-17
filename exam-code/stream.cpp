#include <iostream>
#include <sstream>
#include <map>
#include <fstream>
using namespace std;

#define print(c) do { cout << c << endl; } while(0)
typedef map<string, int> WordDict;
void WordFrequency(const string& filename) {
	ifstream file(filename.c_str());
	WordDict words;
	while (file.good()) {
		string str;
		file >> str;
		WordDict::iterator it = words.find(str);
		if (it == words.end()) {
			words.insert(make_pair(str, 1));
		} else {
			it->second++;
		}
	}
	for (WordDict::const_iterator it = words.begin(); it != words.end(); ++it) {
		cout << it->first << "\t" << it->second << endl;
	}
}

int main(void) {
	WordFrequency("text.txt");
	return 0;
}