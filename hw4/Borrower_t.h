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
	~Borrower_t();

	int GetId() const;
	bool Loan(Book_t& book);
	bool Return(Book_t& book);

private:
	int id;
	string name;
	set<Book_t&> my_books;

	static int id_assign;
};

#endif // _BORROWER_T_H
