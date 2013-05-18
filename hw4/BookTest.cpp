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
	assert(book->getAvailableCopies() == 10);
	Borrower_t** borrowers = new Borrower_t*[20];
	for (int i = 0; i < 20; ++i) {
		string num = static_cast<ostringstream*>( &(ostringstream() << i) )->str();
		borrowers[i] = new Borrower_t(string("shuki") + num);
	}
	// Loan the book to 10 people
	for (unsigned i = 0; i < 10; ++i) {
		assert(book->IsAvailable());
		bool result = book->Loan(*borrowers[i]);
		assert(result);
		assert(book->IsLoaned());
		assert(book->getLoanedCopies() == i+1);
	}
	// Make sure that we can't give the book to more people
	assert(!book->IsAvailable());
	bool result = book->Loan(*borrowers[10]);
	assert(!result);
	// Make sure that you can't return the book if you don't have it
	result = book->Return(*borrowers[10]);
	assert(!result);
	// Add more copies and give them to the other 10 people
	book->AddCopies(10);
	assert(book->getAvailableCopies() == 10);
	assert(book->getLoanedCopies() == 10);
	assert(book->IsLoaned());
	for (unsigned i = 10; i < 20; ++i) {
		assert(book->IsAvailable());
		bool result = book->Loan(*borrowers[i]);
		assert(result);
		assert(book->IsLoaned());
		assert(book->getLoanedCopies() == i+1);
	}
	// Make everyone return the book
	for (int i = 0; i < 20; ++i) {
		assert(book->IsLoaned());
		bool result = book->Return(*borrowers[i]);
		assert(result);
		assert(book->IsAvailable());
	}
	assert(!book->IsLoaned());
	assert(book->getAvailableCopies() == 20);
	assert(book->getLoanedCopies() == 0);

	// Test waiting list
	assert(book->WaitingListEmpty());
	for (int i = 0; i < 20; ++i) {
		book->AddToWaitingList(*borrowers[i]);
		assert(!book->WaitingListEmpty());
	}
	for (int i = 0; i < 20; ++i) {
		const Borrower_t* borrower = book->PopWaitingList();
		assert(borrower != 0);
	}
	assert(book->WaitingListEmpty());
	// Release memory
	for (int i = 0; i < 20; ++i) {
		delete borrowers[i];
	}
	delete[] borrowers;
	delete book;
}
