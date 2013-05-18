#include <assert.h>
#include <iostream>
#include <sstream>

#include "Book_t.h"
#include "Borrower_t.h"

void RunTest();

int main(void) {
	RunTest();
	std::cout << "Success!" << std::endl;
}

void RunTest() {
	Book_t* book = new Book_t("1234", "Lord of The Rings", "J.R.R. Tolkien", 10);
	assert(book->IsAvailable());
	assert(!book->IsLoaned());
	assert(book->GetAuthor() == "J.R.R. Tolkien");
	assert(book->GetName() == "Lord of The Rings");
	assert(book->GetIsbn() == "1234");

	Borrower_t** borrowers = new Borrower_t*[20];
	for (int i = 0; i < 20; ++i) {
		string num = static_cast<ostringstream*>( &(ostringstream() << i) )->str();
		borrowers[i] = new Borrower_t(string("shuki") + num);
	}
	// Loan the book to 10 people
	for (int i = 0; i < 10; ++i) {
		assert(book->IsAvailable());
		bool result = borrowers[i]->Loan(*book);
		assert(result);
		assert(book->IsLoaned());
	}
	// Add 10 people to the waiting list
	for (int i = 10; i < 20; ++i) {
		assert(!book->IsAvailable());
		bool result = borrowers[i]->Loan(*book);
		assert(!result);
		// Make sure that the waiting people don't have the book
		result = borrowers[i]->Return(*book);
		assert(!result);
	}
	// Make the first 10 people return the book
	for (int i = 0; i < 10; ++i) {
		bool result = borrowers[i]->Return(*book);
		assert(result);
		assert(!book->IsAvailable());
		assert(book->IsLoaned());
	}
	// Make the other 10 people return the book
	for (int i = 10; i < 20; ++i) {
		assert(book->IsLoaned());
		bool result = borrowers[i]->Return(*book);
		assert(result);
		assert(book->IsAvailable());
	}
	assert(!book->IsLoaned());

	// Release memory
	for (int i = 0; i < 20; ++i) {
		delete borrowers[i];
	}
	delete[] borrowers;
	delete book;
}
