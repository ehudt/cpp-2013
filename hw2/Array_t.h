#ifndef _ARRAY_T_H
#define _ARRAY_T_H

#include "Container_t.h"
#include <exception>
#include <stddef.h>

template <class T>
class Array_t : public Container_t<T> {
	public:
		Array_t(); // Default CTOR
		~Array_t(); // Pure virtual DTOR
		Array_t(const Array_t<T>& array); // Copy CTOR
		const Array_t& operator= (const Array_t<T>& array); // Operator =
		T& operator[] (int index) const;
		int count() const;
		T* find(const T& element) const;
		bool insert(T& element);
		bool append(T& element, int index) throw(typename Container_t<T>::Error);
		bool prepend(T& element, int index) throw(typename Container_t<T>::Error);
		T* remove(const T& element);
		bool removeAndDelete(const T& element);
		bool removeAll();
		bool removeAllAndDelete();

	private:
		T** array;
		static int initialSize;
		static int expandValue;
		int count_; // current number of elements in the array
		int capacity; // total capacity
};


template <class T>
int Array_t<T>::initialSize = 16;

template <class T>
int Array_t<T>::expandValue = 4;

template <class T>
Array_t<T>::Array_t() :
	array(new T[initialSize]),
	count_(0),
	capacity(initialSize)
		{}

template <class T>
Array_t<T>::~Array_t() {
	delete[] array;
}

template <class T>
Array_t<T>::Array_t(const Array_t& existingArray) :
	array(new T[existingArray.capacity]),
	count_(existingArray.count_),
	capacity(existingArray.capacity)
{
	for (int i = 0; i < this->count_; ++i) {
		this[i] = existingArray[i];
	}
}

template <class T>
const Array_t<T>& Array_t<T>::operator =(const Array_t& existingArray) {
	if (&existingArray != this) {
		delete[] this->array;
		this->array = new T[existingArray.capacity];
		this->count_ = existingArray.count;
		this->capacity = existingArray.capacity;
	}
	return *this;
}

template <class T>
T& Array_t<T>::operator [](int index) const{
	if (index < 0 || index >= count()) throw Container_t<T>::IndexOutOfBounds;
	return *(array[index]);
}

template <class T>
int Array_t<T>::count() const{
	return this->count_;
}

template <class T>
T* Array_t<T>::find(const T& element) const{
	for (int i=0; i < this->count(); i++){
		if (*(this[i]) == element) {
			return this[i];
		}
	}
	return NULL;
}

template <class T>
bool Array_t<T>::insert(T& element){
	if (this->capacity > this->count()) {
		this[count] = &element;
		this->count_++;
		return 1;
	}
	else {
		T** temp = new T[this->capacity + expandValue];
		for (int i=0; i < this->capacity; i++){
			temp[i] = this->array[i];
		}

		this->capacity += expandValue;
		this->array = temp;
		delete[] temp;
		this[count] = &element;
		this->count_++;
		return 1;
	}
	return 0;
}

template <class T>
bool Array_t<T>::append(T& element, int index) throw(typename Container_t<T>::Error){
	if (index > this->count() || index < 0) throw Container_t<T>::IndexOutOfBounds;
		else {
			if (index == this->count()){
				return this->insert(element);
			}
			else{
				T** temp;
				if (this->count()+1 > this->capacity){
					temp = new T[this->capacity+expandValue];
					this->capacity = capacity+expandValue;
				}
				else
					temp = new T[this->capacity];

				for (int i=0; i < index+1; i++)
					temp[i] = this->array[i];

				temp[index+1] = &element;

				for (int i = index+1; i < this->count()+1; i++)
					temp[i+1] = this->array[i];
				this->count_++;
				this->array = temp;
				delete[] temp;
				return 1;
				}
			}
		}



template <class T>
bool Array_t<T>::prepend(T& element, int index) throw(typename Container_t<T>::Error){
	if (index > this->count() || index < 0) throw Container_t<T>::Error;
	else {
		if (index == this->count()){
			T* t = this->array[index];
			this->array[index] = &element;
			return this->insert(*t);
		}
		else{
			T** temp;
			if (this->count()+1 > this->capacity){
				temp = new T[this->capacity+expandValue];
				this->capacity = capacity+expandValue;
			}
			else
				temp = new T[this->capacity];


			for (int i=0; i < index; i++)
				temp[i] = this->array[i];

			temp[index] = &element;

			for (int i = index; i < this->count()+1; i++)
				temp[i+1] = this->array[i];
			this->count_++;
			this->array = temp;
			delete[] temp;
			return 1;
			}
		}
	}

template <class T>
T* Array_t<T>::remove(const T& element){
	int i = 0;
	while ((*(this->array[i]) != element) && (i < capacity+1)) {
		i++;
		}

	if (i == this->capacity+1) return NULL;

	T* elementPointer = this->array[i];

	for (int j=i; j< this->capacity; j++){
		this->array[j] = this->array[j+1];
	}
	this->count_--;

	return elementPointer;
}

template <class T>
bool Array_t<T>::removeAndDelete(const T& element){
	delete remove(element);
	return 1;
}

template <class T>
bool Array_t<T>::removeAll(){
	for (int i=0; i < this->count(); i++){
		this->array[i] = NULL;
	}

	this->count_ = 0;
	return 1;
}

template <class T>
bool Array_t<T>::removeAllAndDelete(){
	for (int i = 0; i < this->count(); i++){
		delete this->array[i];
		this->array[i] = NULL;
	}

	this->count_ = 0;
	return 1;
}



#endif
