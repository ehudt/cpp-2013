#include "Borrower_t.h"

ostream& operator <<(ostream& os,
		const Borrower_t& borrower) {
	os << borrower.GetName() << " (" << borrower.GetId() << ")" << endl;
	os << "This reader has the following books loaned to: ";
	for (BookSet_t::const_iterator it = borrower.my_books.begin();
			it != borrower.my_books.end(); ++it) {
		const Book_t& book = *(*it);
		os << book.GetAuthor() << ", " << book.GetName() << ". ISBN: " << book.GetIsbn() << endl;
	}
	os << endl;
	return os;
}

int Borrower_t::id_assign = 1;

Borrower_t::Borrower_t(string name) :
	id(GetNextID()),
	name(name) {
	// Empty
}

Borrower_t::~Borrower_t() {
	// Empty
}

bool Borrower_t::operator <(Borrower_t& rhs) const {
	return id < rhs.id;
}

int Borrower_t::GetId() const {
	return id;
}

const string& Borrower_t::GetName() const {
	return name;
}

bool Borrower_t::Loan(Book_t& book) {
	bool loan_success = book.Loan(*this);
	if (!loan_success) return false;
	my_books.insert(&book);
	return true;
}

bool Borrower_t::Return(Book_t& book) {
	// Make sure that the borrower loaned the book
	BookSet_t::const_iterator it = my_books.find(&book);
	if (it == my_books.end()) return false;
	my_books.erase(&book);
	book.Return(*this);
	return true;
}

bool Borrower_t::HasLoans() const {
	return (!my_books.empty());
}

int Borrower_t::GetNextID() {
	return id_assign++;
}
