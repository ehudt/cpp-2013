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

	virtual int count() const = 0;
	virtual T* find(const T& element) const = 0;
	virtual bool insert(T& element) = 0;
	virtual bool append(T& element, int index) throw(Error) = 0;
	virtual bool prepend(T& element, int index) throw(Error) = 0;
	virtual T* remove(const T& element) = 0;
	virtual bool removeAndDelete(const T& element) = 0;
	virtual void removeAll() = 0;
	virtual void removeAllAndDelete() = 0;
};

template <class T>
Container_t<T>::~Container_t() {}

#endif
