#ifndef _ARRAY_T_H
#define _ARRAY_T_H

#include "Container_t.h"

template <class T>
class Array_t : public Container_t<T>{
	public:
		virtual Array_t(); // Default CTOR
		virtual ~Array_t(); // Pure virtual DTOR
		virtual Array_t(const Array_t& array); // Copy CTOR
		virtual const Array_t& operator= (const Array_t& array); // Operator =
		virtual T& operator[] (int index); //TODO: const T& ?
		virtual int count() const;
		virtual T* find(T& element) const;
		virtual bool insert(T& element);
		virtual bool append(T& element, int index);
		virtual bool prepend(T& element, int index);
		virtual T* remove(T& element);
		virtual bool removeAndDelete(T& element);
		virtual bool removeAll();
		virtual bool removeAllAndDelete();

	private:
		T** array;
		static int initialSize;
		static int expandValue;
		int count_; // current number of elements in the array
		int capacity; // total capacity
};

int Array_t<class T>::initialSize = 16;
int Array_t<class T>::expandValue = 4;

Array_t<class T>::Array_t() :
	array(new T[initialSize]),
	count_(0),
	capacity(initialSize)
		{}

Array_t<class T>::~Array_t() {
	delete[] array;
}

Array_t<class T>::Array_t(const Array_t& array) :
	array(new T[array.capacity]),
	count_(array.count_),
	capacity(array.capacity)
{
	for (int i = 0; i < this->count_; ++i) {
		this[i] = array[i];
	}
}



#endif
