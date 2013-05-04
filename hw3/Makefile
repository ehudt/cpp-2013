CC = g++
CFLAGS = -Wall -Wextra -g

all : main.o AppointmentTime_t.o Appointment_t.o Day_t.o AppointmentDiary_t.o AppointmentDiaryTest.o AppointmentTest.o AppointmentTimeTest.o DayTest.o 
	${CC} ${CFLAGS} main.o AppointmentTime_t.o Appointment_t.o AppointmentDiary_t.o AppointmentDiaryTest.o AppointmentTest.o AppointmentTimeTest.o Day_t.o DayTest.o -o diary

clean :
	rm -f main.o AppointmentTime_t.o Appointment_t.o AppointmentDiary_t.o AppointmentDiaryTest.o AppointmentTimeTest.o AppointmentTest.o DayTest.o Day_t.o

AppointmentTimeTest.o : AppointmentTime_t.h
	${CC} ${CFLAGS} -c AppointmentTimeTest.cpp

AppointmentTest.o : Appointment_t.h AppointmentTime_t.h
	${CC} ${CFLAGS} -c AppointmentTest.cpp
	
DayTest.o : Day_t.h Appointment_t.h AppointmentTime_t.h
	${CC} ${CFLAGS} -c DayTest.cpp

AppointmentDiaryTest.o : AppointmentDiary_t.h AppointmentTime_t.h Appointment_t.h
	${CC} ${CFLAGS} -c AppointmentDiaryTest.cpp

AppointmentTime_t.o : AppointmentTime_t.h AppointmentTime_t.cpp
	${CC} ${CFLAGS} -c AppointmentTime_t.cpp

Appointment_t.o : Appointment_t.h AppointmentTime_t.h Appointment_t.cpp
	${CC} ${CFLAGS} -c Appointment_t.cpp
	
Day_t.o : Day_t.h Appointment_t.h AppointmentTime_t.h Day_t.cpp
	${CC} ${CFLAGS} -c Day_t.cpp

AppointmentDiary_t.o : AppointmentDiary_t.h Appointment_t.h AppointmentTime_t.h AppointmentDiary_t.cpp
	${CC} ${CFLAGS} -c AppointmentDiary_t.cpp
	
main.o : AppointmentDiary_t.h Appointment_t.h AppointmentTime_t.h Day_t.h
	${CC} ${CFLAGS} -c main.cpp
