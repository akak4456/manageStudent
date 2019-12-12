#include "nonPerson.h"
NonPerson::NonPerson(int t1, const char* t2) {
	setNo(t1);
	setDescription(t2);
}
void NonPerson::setNo(int t1) {
	no = t1;
}
//* set subject, room, section, etc number.

void NonPerson::setDescription(const char* t2) {
	unsigned int len = strlen(t2) < descriptionLength ? strlen(t2) : descriptionLength-1;
	strncpy_s(description, t2, len);
	description[len] = '\0';
}
//* set name of subject, room, section, etc.

//
int NonPerson::getNo() const {
	return no;
}
const char* NonPerson::getDescription() const {
	return description;
}
//* return a data.