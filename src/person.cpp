#include "person.h"
Person::Person(int t1, const char* t2, const char* t3) {
	setNo(t1);
	setName(t2);
	setPassword(t3);
}
void Person::setNo(int t1) {
	no = t1;
}
//* set student, instructor, user, etc number.

void Person::setName(const char* t2) {
	unsigned int len = strlen(t2) < nameLength ? strlen(t2) : nameLength-1;
	strncpy_s(name, t2, len);
	name[len] = '\0';
}
//* set name of student, instructor, user, etc.

void Person::setPassword(const char* t3) {
	unsigned int len = strlen(t3) < passwordLength ? strlen(t3) : passwordLength-1;
	strncpy_s(password, t3, len);
	password[len] = '\0';
}
//* set password of student, instructor, user, etc.


//
int Person::getNo() const {
	return no;
}
const char* Person::getName() const {
	return name;
}
const char* Person::getPassword() const {
	return password;
}
//* return a data.