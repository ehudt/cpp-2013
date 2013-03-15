#include "memPage_t.h"

class memPool_t {
	public: // member functions
		memPool_t(); // Default CTOR
		memPool_t(int initPageCount); // CTOR from initial empty page count
		~memPool_t(); // DTOR
		int setPosition(int newPos); // Set the current position. Returns the new position or -1 on error
		int getPosition() const; // Get the current position
		bool isEmpty() const; 
		int getSize() const;
		int getCapacity() const;
		int getPageCount() const;
		static int getNewPageSize();
		static int setNewPageSize(int newSize);
		int read(void * dst, int sizeToRead); // returns the number of bytes read or -1 on error
		int read(void * dst, int sizeToRead, int offset);
		int write(const void * src, int sizeToWrite); // returns the number of bytes written or -1 on error
		int write(const void * src, int sizeToWrite, int offset);

	private: //data members
		memPool_t(const memPool_t& memPool); // Copying memPool_t is not allowed
		const memPool_t& operator= (const memPool_t& memPool); // Copying memPool_t is not allowed
		int pageCount;	// Page counter
		int size;	// Actual size of the memPool
		int capacity;	// memPool capacity
		int position;	// current position
		memPage_t* firstPage;
		memPage_t* currentPage;
};
