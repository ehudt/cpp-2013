#include "Book_t.h"

friend ostream& operator <<(ostream& os, const Book_t& book) {
	os << book.author << ", " << book.name << ". ISBN: " << book.isbn << endl;
	os << "This book is loaned out to: ";
	for (set<Borrower_t&>::const_iterator it = book.loans.begin();
			it != book.loans.end(); ++it) {
		os << it->GetName() << " (" << it->GetId() << ") ";
	}
	os << endl;
	return os;
}

Book_t::Book_t(const string& isbn, const string& name, const string& author,
		size_t num_of_copies) :
			isbn(isbn),
			name(name),
			author(author),
			available_copies(num_of_copies),
			loaned_copies(0) {}

Book_t::~Book_t() {
	// Empty
}

bool Book_t::Loan(Borrower_t& loan_to) {
}

bool Book_t::Return(Borrower_t& return_from) {
}

bool Book_t::IsAvailable() const {
	return available_copies > 0;
}

bool Book_t::IsLoaned() const {
	return loaned_copies > 0;
}
