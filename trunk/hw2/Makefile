CC = g++
CFLAGS = -Wall -Wextra -g


all : main.o test/dlist_test.o
	${CC} ${CFLAGS} main.o test/dlist_test.o -o container_example

clean :
	rm main.o test/dlist_test.o

tests : test/dlist_test.cpp Dlist_t.h Node_t.h Container_t.h
	${CC} ${CFLAGS} -c test/dlist_test.cpp

main.o : test/dlist_test.o Dlist_t.h Node_t.h Array_t.h Container_t.h
	${CC} ${CFLAGS} -c main.cpp
