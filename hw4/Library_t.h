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
	virtual bool AddBook(const string& name, const string& author,
			const string& isbn, size_t copies);
	virtual bool RemoveBook(Book_t& book);

	//search for a book in the library. Returns null if there isn't one
	virtual const Book_t* SearchBook(const string& isbn) const;

	virtual int AddBorrower(const string& name); //return the ID assigned after adding the borrower
	//search for a borrower in the library. Returns null if there isn't one
	virtual const Borrower_t* SearchBorrower(int id) const;
	virtual bool RemoveBorrower(Borrower_t& borrower);
	virtual void BookReport() const;
	virtual void BorrowerReport() const;

private:
	// map for all the books in the library by ISBN
	BookMap_t books;
	// map for all the borrowers in the library by ID
	BorrowerMap_t borrowers;

	// Prevent from copying
	Library_t(const Library_t& library);
	Library_t& operator=(const Library_t& rhs);

};

#endif
