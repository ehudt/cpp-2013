class memPage_t {

	//TODO: assignment operator?
	
	public: // member functions
		memPage_t(); // Default CTOR
		memPage_t(const int capacity); // CTOR with specific capacity
		~memPage_t();
		const int setPosition(const int newPos); // Set the current position. Returns the new position or -1 on error
		const int getPosition() const; // Get the current position
		const bool isEmpty() const; 
		const bool isFull() const;
		const int getSize() const;
		const int getCapacity() const;
		const int read(void* const dst, const int sizeToRead, const int offset) const; // returns the number of bytes read or -1 on error
		const int read(void* const dst, const int sizeToRead) const; // returns the number of bytes read or -1 on error
		const int write(const void* const src, const int sizeToWrite); // returns the number of bytes written or -1 on error
		const int write(const void* const src, const int sizeToWrite, const int offset); // returns the number of bytes written or -1 on error
		void setNext(const memPage_t* const next);
		const memPage_t* getNext() const;

	private: //data members
		memPage_t(const memPage_t& memPage); // Copying memPage_t is not allowed
		static int maxCapacity;
		int size;	// Actual size of the memPage
		int capacity;	// memPage capacity	
		int position; // Current position
		char[]& buffer;
		memPage_t* next; // Pointer to the next page
};

