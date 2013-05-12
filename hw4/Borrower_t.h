#ifndef _BORROWER_T_H
#define _BORROWER_T_H

#include <set>
#include <string>
#include <iostream>

using namespace std;

class Book_t;

class Borrower_t {
	// Support printing operations
	friend ostream& operator << (ostream& os, const Borrower_t& borrower);

public:
	// CTOR using name. ID is assigned automatically.
	Borrower_t(string name);
	virtual ~Borrower_t();

	// Get user ID
	int GetId() const;
	// Loan a book
	virtual bool Loan(Book_t& book);
	// Return a book
	virtual bool Return(Book_t& book);

private:
	// Prevent copying and assigning
	Borrower_t(const Borrower_t& other);
	Borrower_t& operator = (const Borrower_t& rhs);

	// Unique borrower ID
	int id;
	// Borrower's name
	string name;
	// Set of loaned books
	set<Book_t&> my_books;

	// A static data mamber for assigning IDs
	static int id_assign;
};

#endif // _BORROWER_T_H
