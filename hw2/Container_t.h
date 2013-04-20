#ifndef _CONTAINER_T_H
#define _CONTAINER_T_H

template <class T>
class Container_t {
public:
	enum Error {
		IndexOutOfBounds,
	};
	Container_t() {}; // Default CTOR
	virtual ~Container_t() = 0; // Pure virtual DTOR
	//virtual Container_t(const Container_t<T>& container) = 0; // Copy CTOR
	//virtual const Container_t& operator= (const Container_t<T>& container) = 0; // Operator =
	virtual int count() const = 0;
	virtual T* find(const T& element) const = 0;
	virtual bool insert(const T& element) = 0; // TODO: handle exceptions
	virtual bool append(const T& element, int index) throw(Error) = 0; // TODO: handle exceptions
	virtual bool prepend(const T& element, int index) throw(Error) = 0; // TODO: handle exceptions
	virtual T* remove(const T& element) = 0;
	virtual bool removeAndDelete(const T& element) = 0; // TODO: handle exceptions
	virtual bool removeAll() = 0; // TODO: handle exceptions
	virtual bool removeAllAndDelete() = 0; // TODO: handle exceptions
};

#endif
