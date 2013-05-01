bool AppointmentTime_t::operator <(const AppointmentTime_t& rhs) const {
	return start + duration < rhs.start;
}
