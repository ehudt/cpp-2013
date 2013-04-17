#ifndef _NODE_T_H
#define _NODE_T_H

template <class T>
class Node_t {
	public:
		Node_t(T& value); // CTOR from T reference
		Node_t(T* valuePtr); // CTOR form T pointer
		// ~Node_t(); // Default DTOR
		Node_t(const Node_t& existingNode); // Copy CTOR - only copies pointer to element. prev and next are set to zero
		const Node_t& operator= (const Node_t& existingNode); // operator= - same behaviour as copy CTOR
		T* value() const;
		Node_t& getNext();
		void setNext(Node_t* node);
		Node_t& getPrev();
		void setPrev(Node_t* node);

	private:
		T* valuePtr;
		Node_t* prev;
		Node_t* next;
};

template <class T>
Node_t<T>::Node_t(T& value) :
	valuePtr(&value),
	prev(0),
	next(0)
	{}

template <class T>
Node_t<T>::Node_t(T* value) :
	valuePtr(valuePtr),
	prev(0),
	next(0)
	{}

template <class T>
Node_t<T>::Node_t(const Node_t& existingNode) :
	valuePtr(existingNode.valuePtr),
	prev(0),
	next(0)
{}

template <class T>
const Node_t& Node_t<T>::operator =(const Node_t& existingNode) {
	if (*this != existingNode) {
		valuePtr = existingNode.valuePtr;
		next = 0;
		prev = 0;
	}
	return *this;
}

template <class T>
T* Node_t<T>::value() const {
	return valuePtr;
}

template <class T>
Node_t& Node_t<T>::getNext() {
	return next;
}

template <class T>
void Node_t<T>::setNext(Node_t* node) {
	next = node;
}

template <class T>
Node_t& Node_t<T>::getPrev() {
	return prev;
}

template <class T>
void Node_t<T>::setPrev(Node_t* node) {
	prev = node;
}
