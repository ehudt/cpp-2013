#include "Book_t.h"

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
	if (available_copies == 0) return false;
	available_copies--;
	loaned_copies++;
	loans.insert(&loan_to);
	return true;
}

bool Book_t::Return(const Borrower_t& return_from) {
	// Make sure that the book is loaned out to this borrower
	BorrowerSet_t::const_iterator it = loans.find(&return_from);
	if (it == loans.end()) return false;
	// Return the book
	loans.erase(&return_from);
	available_copies++;
	loaned_copies--;
	return true;
}

bool Book_t::IsAvailable() const {
	return available_copies != 0;
}

bool Book_t::IsLoaned() const {
	return loaned_copies != 0;
}

void Book_t::AddCopies(size_t copies_to_add) {
	available_copies += copies_to_add;
}

void Book_t::AddToWaitingList(const Borrower_t& borrower) {
	waiting_list.push(&borrower);
}

const Borrower_t* Book_t::PopWaitingList() {
	if (WaitingListEmpty()) return 0;
	const Borrower_t* borrower = waiting_list.front();
	waiting_list.pop();
	return borrower;
}

bool Book_t::WaitingListEmpty() const {
	return waiting_list.empty();
}
