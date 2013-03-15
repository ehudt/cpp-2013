class memPage_t {

	//TODO: assignment operator? 
	// We need to make it private (ehud)
	
	public: // member functions
		memPage_t(); // Default CTOR
		~memPage_t();
		int setPosition(int newPos); // Set the current position. Returns the new position or -1 on error.
		int getPosition() const; // Get the current position
		bool isEmpty() const; 
		bool isFull() const;
		int getSize() const;
		int getCapacity() const;
		int read(void* const dst, int sizeToRead, int offset); // returns the number of bytes read or -1 on error
		int read(void* const dst, int sizeToRead); // returns the number of bytes read or -1 on error
		int write(const void* const src, int sizeToWrite); // returns the number of bytes written or -1 on error
		int write(const void* const src, int sizeToWrite, int offset); // returns the number of bytes written or -1 on error
		void setNext(memPage_t* const next);
		const memPage_t* getNext() const;
		static int setNewPageSize(int newSize); // Static method to change the default size for new pages

	private: //data members
		memPage_t(const memPage_t& memPage); // Copying memPage_t is not allowed
		const memPage_t& operator= (const memPage_t& mp);
		static int newPageSize;
		int size;	// Actual size of the memPage
		int capacity;	// memPage capacity	
		int position; // Current position
		char* const buffer;
		memPage_t* next; // Pointer to the next page
};

