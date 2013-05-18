#include "Library_t.h"

Library_t::Library_t() {
	// Empty
}

Library_t::~Library_t() {
	// Delete all books
	for (BookMap_t::iterator it = books.begin();
				it != books.end(); ++it) {
		Book_t* book_to_delete = it->second;
		delete (book_to_delete);
	}
	// Delete all borrowers
	for (BorrowerMap_t::iterator it = borrowers.begin();
			it != borrowers.end(); ++it) {
		Borrower_t* borrower_to_delete = it->second;
		delete (borrower_to_delete);
	}
}

bool Library_t::AddBook(const string& name, const string& author,
		const string& isbn, size_t copies) {
	BookMap_t::const_iterator it = books.find(isbn);
	if (it != books.end()) {
		// The book already exists
		return false;
//		const Book_t& existing_book = *it->second;
//		if (existing_book.GetName() != name
//				|| existing_book.GetAuthor() != author
//				|| existing_book.GetIsbn() != isbn) {
//			return false;
//		}
//		const_cast<Book_t&>(existing_book).available_copies += copies;
	} else {
		Book_t* new_book = new Book_t(isbn, name, author, copies);
		books.insert(pair<string, Book_t*>(isbn, new_book));
	}
	return true;
}

bool Library_t::RemoveBook(Book_t& book) {
	if (book.IsLoaned()) return false;
	BookMap_t::iterator it = books.find(book.GetIsbn());
	if (it == books.end()) return false;
	Book_t* book_to_remove = it->second;
	delete book_to_remove;
	books.erase(it);
	return true;
}

const Book_t* Library_t::SearchBook(const string& isbn) const {
	BookMap_t::const_iterator it = books.find(isbn);
	if (it == books.end()) return 0;
	return it->second;
}

int Library_t::AddBorrower(const string& name) {
	Borrower_t* new_borrower = new Borrower_t(name);
	int id = new_borrower->GetId();
	borrowers.insert(pair<int, Borrower_t*>(id, new_borrower));
	return id;
}

const Borrower_t* Library_t::SearchBorrower(int id) const {
	BorrowerMap_t::const_iterator it = borrowers.find(id);
	if (it == borrowers.end()) return 0;
	return it->second;
}

bool Library_t::RemoveBorrower(Borrower_t& borrower) {
	if (borrower.HasLoans()) return false;
	BorrowerMap_t::iterator it = borrowers.find(borrower.GetId());
	if (it == borrowers.end()) return false;
	Borrower_t* borrower_to_remove = it->second;
	delete borrower_to_remove;
	borrowers.erase(it);
	return true;
}

void Library_t::BookReport() const {
	cout << "Book report:" << endl;
	for (BookMap_t::const_iterator it = books.begin();
			it != books.end(); ++it) {
		cout << *it->second << endl;
	}
}

void Library_t::BorrowerReport() const {
	cout << "Borrower report:" << endl;
	for (BorrowerMap_t::const_iterator it = borrowers.begin();
			it != borrowers.end(); ++it) {
		cout << *it->second << endl;
	}
}
