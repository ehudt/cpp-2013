CC = g++
CFLAGS = -Wall -Wextra -g
BIN_NAME = University_demo

all: program tests
	
program: main.o University.o StudentFactory.o Student.o StudentImpl.o Subject.o StudentESF.o StudentFOH.o
	${CC} ${CFLAGS}  main.o University.o StudentFactory.o Student.o StudentImpl.o Subject.o StudentESF.o StudentFOH.o -o ${BIN_NAME}

tests: StudentFactory_test

clean:
	rm -f *.o ${BIN_NAME} *.gch
	
main.o: main.cpp
	${CC} ${CFLAGS} -c main.cpp

University.o: University.h University.cpp Subject.h Student.h
	${CC} ${CFLAGS} -c University.h University.cpp 
	
Subject.o: Subject.h Subject.cpp Observer.h
	${CC} ${CFLAGS} -c Subject.h Subject.cpp

Observer.o: Observer.h
	${CC} ${CFLAGS} -c Observer.h 
		
Student.o: Student.h Student.cpp Observer.h StudentFactory.h University.h
	${CC} ${CFLAGS} -c Student.h Student.cpp 

StudentImpl.o: StudentImpl.h StudentImpl.cpp Observer.h University.h
	${CC} ${CFLAGS} -c StudentImpl.h StudentImpl.cpp 

StudentESF.o: StudentESF.h StudentESF.cpp StudentImpl.h
	${CC} ${CFLAGS} -c StudentESF.h StudentESF.cpp

StudentFOH.o: StudentFOH.h StudentFOH.cpp StudentImpl.h
	${CC} ${CFLAGS} -c StudentFOH.h StudentFOH.cpp

StudentFactory_test: StudentFactory_test.o StudentFactory.o StudentESF.o StudentFOH.o
	${CC} ${CFLAGS} StudentFactory_test.o StudentFactory.o StudentESF.o StudentFOH.o -o StudentFactory_test

StudentFactory_test.o: StudentFactory_test.cpp StudentFactory.h University.h
	${CC} ${CFLAGS} -c StudentFactory_test.cpp	
