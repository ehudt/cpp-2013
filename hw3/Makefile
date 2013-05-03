CC = g++
CFLAGS = -Wall -Wextra -g

all : main.o AppointmentTime_t.o Appointment_t.o AppointmentDiary_t.o AppointmentDiaryTest.o AppointmentTimeTest.o 
	${CC} ${CFLAGS} main.o AppointmentTime_t.o Appointment_t.o AppointmentDiary_t.o AppointmentDiaryTest.o AppointmentTimeTest.o -o diary

clean :
	rm -f main.o AppointmentTime_t.o Appointment_t.o AppointmentDiary_t.o AppointmentDiaryTest.o AppointmentTimeTest.o

AppointmentTimeTest.o : AppointmentTime_t.h
	${CC} ${CFLAGS} -c AppointmentTimeTest.cpp

AppointmentDiaryTest.o : AppointmentDiary_t.h
	${CC} ${CFLAGS} -c AppointmentDiaryTest.cpp

AppointmentTime_t.o : AppointmentTime_t.h AppointmentTime_t.cpp


main.o : AppointmentDiary_t.h Appointment_t.h AppointmentTime_t.h
	${CC} ${CFLAGS} -c main.cpp
