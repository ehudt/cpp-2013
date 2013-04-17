#ifndef _CONTAINER_T_H
#define _CONTAINER_T_H

template <class T>
class Container_t {
	public:
		virtual Container_t() = 0; // Default CTOR // TODO: pure virtual?
		virtual ~Container_t() = 0; // Pure virtual DTOR
		virtual Container_t(const Container_t<T>& container) = 0; // Copy CTOR
		virtual const Container_t& operator= (const Container_t<T>& container) = 0; // Operator =
		virtual int count() const = 0;
		virtual T* find(T& element) const = 0;
		virtual bool insert(T& element) = 0; // TODO: handle exceptions
		virtual bool append(T& element, int index) = 0; // TODO: handle exceptions
		virtual bool prepend(T& element, int index) = 0; // TODO: handle exceptions
		virtual T* remove(T& element) = 0;
		virtual bool removeAndDelete(T& element) = 0; // TODO: handle exceptions
		virtual bool removeAll() = 0; // TODO: handle exceptions
		virtual bool removeAllAndDelete() = 0; // TODO: handle exceptions
};

#endif
