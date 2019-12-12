
#include "student.h"


Student::Student() :Person(0, " ", " ") {
	for (int i = 0; i < subjectNumLength; i++) {
		setSubjectNum(i, 0);
	}
	setMajor("");
}

Student::Student(int t1, const char* t2, const char* t3,const char* t4) : Person(t1, t2, t3) {
	for (int i = 0; i < subjectNumLength; i++) {
		setSubjectNum(i, 0);
	}
	setMajor(t4);
}
void Student::setMajor(const char* t2) {
	unsigned int len = strlen(t2) < majorLength ? strlen(t2) : majorLength - 1;
	strncpy_s(major, t2, len);
	major[len] = '\0';
}
const char* Student::getMajor() {
	return major;
}
void Student::setSubjectNum(int index, int value) {
	subjectNum[index] = value;
}
//* set a subject number.


int Student::getSubjectNum(int index) {
	return subjectNum[index];
}
// return a data.