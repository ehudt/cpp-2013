#include "memPool_t.h"
#include <string.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

memPool_t::memPool_t() :
	pageCount(1),
	size(0),
	capacity(memPage_t::getNewPageSize()),
	position(0),
	firstPage(new memPage_t),
	currentPage(firstPage)
{}

memPool_t::memPool_t(int initPageCount) :
	pageCount(initPageCount),
	size(0),
	capacity(initPageCount * memPage_t::getNewPageSize()),
	position(0),
	firstPage(new memPage_t),
	currentPage(firstPage)
{
	memPage_t* page = firstPage;
	for(int i = 0; i < initPageCount - 1; ++i) {
		page->setNext(new memPage_t);
		page = page->getNext();
	}
}

memPool_t::~memPool_t() {
	memPage_t* page = firstPage;
	while (page != NULL) {
		memPage_t* next = page->getNext();
		delete page;
		page = next;
	}
	currentPage = NULL;
}

int memPool_t::setPosition(int newPos) {
	if (newPos < 0 || newPos > size) return -1;
	int remPos = newPos;
	memPage_t* page = firstPage;
	while (remPos > page->getCapacity()) {
		remPos -= page->getCapacity();
		page = page->getNext();
	}
	currentPage = page;
	page->setPosition(remPos);
	position = newPos;
	return position;
}

int memPool_t::getPosition() const {
	return position;
}

bool memPool_t::isEmpty() const {
	return size == 0;
}

int memPool_t::getSize() const {
	return size;
}

int memPool_t::getCapacity() const {
	return capacity;
}

int memPool_t::getPageCount() const {
	return pageCount;
}

int memPool_t::getNewPageSize() {
	return memPage_t::getNewPageSize();
}

int memPool_t::setNewPageSize(int newSize) {
	return memPage_t::setNewPageSize(newSize);
}

int memPool_t::read(void * dst, int sizeToRead) {
	if (!dst || sizeToRead < 0) return -1;
	int actual = min(sizeToRead, size - position);
	int bytesLeft = actual;

	while (bytesLeft > 0) { // invariant: if currentPage == NULL then bytesLeft == 0
		if (currentPage->getPosition() == currentPage->getCapacity()) {
			currentPage = currentPage->getNext();
			if (!currentPage) break;
			currentPage->setPosition(0);
		}
		int bytesRead = currentPage->read(dst, bytesLeft);
		bytesLeft -= bytesRead;
		dst = (char *)dst + bytesRead;
		position += bytesRead;
	}
	return actual;
}

int memPool_t::read(void * dst, int sizeToRead, int offset) {
	int prevPos = position;
	if (setPosition(offset) < 0) return -1;
	int bytesRead = read(dst, sizeToRead);
	if (bytesRead < 0) {
		setPosition(prevPos);
	}
	return bytesRead;
}

int memPool_t::write(const void * src, int sizeToWrite) {
	if (!src || sizeToWrite < 0) return -1;
	int bytesLeft = sizeToWrite;
	while (bytesLeft > 0) {
		if (currentPage->getPosition() == currentPage->getCapacity()) {
			memPage_t *tmp;
			if ((tmp = currentPage->getNext()) != NULL) {
				currentPage = tmp;
				currentPage->setPosition(0);
			} else { // need to allocate new page
				currentPage->setNext(new memPage_t);
				currentPage = currentPage->getNext();
				capacity += getNewPageSize();
				pageCount++;
			}
		}
		int bytesWritten = currentPage->write(src, bytesLeft);
		bytesLeft -= bytesWritten;
		src = (char *)src + bytesWritten;
		position += bytesWritten;
	}
	size = max(size, position);
	return sizeToWrite;
}

int memPool_t::write(const void * src, int sizeToWrite, int offset) {
	int prevPos = position;
	if (setPosition(offset) < 0) return -1;
	int bytesWritten = write(src, sizeToWrite);
	if (bytesWritten < 0) {
		setPosition(prevPos);
	}
	return bytesWritten;
}