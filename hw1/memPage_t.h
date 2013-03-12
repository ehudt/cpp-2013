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

