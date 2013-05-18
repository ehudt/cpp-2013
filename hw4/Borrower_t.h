#ifndef _BORROWER_T_H
#define _BORROWER_T_H

#include <set>
#include <string>
#include <iostream>

#include "Book_t.h"

using namespace std;

class Book_t;

typedef set<const Book_t*> BookSet_t;

class Borrower_t {
	// Support printing operations
	friend ostream& operator << (ostream& os, const Borrower_t& borrower);

public:
	// CTOR using name. ID is assigned automatically.
	Borrower_t(string name);
	virtual ~Borrower_t();

	// Get user ID
	int GetId() const;
	// Get user name
	const string& GetName() const;
	// Loan a book. If the book is not available, the borrower is added to
	// the book's waiting list and the function returns false.
	virtual bool Loan(Book_t& book);
	// Return a book. Returns false if the book wasn't loaned by the borrower.
	virtual bool Return(Book_t& book);
	// Check if this borrower has books loaned
	virtual bool HasLoans() const;

private:
	// Prevent copying and assigning
	Borrower_t(const Borrower_t& other);
	const Borrower_t& operator = (const Borrower_t& rhs);

	// Generate unique IDs
	static int GetNextID();

	// Unique borrower ID
	const int id;
	// Borrower's name
	const string name;
	// Set of loaned books
	BookSet_t my_books;

	// A static data mamber for assigning IDs
	static int id_assign;
};

#endif // _BORROWER_T_H
