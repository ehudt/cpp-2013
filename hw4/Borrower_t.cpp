#include "Borrower_t.h"

int Borrower_t::id_assign = 1;

Borrower_t::Borrower_t(string name) :
	id(GetNextID()),
	name(name) {
	// Empty
}

Borrower_t::~Borrower_t() {
	// Empty
}

int Borrower_t::GetId() const {
	return id;
}

const string& Borrower_t::GetName() const {
	return name;
}

void Borrower_t::Loan(const Book_t& book) {
	my_books.insert(&book);
}

bool Borrower_t::Return(const Book_t& book) {
	// Make sure that the borrower loaned the book
	BookSet_t::const_iterator it = my_books.find(&book);
	if (it == my_books.end()) return false;
	my_books.erase(&book);
	return true;
}

bool Borrower_t::HasLoans() const {
	return (!my_books.empty());
}

int Borrower_t::GetNextID() {
	return id_assign++;
}
