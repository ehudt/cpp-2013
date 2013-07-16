#include <map>
#include <iostream>
#include <string> 

using namespace std;
#define print(c) do { cout << c << endl; } while(0)


template <class CID>
class Course_t {
public:
	Course_t(CID id) : id(id) {}
	Course_t(const Course_t& other) : id(other.id) {}
	virtual ~Course_t() {}
	Course_t& operator = (const Course_t& rhs) {
		if (this != &rhs) {
			id = rhs.id;
		}
		return *this;
	}

	void setCourseID (const CID& new_id) {
		id = new_id;
	}

	const CID& getCourseID () const {
		return id;
	}


private:
	CID id;
};

template <class FID, class CID>
class Faculty_t {
public:
	Faculty_t(FID id) : id(id) {}
	Faculty_t(const Faculty_t& other) : id(other.id), courses(other.courses) {}
	virtual ~Faculty_t() {}
	Faculty_t& operator = (const Faculty_t& rhs) {
		if (this != &rhs) {
			id = rhs.id;
			courses = rhs.courses;
		}
		return *this;
	}

	void setFacultyID (const FID& new_id) {
		id = new_id;
	}

	const FID& getFacultyID () const {
		return id;
	}

	void addCourse(Course_t<CID>* course) {
		courses.insert(make_pair(course->getCourseID(), course));
	}

	const Course_t<CID>* getCourse(const CID& course_id) const {
		typename CourseContainer::const_iterator it = courses.find(course_id);
		if (it != courses.end()) {
			return it->second;
		} else {
			return 0;
		}
	}
private:
	FID id;
	typedef map<CID, Course_t<CID>*> CourseContainer;
	CourseContainer courses;
};

template <class UID, class FID, class CID>
class University_t {
public:
	University_t(UID id) : id(id) {}
	University_t(const University_t& other) : id(other.id), faculties(other.faculties) {}
	virtual ~University_t() {}
	University_t& operator = (const University_t& rhs) {
		if (this != &rhs) {
			id = rhs.id;
			faculties = rhs.faculties;
		}
		return *this;
	}

	void setUniversityID (const UID& new_id) {
		id = new_id;
	}

	const UID& getUniversityID () const {
		return id;
	}

	void addFaculty(Faculty_t<FID, CID>* faculty) {
		faculties.insert(make_pair(faculty->getFacultyID(), faculty));
	}

	const Faculty_t<FID, CID>* getFaculty(const CID& faculty_id) const {
		typename FacultyContainer::const_iterator it = faculties.find(faculty_id);
		if (it != faculties.end()) {
			return it->second;
		} else {
			return 0;
		}
	}
private:
	UID id;
	typedef map<FID, Faculty_t<FID, CID>*> FacultyContainer;
	FacultyContainer faculties;
};

int main(void) {
	University_t<string, int, double> uni("stupid");
	Faculty_t<int, double> fac(42);
	Course_t<double> course(3.14);
	uni.addFaculty(&fac);
	fac.addCourse(&course);
	print(uni.getFaculty(42)->getCourse(3.14)->getCourseID());
}