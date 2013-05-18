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
	Borrower_t* ehud = new Borrower_t("Ehud Tamir");
	assert(ehud->GetId() == 1);
	assert(ehud->GetName() == "Ehud Tamir");
	assert(!ehud->HasLoans());
	Borrower_t* arbel = new Borrower_t("Arbel Zinger");
	assert(arbel->GetId() == 2);
	assert(arbel->GetName() == "Arbel Zinger");
	assert(!arbel->HasLoans());

	Book_t book1("1234", "Color of Magic", "Terry Pratchett", 1000);
	Book_t book2("1235", "Ender's Game", "Orson Scott Card", 1000);

	bool result;

	// Loan books
	ehud->Loan(book1);
	assert(ehud->HasLoans());
	ehud->Loan(book2);
	assert(ehud->HasLoans());
	arbel->Loan(book1);
	assert(arbel->HasLoans());

	// Return books
	result = ehud->Return(book1);
	assert(result);
	// Try to return a book that you don't have
	result = arbel->Return(book2);
	assert(!result);

	result = ehud->Return(book2);
	assert(result);
	assert(!ehud->HasLoans());
	result = arbel->Return(book1);
	assert(result);
	assert(!arbel->HasLoans());

	// Release memory
	delete ehud;
	delete arbel;
}
