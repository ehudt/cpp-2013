#ifndef _DLIST_T_H
#define _DLIST_T_H

template <class T>
class Dlist_t : public Container_t<T>{
	public:
		virtual Dlist_t(); // Default CTOR
		virtual ~Dlist_t(); // Pure virtual DTOR
		virtual Dlist_t(const Dlist_t& dlist); // Copy CTOR
		virtual const Dlist_t& operator= (const Dlist_t& dlist); // Operator =
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

};

#endif
