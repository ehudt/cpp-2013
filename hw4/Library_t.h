#ifndef _LIBRARY_T_H
#define _LIBRARY_T_H

#include <map>
#include <string>

using namespace std;

class Book_t;
class Borrower_t;

class Library_t{
public:
	Library_t();
	virtual ~Library_t();
	virtual bool AddBook(string name, string author, string isbn, int copies);
	virtual bool RemoveBook(string isbn);

	//search for a book in the library. Returns null if there isn't one
	virtual Book_t* SearchBook(string isbn) const;

	virtual int AddBorrower(string name); //return the ID assigned after adding the borrower
	//search for a borrower in the library. Returns null if there isn't one
	virtual Borrower_t* SearchBorrower(int id) const;
	virtual bool RemoveBorrower(int id);

private:
	// map for all the books in the library by ISBN
	map<string, Book_t&> books;
	// map for all the borrowers in the library by ID
	map<int, Borrower_t&> borrowers;

	// Prevent from copying
	Library_t(const Library_t& library);
	Library_t& operator=(const Library_t& rhs);

};

#endif
