CC = g++
CFLAGS = -Wall -Wextra -g
BIN_NAME = University_demo

all: program tests
	
program: main.o University.o StudentFactory.o Student.o StudentImpl.o Subject.o Observer.o
	${CC} ${CFLAGS}  main.o University.o StudentFactory.o Student.o StudentImpl.o -o ${BIN_NAME}


clean:
	rm -f main.o University.o StudentFactory.o Student.o StudentImpl.o ${BIN_NAME} *.gch
	
main.o: main.cpp
	${CC} ${CFLAGS} -c main.cpp


Subject.o: Subject.h Subject.cpp
	${CC} ${CFLAGS} -c Subject.h Subject.cpp
	
University.o: University.h University.cpp Subject.h Student.h
	${CC} ${CFLAGS} -c University.h University.cpp 

Student.o: Student.h Student.cpp Observer.h StudentFactory.h
	${CC} ${CFLAGS} -c Student.h Student.cpp 

StudentImpl.o: StudentImpl.h StudentImpl.cpp Observer.h University.h
	${CC} ${CFLAGS} -c StudentImpl.h StudentImpl.cpp 

StudentESF.o: StudentESF.h StudentESF.cpp StudentImpl.h
	${CC} ${CFLAGS} -c StudentESF.h StudentESF.cpp

StudentFOH.o: StudentFOH.h StudentFOH.cpp StudentImpl.h
	${CC} ${CFLAGS} -c StudentFOH.h StudentFOH.cpp

Observer.o: Observer.h Observer.cpp
	${CC} ${CFLAGS} -c Observer.h Observer.cpp