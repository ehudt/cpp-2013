#include "Appointment_t.h"

Appointment_t::Appointment_t(AppointmentTime_t& time, string& subject) :
	appointmentTime(time),
	subject(subject)
{}


Appointment_t::Appointment_t(const Appointment_t& other) :
		appointmentTime(other.appointmentTime),
		subject(other.subject)
{}

Appointment_t::~Appointment_t(){}

Appointment_t& Appointment_t::operator= (const Appointment_t& appointment){
	if (*this != appointment){
		this->appointmentTime = appointment.appointmentTime;
		this->subject = appointment.subject;
	}
	return *this;
}


bool Appointment_t::operator== (const Appointment_t& appointment) const{
	return (this->appointmentTime == appointment.appointmentTime && this->subject == appointment.subject);
}

bool Appointment_t::operator!= (const Appointment_t& appointment) const{
	return !(*this == appointment);
}

const AppointmentTime_t& Appointment_t::getTime() const{
		return this->appointmentTime;
	}

const string& Appointment_t::getSubject() const{
	return this->subject;
}

ostream& operator <<(ostream& os, const Appointment_t& appointment) {
	os << "Subject: " << appointment.getSubject() << endl;
	return os << "Time: " << appointment.getTime() << endl;
}

void Appointment_t::setTime(const AppointmentTime_t& newTime){
	this->appointmentTime = newTime;
}
