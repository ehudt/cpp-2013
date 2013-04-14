template <class T>
class Container_t {
	public:
		Container_t(); // Default CTOR
		~Container_t(); // DTOR
		Container_t(const Container_t& container); // Copy CTOR
		const Container_t& operator= (const Container_t& container); // Operatot =
		int count() const;
		T* find(T& element) const;
		bool insert(T& element); // TODO: handle exceptions
		bool append(T& element, int index); // TODO: handle exceptions
		bool prepend(T& element, int index); // TODO: handle exceptions
		T* remove(T& element);
		bool removeAndDelete(T& element); // TODO: handle exceptions
		bool removeAll(); // TODO: handle exceptions
		bool removeAllAndDelete(); // TODO: handle exceptions

};
