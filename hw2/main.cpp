#include "Container_t.h"
#include "Dlist_t.h"
#include "Array_t.h"
#include <iostream>
using namespace std;

void Dlist_t_test1();
void Array_tTest();

int main(void) {
	Dlist_t_test1();
	Array_tTest();
	cout << "All tests passed..." << endl;

	bool cont	= true;			// trigger to stop loop
		unsigned int c = (unsigned)-1;

		Container_t<int>* container = 0;
		// Ask the user if they want an array or a linked list
		cout << "Testing a Container_t<int>:" << endl
			 << "	0: Array"		<< endl
			 << "	1: Linked list" << endl
			 << "	other: Quit"	<< endl
			 << "Enter your choice: ";
		cin >> c;

		if (c == 0) {
			container = new Array_t<int>();
		} else if (c == 1) {
			container = new Dlist_t<int>();
		} else {
			cout << "Bye." << endl;
			return 0;
		}

		while (cont) {
			cout << "	0: insert" 				<< endl
				 << "	1: find" 				<< endl
				 << "	2: remove" 				<< endl
				 << "	3: append" 				<< endl
				 << "	4: prepend" 			<< endl
				 << "	5: count" 				<< endl
				 << "	6: removeAndDelete" 	<< endl
				 << "	7: removeAll" 			<< endl
				 << "	8: removeAllAndDelete" 	<< endl
				 << "Enter your choice : ";

			cin >> c;
			if (!cin.good()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}

			int value, index;
			int* p = 0;
			bool success, result;
			switch (c) {
				case 0:
					cout << "Enter int to insert: ";
					cin >> value;
					if (!cin.good()) {
						cout << "Invalid input" << endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						break;
					}
					container->insert(*(new int(value)));
					break;
				case 1:
					cout << "Enter int to find: ";
					cin >> value;
					if (!cin.good()) {
						cout << "Invalid input" << endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						break;
					}
					p = container->find(value);
					cout << "Value " << (p ? "" : "not ") << "found." << endl;
					break;
				case 2:
					cout << "Enter int to remove: ";
					cin >> value;
					if (!cin.good()) {
						cout << "Invalid input" << endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						break;
					}
					p = container->remove(value);
					cout << "Value " << (p ? "" : "not found and not ") << "removed." << endl;
					break;
				case 3:
					cout << "Enter value and index to append to:" << endl;
					cin >> value >> index;
					if (!cin.good()) {
						cout << "Invalid input" << endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						break;
					}
					success = true;
					try {
						container->append(*(new int(value)), index);
					} catch (Container_t<int>::Error err) {
						success = false;
					}
					cout << "Append " << (success ? "succeeded." : "failed. Index out of bounds.") << endl;
					break;
				case 4:
					cout << "Enter value and index to prepend to:" << endl;
					cin >> value >> index;
					if (!cin.good()) {
						cout << "Invalid input" << endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						break;
					}
					success = true;
					try {
						container->prepend(*(new int(value)), index);
					} catch (Container_t<int>::Error err) {
						success = false;
					}
					cout << "Prepend " << (success ? "succeeded." : "failed. Index out of bounds.") << endl;
					break;
				case 5:
					cout << "Count: " << container->count() << endl;
					break;
				case 6:
					cout << "Enter int to remove and delete: ";
					cin >> value;
					if (!cin.good()) {
						cout << "Invalid input" << endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						break;
					}
					result = container->removeAndDelete(value);
					cout << "Value " << (result ? "" : "not found and not ") << "removed and deleted." << endl;
					break;
				case 7:
					container->removeAll();
					cout << "All items were removed from container." << endl;
					break;
				case 8:
					container->removeAllAndDelete();
					cout << "All items were removed from container and deleted." << endl;
					break;
				default : cont = false;
			}
		}
		container->removeAllAndDelete();
		delete container;
		cout << "Bye." << endl;
		return 0;
	}
