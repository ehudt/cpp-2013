#include "memPage_t.h"
#include <string.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

int memPage_t::newPageSize = 1024;

memPage_t::memPage_t():
	size(0),
	capacity(newPageSize),
	position(0),
	next(NULL),
	buffer(new char[newPageSize]) {}

memPage_t::~memPage_t() { 
	delete[] buffer;
}

int memPage_t::setPosition(int newPos){
	if (newPos < 0 || newPos > size) return -1;
	position = newPos;
	return position;
}

int memPage_t::getPosition() const {
	return position;
}

bool memPage_t::isEmpty() const {
	return (size==0);
}

bool memPage_t::isFull() const {
	return (size==capacity);
}

int memPage_t::getSize() const {
	return size;
}

const int memPage_t::getCapacity() const {
	return capacity;
}

int memPage_t::read(void* const dst, int sizeToRead) {
	if (!dst || sizeToRead < 0) return -1;
	int actual;
	actual = min(sizeToRead, size-position);
	memcpy(dst, buffer+position, actual);
	setPosition(position+actual);
	return actual;
}

int memPage_t::read(void* const dst, int sizeToRead, int offset) {
	int prevPos = position;
	if (setPosition(offset) < 0) return -1;
	int bytesRead;
	bytesRead = read(dst, sizeToRead);
	if (bytesRead < 0){
		setPosition(prevPos);
	}
	return bytesRead;
}

int memPage_t::write(const void* const src, int sizeToWrite){
	if (!src || sizeToWrite < 0) return -1;
	int actual;
	actual = min(sizeToWrite, capacity-position);
	memcpy(buffer + position, src, actual);
	size = max(size, position + actual);
	setPosition(position + actual);
	
	return actual;
}

int memPage_t::write(const void* const src, int sizeToWrite, int offset){
	int prevPos = position;
	if (setPosition(offset) < 0) return -1;
	int bytesWritten;
	bytesWritten = write(src, sizeToWrite);
	if (bytesWritten < 0){
		setPosition(prevPos);
	}
	return bytesWritten;
}

void memPage_t::setNext(memPage_t* const newNext){
	next = newNext;
}

memPage_t* memPage_t::getNext() const{
	return next;
}

int memPage_t::setNewPageSize(int newSize){
	if (newSize <= 0) return -1;
	newPageSize = newSize;
	return newPageSize;
}

int memPage_t::getNewPageSize() {
	return newPageSize;
}