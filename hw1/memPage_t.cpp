#include "memPage_t.h"
#include <string.h>

memPage_t::maxCapacity = 1024;

memPage_t::memPage_t():
	size(0),
	capacity(maxCapacity),
	position(0),
	next(NULL),
	buffer(*(new char[maxCapacity])) {}

memPage_t::memPage_t(const int capacity):
	size(0),
	capacity(capacity),
	position(0),
	next(NULL),
	buffer(*(new char[capacity])) {}	

memPage_t::~memPage_t() { 
	delete[] &buffer;
}

int memPage_t::setPosition(const int newPos){
	if (newPos < 0 || newPos > size) return -1;
	position = newPos;
	return position;
}

int memPage_t::getPosition(){
	return position;
}

bool memPage_t::isEmpty(){
	return (size==0);
}

bool memPage_t::isFull(){
	return (size==capacity);
}

int memPage_t::getSize(){
	return size;
}

int memPage_t::getCapacity(){
	return capacity;
}

int memPage_t::read(void* const dst, const int sizeToRead, const int offset){
	if (!dst || sizeToRead <= 0 || offset < 0 || offset >= size) return -1;
	int actual;
	actual = min(size-offset, sizeToRead);
	memcpy(dst, buffer+offset, actual);
	return actual;
}

int memPage_t::read(void* const dst, const int sizeToRead){
	int actual;
	actual = read(dst, sizeToRead, position);
	if (actual != -1) position += actual;
	return actual;
}

int memPage_t::write(const void* const src, const int sizeToWrite, const int offset){
	if (!src || sizeToWrite <= 0 || offset < 0 || offset > size) return -1;
	int actual;
	actual = min(sizeToWrite, capacity-offset);
	memcpy(buffer+offset, src, actual);
	return actual;
}

int memPage_t::write(const void* const src, const int sizeToWrite){
	int actual;
	actual = write(src, sizeToWrite, position);
	if (actual != -1) position += actual;
	return actual;
}

void memPage_t::setNext(const memPage_t* const next){
	this.next = next;
}

const memPage_t* memPage_t::getNext(){
	return next;
}
