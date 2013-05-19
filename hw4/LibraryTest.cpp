#include <assert.h>
#include <iostream>
#include <sstream>

#include "Book_t.h"
#include "Borrower_t.h"
#include "Library_t.h"

void RunTest();

int main(void) {
	RunTest();
	std::cout << "Success!" << std::endl;
}

void RunTest() {
	Library_t library;
	bool result;
	// Add some books
	result = library.AddBook("The Count of Monte Cristo", "Alexander Dumas", "123-555-001", 1);
	assert(result);
	result = library.AddBook("The Cat In The Hat", "Dr. Seuss", "123-555-002", 1);
	assert(result);
	result = library.AddBook("Hitchhiker's Guide To The Galaxy", "Douglas Adams", "123-555-003", 42);
	assert(result);
	result = library.AddBook("A Journey To The Center of The Earth", "Jules Verne", "123-555-004", 5000);
	assert(result);
	// Add more copies of one of the books
	result = library.AddBook("The Cat In The Hat", "Dr. Seuss", "123-555-002", 6);
	assert(result);
	// Add a new book with conflicting ISBN
	result = library.AddBook("The Fox In Socks", "Dr. Seuss", "123-555-002", 987654);
	assert(!result);
	// Find and remove a book
	Book_t* book = library.SearchBook("123-555-002");
	assert(book != 0);
	assert(book->GetIsbn() == "123-555-002");
	assert(book->GetName() == "The Cat In The Hat");
	assert(book->GetAuthor() == "Dr. Seuss");
	assert(book->getAvailableCopies() == 7);
	result = library.RemoveBook(*book);
	assert(result);
	// Remove a non existing book
	Book_t book_external("Introduction to Algorithms", "Cormen", "666-555-001", 1);
	result = library.RemoveBook(book_external);
	assert(!result);
	// Search for a non-existing book
	book = library.SearchBook(book_external.GetIsbn());
	assert(book == 0);

	// Add borrowers
	int id = library.AddBorrower("Ehud");
	assert(id == 1);
	id = library.AddBorrower("Arbel");
	assert(id == 2);
	id = library.AddBorrower("Moshe");
	assert(id == 3);
	id = library.AddBorrower("Moshe");
	assert(id == 4);
	// Find and delete the 2nd Moshe borrower
	Borrower_t* borrower = library.SearchBorrower(4);
	assert(borrower != 0);
	assert(borrower->GetId() == 4);
	assert(borrower->GetName() == "Moshe");
	result = library.RemoveBorrower(*borrower);
	assert(result);
	// Remove a non-existing borrower
	Borrower_t borrower_not_real("Cookie Monster");
	result = library.RemoveBorrower(borrower_not_real);
	assert(!result);
	// Search for a non-existent borrower
	borrower = library.SearchBorrower(5);
	assert(borrower == 0);

	// Make loans and returns
	Borrower_t& ehud = *library.SearchBorrower(1);
	Borrower_t& arbel = *library.SearchBorrower(2);
	Borrower_t& moshe = *library.SearchBorrower(3);
	Book_t& monte_cristo = *library.SearchBook("123-555-001");
	Book_t& hitchhiker = *library.SearchBook("123-555-003");
	Book_t& journey = *library.SearchBook("123-555-004");

	// Check that loaning works and waiting list works
	assert(!ehud.HasLoans());
	result = library.LoanBook(ehud, monte_cristo);
	assert(result);
	assert(ehud.HasLoans());
	assert(!arbel.HasLoans());
	result = library.LoanBook(arbel, monte_cristo);
	assert(!result);
	assert(!arbel.HasLoans());
	result = library.ReturnBook(ehud, monte_cristo);
	assert(result);
	assert(arbel.HasLoans());
	// Double return
	result = library.ReturnBook(ehud, monte_cristo);
	assert(!result);
	// Return a book that I never had
	result = library.ReturnBook(moshe, monte_cristo);
	assert(!result);

	result = library.LoanBook(moshe, hitchhiker);
	assert(result);

	// Try to remove a book that's loaned already
	result = library.RemoveBook(monte_cristo);
	assert(!result);
	// Return it
	result = library.ReturnBook(arbel, monte_cristo);
	assert(result);
	// Try again
	result = library.RemoveBook(monte_cristo);
	assert(result);

	// Try to remove a borrower that has books loaned out to
	result = library.RemoveBorrower(moshe);
	assert(!result);
	// Return the books
	result = library.ReturnBook(moshe, hitchhiker);
	assert(result);
	// Try again
	result = library.RemoveBorrower(moshe);
	assert(result);

	// Try to loan and return a book that's not in the library
	result = library.LoanBook(ehud, monte_cristo);
	assert(!result);

	// Try to loan and return from a borrower that's not in the library
	result = library.LoanBook(moshe, journey);
	assert(!result);
}
