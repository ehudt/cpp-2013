class StudentFactory {
public:
	static Student* Create(const string& type, const string& name) {
		Student* ptrStudent = 0;
  		if (type == "ESF")
			ptrStudent = new StudentESF(name);
  		if (type == "FOH")
			ptrStudent = new StudentFOH(name);
		return ptrStudent;
	}
public:
	StudentFactory();
	StudentFactory(const StudentFactory&);
	StudentFactory& operator=(const StudentFactory&);
};

