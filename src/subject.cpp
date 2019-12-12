#include "subject.h"
Subject::Subject() :NonPerson(0, " ") {
	setUnit(0);
}
Subject::Subject(int t1, const char* t2, int t3) : NonPerson(t1, t2) {
	setUnit(t3);
}
void Subject::setUnit(int t3) {
	unit = t3;
}
//* set unit of subject.


const int Subject::getUnit() const {
	return unit;
}
//* return a data.