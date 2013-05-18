CC = g++
CFLAGS = -Wall -Wextra -g
BIN_NAME = library_demo

all: main.o Library_t.o Borrower_t.o Book_t.o
	${CC} ${CFLAGS} main.o Library_t.o Borrower_t.o Book_t.o -o ${BIN_NAME}

clean:
	rm -f main.o Library_t.o Borrower_t.o Book_t.o *.gch

main.o: main.cpp
	${CC} ${CFLAGS} -c main.cpp

Library_t.o: Library_t.h Library_t.cpp Book_t.h Borrower_t.h
	${CC} ${CFLAGS} -c Library_t.cpp Library_t.h Book_t.h Borrower_t.h

Borrower_t.o: Borrower_t.h Book_t.h Borrower_t.cpp
	${CC} ${CFLAGS} -c Borrower_t.cpp Borrower_t.h Book_t.h

Book_t.o: Book_t.h Book_t.cpp
	${CC} ${CFLAGS} -c Book_t.cpp Book_t.h Borrower_t.h

BookTest: BookTest.o Book_t.o Borrower_t.o
	${CC} ${CFLAGS} BookTest.o Book_t.o Borrower_t.o -o BookTest

BookTest.o: BookTest.cpp Book_t.h Borrower_t.h
	${CC} ${CFLAGS} -c BookTest.cpp

BorrowerTest: BorrowerTest.o Book_t.o Borrower_t.o
	${CC} ${CFLAGS} BorrowerTest.o Book_t.o Borrower_t.o -o BorrowerTest

BorrowerTest.o: BorrowerTest.cpp Book_t.h Borrower_t.h
	${CC} ${CFLAGS} -c BorrowerTest.cpp