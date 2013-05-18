#ifndef _BOOK_T_H
#define _BOOK_T_H

#include <set>
#include <queue>
#include <string>
#include <iostream>

#include "Borrower_t.h"
//#include "Library_t.h"

class Borrower_t;

using namespace std;

typedef set<const Borrower_t*> BorrowerSet_t;
typedef queue<const Borrower_t*> BorrowerQueue_t;

class Book_t {
	// Support printing operations
	friend ostream& operator << (ostream& os, const Book_t& book);

public:
	// CTOR using required fields
	Book_t(const string& isbn, const string& name, const string& author,
			size_t num_of_copies);
	virtual ~Book_t();

	// Loan the book out to someone, if the book is available. Return true on success.
	// If the book has no available copies, the function returns false and adds the
	// borrower to the waiting list.
	virtual bool Loan(const Borrower_t& loan_to);
	// Return a book to the library. If the waiting list isn't empty, returning
	// a book will loan it to the first borrower in the waiting list.
	virtual bool Return(const Borrower_t& return_from);
	// Returns whether there are available copies of the book in the library.
	virtual bool IsAvailable() const;
	// Returns whether there are copies of the book which are loaned out
	virtual bool IsLoaned() const;

	const string& GetAuthor() const {
		return author;
	}

	const string& GetIsbn() const {
		return isbn;
	}

	const string& GetName() const {
		return name;
	}

private:
	// Disable copying and assigning books
	Book_t(Book_t& other);
	Book_t& operator = (Book_t& rhs);

	// Unique string identifier of a book
	const string isbn;
	// Book name
	const string name;
	// Book author
	const string author;
	// # of copies of the book which are available to loan in the library
	size_t available_copies;
	// # of copies that are out of the library
	size_t loaned_copies;
	// Set of people who loaned the book
	BorrowerSet_t loans;
	// Queue of people who are waiting to loan the book
	BorrowerQueue_t waiting_list;
};

#endif // _BOOK_T_H
