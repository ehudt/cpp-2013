
const int minute = 60;
const int hour = minute * 60;
const int day = hour * 24;

class AppointmentTime_t{
public:


	bool operator < (const AppointmentTime_t &rhs) const;

private:
	// time representation
	int start;
	int duration;
};
