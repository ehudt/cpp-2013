CC = g++
CFLAGS = -Wall -Wextra -g


all : main.o test/dlist_test.o test/array_test.o
	${CC} ${CFLAGS} main.o test/dlist_test.o test/array_test.o -o container_example

clean :
	rm -f main.o test/dlist_test.o test/array_test.o dlist_test.o array_test.o

tests : test/dlist_test.cpp test/array_test.cpp Dlist_t.h Node_t.h Array_t.h Container_t.h
	${CC} ${CFLAGS} -c test/dlist_test.cpp
	${CC} ${CFLAGS} -c test/array_test.cpp

main.o : tests Dlist_t.h Node_t.h Array_t.h Container_t.h
	${CC} ${CFLAGS} -c main.cpp
