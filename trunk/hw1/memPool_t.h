class memPage_t {
	public: // member functions
		memPage_t(); // Default CTOR
		memPage_t(const int size); // CTOR with specific size
		~memPage_t();
		const int setPosition(const int offset); // Set the current position. Returns the new position or -1 on error
		const int getPosition() const; // Get the current position
		const bool isEmpty() const; 
		const bool isFull() const;
		const int getSize() const;
		const int getCapacity() const;
		const int read(void* const dst, const int size) const; // returns the number of bytes read or -1 on error
		const int read(void* const dst, const int size, const int offset) const; // returns the number of bytes read or -1 on error
		const int write(const void* const src, const int size); // returns the number of bytes written or -1 on error
		const int write(const void* const src, const int size, const int offset); // returns the number of bytes written or -1 on error

	private: //data members
		memPage_t(const memPage_t& memPage); // Copying memPage_t is not allowed
		static int maxSize;
		int size;	// Actual size of the memPage
		int capacity;	// memPage capacity	
		int position; // Current position
		memPage_t* next; // Pointer to the next page
};

class memPool_t {
	public: // member functions
		memPool_t(); // Default CTOR
		memPool_t(const int initPageCount); // CTOR from initial empty page count
		~memPool_t(); // DTOR
		const memPool_t& operator= (const memPool_t& memPool); // Overloading the assignment operator
		const int setPosition(const int offset); // Set the current position. Returns the new position or -1 on error
		const int getPosition() const; // Get the current position
		const bool isEmpty() const; 
		const int getSize() const;
		const int getCapacity() const;
		const int getPageCount() const;
		const int getPageSize() const;
		const int setPageSize(const int newSize);
		const int read(void * const dst, const int size) const; // returns the number of bytes read or -1 on error
		const int write(const void * const src, const int size); // returns the number of bytes written or -1 on error

	private: //data members
		memPool_t(const memPool_t& memPool); // Copying memPool_t is not allowed
		int pageSize; // Default size of page
		int pageCount;	// Page counter
		int size;	// Actual size of the memPool
		int capacity;	// memPool capacity
		int position;	// current position
		memPage_t* firstPage;
};