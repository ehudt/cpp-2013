#ifndef _LIBRARY_T_H
#define _LIBRARY_T_H

#include <map>
#include <string>

#include "Book_t.h"
#include "Borrower_t.h"

class Book_t;
class Borrower_t;

using namespace std;

typedef map<string, Book_t*> BookMap_t;
typedef map<int, Borrower_t*> BorrowerMap_t;

class Library_t{

public:
	Library_t();
	virtual ~Library_t();
	// Add a book to the library. If the book already exists, it only adds more
	// copies of the book to the library. If the ISBN already exists in the
	// library, but the other info doesn't match, the add fails (return false);
	virtual bool AddBook(const string& name, const string& author,
			const string& isbn, size_t copies);
	// Remove a book, if it exists. Returns false if the book doesn't
	// exist in the library.
	virtual bool RemoveBook(Book_t& book);
	//search for a book in the library. Returns null if there is no match
	virtual Book_t* SearchBook(const string& isbn) const;

	// Returns the unique ID assigned to the borrower
	virtual int AddBorrower(const string& name);
	// Search for a borrower in the library. Returns null if there is no match
	virtual Borrower_t* SearchBorrower(int id) const;
	virtual bool RemoveBorrower(Borrower_t& borrower);

	// Loan and return books
	// If the book is available it is loaned and the function returns true.
	// If the book isn't available, the borrower is added to the book's waiting
	// list and the function returns false.
	virtual bool LoanBook(Borrower_t& borrower, Book_t& book) const;
	// Return the book, if it was indeed loaned by the borrower (if not,
	// the function returns false). If the book's waiting list isn't empty,
	// It is immediately loaned to the first person in the waiting list.
	virtual bool ReturnBook(Borrower_t& borrower, Book_t& book) const;

	// Print a textual report of Books or Borrowers to standard output.
	virtual void BookReport() const;
	virtual void BorrowerReport() const;

private:
	// map for all the books in the library by ISBN
	BookMap_t books;
	// map for all the borrowers in the library by ID
	BorrowerMap_t borrowers;

	// Prevent from copying
	Library_t(const Library_t& other);
	Library_t& operator=(const Library_t& rhs);

};

#endif
