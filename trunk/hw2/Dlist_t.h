#ifndef _DLIST_T_H
#define _DLIST_T_H

#include "Container_t.h"
#include "Node_t.h"

template <class T>
class Dlist_t : public Container_t<T>{
	public:
		Dlist_t(); // Default CTOR
		virtual ~Dlist_t(); // DTOR
		Dlist_t(const Dlist_t<T>& dlist); // Copy CTOR
		const Dlist_t& operator= (const Dlist_t<T>& dlist); // Operator =
		int count() const;
		T* find(const T& element) const;
		bool insert(T& element);
		bool append(T& element, int index) throw(typename Container_t<T>::Error);
		bool prepend(T& element, int index) throw(typename Container_t<T>::Error);
		T* remove(const T& element);
		bool removeAndDelete(const T& element);
		void removeAll();
		void removeAllAndDelete();
		T* next();
		T* prev();
		void reset();


	private:
		Node_t<T>* getNodeByIndex(int index) const;
		Node_t<T>* getNode(const T& element) const;
		void insertAll(const Dlist_t<T>& dlist);
		Node_t<T>* getHead() const;
		Node_t<T>* getTail() const;
		Node_t<T>* getCurrent() const;
		void setCurrent(Node_t<T>* current);
		void removeAllExplicit(bool deleteAll);

		Node_t<T>* const head;
		Node_t<T>* const tail;
		Node_t<T>* current;
		int count_;
};

template <class T>
Dlist_t<T>::Dlist_t() : // default CTOR
	head(new Node_t<T>(0)),
	tail(new Node_t<T>(0)),
	current(head),
	count_(0)
{
	head->setNext(tail);
	tail->setPrev(head);
}

template <class T>
Dlist_t<T>::~Dlist_t() { // default DTOR
	removeAll();
	delete head;
	delete tail;
}

template <class T>
Dlist_t<T>::Dlist_t(const Dlist_t<T>& dlist) : // Copy CTOR
	head(new Node_t<T>(0)),
	tail(new Node_t<T>(0)),
	current(head),
	count_(0)
{
	head->setNext(tail);
	tail->setPrev(head);
	insertAll(dlist);
}

template <class T>
const Dlist_t<T>& Dlist_t<T>::operator= (const Dlist_t<T>& dlist) {
	if (this != &dlist) {
		removeAll();
		insertAll(dlist);
	}
	return *this;
}

template <class T>
Node_t<T>* Dlist_t<T>::getHead() const {
	return head;
}

template <class T>
Node_t<T>* Dlist_t<T>::getTail() const {
	return tail;
}

template <class T>
void Dlist_t<T>::insertAll(const Dlist_t<T>& dlist) {
	Node_t<T>* listCursor = dlist.getHead()->getNext();
	while (listCursor != dlist.getTail()) {
		T* ptr = listCursor->value();
		this->insert(*ptr);
		listCursor = listCursor->getNext();
	}
}


template<class T>
Node_t<T>* Dlist_t<T>::getNode(const T& element) const {
	Node_t<T>* listCursor = getHead()->getNext();
	while (listCursor != getTail()) {
		if (*listCursor->value() == element) {
			return listCursor;
		}
		listCursor = listCursor->getNext();
	}
	return 0;
}

template <class T>
Node_t<T>* Dlist_t<T>::getNodeByIndex(int index) const {
	Node_t<T>* listCursor = getHead()->getNext();
	while (index && listCursor != getTail()) {
		listCursor = listCursor->getNext();
		--index;
	}
	if (listCursor == getTail()) {
		return 0;
	}
	return listCursor;
}

template <class T>
inline Node_t<T>* Dlist_t<T>::getCurrent() const {
	return current;
}

template<class T>
inline int Dlist_t<T>::count() const {
	return count_;
}

template<class T>
inline T* Dlist_t<T>::find(const T& element) const {
	Node_t<T>* node = getNode(element);
	if (node) {
		return node->value();
	} else {
		return 0;
	}
}

template<class T>
inline bool Dlist_t<T>::insert(T& element) {
	Node_t<T>* newNode = new Node_t<T>(element);
	Node_t<T>* lastNode = getTail()->getPrev();
	lastNode->setNext(newNode);
	newNode->setPrev(lastNode);
	newNode->setNext(getTail());
	getTail()->setPrev(newNode);
	++count_;
	return true;
}

template<class T>
inline bool Dlist_t<T>::append(T& element, int index) throw(typename Container_t<T>::Error) {
	Node_t<T>* cursor = getNodeByIndex(index);
	if (!cursor) {
		throw Container_t<T>::IndexOutOfBounds;
	}
	Node_t<T>* newNode = new Node_t<T>(element);
	Node_t<T>* nextNode = cursor->getNext();
	cursor->setNext(newNode);
	newNode->setPrev(cursor);
	newNode->setNext(nextNode);
	nextNode->setPrev(newNode);
	++count_;
	return true;
}

template<class T>
inline bool Dlist_t<T>::prepend(T& element, int index) throw(typename Container_t<T>::Error) {
	Node_t<T>* cursor = getNodeByIndex(index);
		if (!cursor) {
			throw Container_t<T>::IndexOutOfBounds;
		}
		Node_t<T>* newNode = new Node_t<T>(element);
		Node_t<T>* prevNode = cursor->getPrev();
		prevNode->setNext(newNode);
		newNode->setPrev(prevNode);
		newNode->setNext(cursor);
		cursor->setPrev(newNode);
		++count_;
		return true;
}

template <class T>
static void removeNode(Node_t<T>* node) {
	node->getPrev()->setNext(node->getNext());
	node->getNext()->setPrev(node->getPrev());
	delete node;
}

template <class T>
inline T* Dlist_t<T>::remove(const T& element) {
	Node_t<T>* nodeToRemove = getNode(element);
	if (!nodeToRemove) {
		return 0;
	}
	T* elementPtr = nodeToRemove->value();
	removeNode(nodeToRemove);
	--count_;
	reset();
	return elementPtr;
}

template<class T>
inline bool Dlist_t<T>::removeAndDelete(const T& element) {
	T* elementToDelete = remove(element);
	if (!elementToDelete) {
		return false;
	}
	delete elementToDelete;
	reset();
	return true;
}


template<class T>
inline void Dlist_t<T>::removeAllExplicit(bool deleteAll) {
	Node_t<T>* listCursor = getHead()->getNext();
	while (listCursor != getTail()) {
		Node_t<T>* tmp = listCursor;
		listCursor = listCursor->getNext();
		if (deleteAll) {
			delete tmp->value();
		}
		removeNode(tmp);
	}
	count_ = 0;
	reset();
}
template<class T>
inline void Dlist_t<T>::removeAll() {
	removeAllExplicit(false);
}

template<class T>
inline void Dlist_t<T>::removeAllAndDelete() {
	removeAllExplicit(true);
}

template<class T>
inline T* Dlist_t<T>::next() {
	if (current != getTail()){
		current = current->getNext();
	}
	return current->value();
}

template<class T>
inline T* Dlist_t<T>::prev() {
	if (current != getHead()) {
		current = current->getPrev();
	}
	return current->value();
}

template<class T>
inline void Dlist_t<T>::reset() {
	setCurrent(head);
}

template <class T>
inline void Dlist_t<T>::setCurrent(Node_t<T>* current) {
	this->current = current;
}

#endif
