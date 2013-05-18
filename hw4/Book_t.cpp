#include "Book_t.h"

ostream& operator <<(ostream& os, const Book_t& book) {
	os << book.author << ", " << book.name << ". ISBN: " << book.isbn << endl;
	os << "This book is loaned out to: ";
	bool first = true;
	for (BorrowerSet_t::const_iterator it = book.loans.begin();
			it != book.loans.end(); ++it) {
		if (!first) os << ", ";
		first = false;
		const Borrower_t& borrower = *(*it);
		os << borrower.GetName() << " (" << borrower.GetId() << ")";
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
			loaned_copies(0) {
	// Empty
}

Book_t::~Book_t() {
	// Empty
}

bool Book_t::Loan(const Borrower_t& loan_to) {
	if (available_copies != 0) {
		available_copies--;
		loaned_copies++;
		loans.insert(&loan_to);
		return true;
	} else {
		waiting_list.push(&loan_to);
		return false;
	}
}

bool Book_t::Return(const Borrower_t& return_from) {
	// Make sure that the book is loaned out to this borrower
	BorrowerSet_t::const_iterator it = loans.find(&return_from);
	if (it == loans.end()) return false;
	// Return the book
	loans.erase(&return_from);
	available_copies++;
	loaned_copies--;
	// Check the waiting list
	if (!waiting_list.empty()) {
		Borrower_t* next_loan = const_cast<Borrower_t*>(waiting_list.front());
		waiting_list.pop();
		Loan(*next_loan);
		next_loan->Loan(*this);
	}
	return true;
}

bool Book_t::IsAvailable() const {
	return available_copies != 0;
}

bool Book_t::operator <(Book_t& rhs) const {
	return name < rhs.name;
}

bool Book_t::IsLoaned() const {
	return loaned_copies != 0;
}
