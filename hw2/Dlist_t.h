#ifndef _DLIST_T_H
#define _DLIST_T_H

template <class T>
class Dlist_t : public Container_t<T>{
	public:
		virtual Dlist_t(); // Default CTOR
		virtual ~Dlist_t(); // DTOR
		virtual Dlist_t(const Dlist_t<T>& dlist); // Copy CTOR
		virtual const Dlist_t& operator= (const Dlist_t<T>& dlist); // Operator =
		virtual int count() const;
		virtual T* find(T& element) const;
		virtual bool insert(T& element);
		virtual bool append(T& element, int index);
		virtual bool prepend(T& element, int index);
		virtual T* remove(T& element);
		virtual bool removeAndDelete(T& element);
		virtual bool removeAll();
		virtual bool removeAllAndDelete();
		virtual T* next();
		virtual T* prev();
		virtual void reset();

	private:
		const Node_t<T>* const head;
		const Node_t<T>* const tail;
		Node_t<T>* current;
		int count_;
};

template <class T>
Dlist_t<T>::Dlist_t() : // default CTOR
	head(new Node_t(0)),
	tail(new Node_t(0)),
	current(head),
	count_(0)
{
	head->setNext(tail);
	tail->setPrev(head);
}

template <class T>
Dlist_t<T>::~Dlist_t() { // default DTOR
	Node_t<T>* cursor = head;
	while(cursor) {
		Node_t<T>* tmp = cursor;
		cursor = cursor->getNext();
		delete cursor;
	}
}

template <class T>
Dlist_t<T>::Dlist_t(const Dlist_t<T>& dlist) : // Copy CTOR
	head(new Node_t(0)),
	tail(new Node_t(0)),
	current(head),
	count_(0)
{ // TODO conserve the current pointer in dlist and in this
	head->setNext(tail);
	tail->setPrev(head);
	if (dlist.count()) {
		T* ptr = dlist.next();
		while (ptr) {
			this->insert(*ptr);
			ptr = dlist.next();
		}
	}
}

template <class T>
const Dlist_t& Dlist_t<T>::operator= (const Dlist_t<T>& dlist) {
	if (*this != dlist) {
		removeAll();
		// TODO insert all dlist items into this
	}
}

#endif
