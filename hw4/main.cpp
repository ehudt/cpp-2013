#include <iomanip>
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <limits>
#include "Book_t.h"
#include "Borrower_t.h"
#include "Library_t.h"


class Borrower_t;
class Book_t;
class Library_t;


int main(void) {
	bool cont	= true;			// trigger to stop loop
	unsigned int c = (unsigned)-1;

	Library_t library;

	cout << "Welcome to our Library:" << endl;

	while (cont) {
		cout 	<< "	What would you like to do?"				<< endl
				<< "	0: Add a new book to the library" 		<< endl
				<< "	1: Remove a book from the library" 		<< endl
				<< "	2: Add a borrower to the library" 		<< endl
				<< "	3: Remove a borrower from the library"	<< endl
				<< "	4: Loan a book"							<< endl
				<< "	5: Return a book"						<< endl
				<< "	6: Print a book report"					<< endl
				<< "	7: Print a borrower report"				<< endl
				<< "	other: quit"							<< endl
				<< "Enter your choice : ";

		cin >> c;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}

		string isbn, bookName, author, borrowerName;
		size_t numOfCopies;
		int id;
		Borrower_t* borrower;
		Book_t* book;

		bool success;
		switch (c) {
		case 0:{
			cout << "Enter the book isbn:  " << endl;
			cin.get();
			getline(cin,isbn);

			cout << "Enter the book name: " << endl;
			getline(cin, bookName);

			cout << "Enter the book author: " << endl;
			getline(cin, author);

			cout << "Enter the book number of copies: " << endl;
			cin >> numOfCopies;

			if (!cin.good()) {
				cout << "Invalid input" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}

			success = library.AddBook(bookName, author, isbn, numOfCopies);

			cout << "Adding the book " << (success ? "succeeded." : "failed.") << endl << endl;
			break;
		}

		case 1: {
			cout << "Enter ISBN of book to remove: " << endl;
			cin >> isbn;
			if (!cin.good()) {
				cout << "Invalid input" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
			book = library.SearchBook(isbn);
			if (book){
				success = library.RemoveBook(*book);
			}
			else
				success = false;

			cout << "Removing the book " << (success ? "succeeded." : "failed. ") << endl << endl;
			break;
		}

		case 2: {
			cout << "Enter the name for the new borrower " << endl;

			cin.get();
			getline(cin,borrowerName);

			if (!cin.good()) {
				cout << "Invalid input" << endl << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}

			id = library.AddBorrower(borrowerName);

			cout << "The borrower were added with ID: " << id << endl << endl;
			break;
		}

		case 3: {
			cout << "Enter ID for borrower to be removed " << endl;
			cin >> id;
			if (!cin.good()) {
				cout << "Invalid input" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}

			borrower = library.SearchBorrower(id);
			if (borrower){
				success = library.RemoveBorrower(*borrower);
			}
			else
				success = false;

			cout << "Removing the borrower " << (success ? "succeeded." : "failed.") << endl << endl;
			break;
		}

		case 4:
			cout << "Enter isbn for the book to loan, and the ID for the borrower: " << endl;
			cin >> isbn >> id;
				if (!cin.good()) {
					cout << "Invalid input" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					break;
				}

			book = library.SearchBook(isbn);
			borrower = library.SearchBorrower(id);

			if (borrower && book){
				success = library.LoanBook(*borrower,*book);
				cout << "Loaning the book " << book->GetName() << " to " << borrower->GetName() << (success ? " succeeded." : " failed.");
				cout << endl << endl;
			}
			else
				cout << "Book or borrower not found" << endl << endl;

			break;


		case 5:
			cout << "Enter isbn for the book to return, and the ID for the borrower: " << endl;
			cin >> isbn >> id;
				if (!cin.good()) {
					cout << "Invalid input" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					break;
				}


			book = library.SearchBook(isbn);
			borrower = library.SearchBorrower(id);

			if (borrower && book){
						success = library.ReturnBook(*borrower, *book);
						cout << "Returning the book " << book->GetName() << " from " << borrower->GetName() << (success ? " succeeded." : " failed.");
						cout << endl << endl;
						}
				else
					cout << "Book or borrower not found" << endl << endl;
			break;

		case 6:
			library.BookReport();
			break;

		case 7:
			library.BorrowerReport();
			break;

		default:
			cont = false;
			break;
		}
	}

	cout << "Bye." << endl;
	return 0;
}

