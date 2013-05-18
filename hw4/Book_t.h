#ifndef _BOOK_T_H
#define _BOOK_T_H

#include <set>
#include <queue>
#include <string>
#include <iostream>

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
	// If the book has no available copies, the function returns false.
	virtual bool Loan(const Borrower_t& loan_to);
	// Return a book to the library, if the input borrower did loan it.
	virtual bool Return(const Borrower_t& return_from);
	// Returns whether there are available copies of the book in the library.
	virtual bool IsAvailable() const;
	// Returns whether there are copies of the book which are loaned out
	virtual bool IsLoaned() const;
	// Add new copies of the book in the library.
	virtual void AddCopies(size_t copies_to_add);
	// Add and remove borrowers to the waiting list
	virtual void AddToWaitingList(const Borrower_t& borrower);
	virtual const Borrower_t* PopWaitingList();
	virtual bool WaitingListEmpty() const;

	const string& GetAuthor() const {
		return author;
	}

	const string& GetIsbn() const {
		return isbn;
	}

	const string& GetName() const {
		return name;
	}

	size_t getAvailableCopies() const {
		return available_copies;
	}

	size_t getLoanedCopies() const {
		return loaned_copies;
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
