#ifndef _BOOK_T_H
#define _BOOK_T_H

#include <set>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

class Borrower_t;

class Book_t {
	// Support printing operations
	friend ostream& operator << (ostream& os, const Book_t& book);

public:
	// CTOR using required fields
	Book_t(const string ISBN, const string name, const string author,
			int num_of_copies);
	~Book_t();

	// Loan the book out to someone, if the book is available. Return true on success.
	// If the book has no available copies, the function returns false and adds the
	// borrower to the waiting list.
	bool Loan(Borrower_t& loan_to);
	// Return a book to the library. If the waiting list isn't empty, returning
	// a book will loan it to the first borrower in the waiting list.
	bool Return(Borrower_t& return_from);
	// Returns whether there are available copies of the book in the library.
	bool IsAvailable() const;
	// Returns whether there are copies of the book which are loaned out
	bool IsLoaned() const;

private:
	// Disable copying and assigning books
	Book_t(Book_t& other);
	Book_t& operator = (Book_t& rhs);

	// Unique string identifier of a book
	string isbn;
	// Book name
	string name;
	// Book author
	string author;
	// # of copies of the book which are available to loan in the library
	int available_copies;
	// # of copies that are out of the library
	int loaned_copies;
	// Set of people who loaned the book
	set<Borrower_t&> loans;
	// Queue of people who are waiting to loan the book
	queue<Borrower_t&> waiting_list;
};

#endif // _BOOK_T_H
