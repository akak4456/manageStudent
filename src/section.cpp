#include "section.h"
Section::Section() {
	setNo(0);
	setSubjectNo(0);
	setRoomNo(0);
	setInstructorNo(0);
	setDay(0);
	setTimeStartHour(0);
	setTimeStartMinute(0);
	setTimeEndHour(0);
	setTimeEndMinute(0);
}
Section::Section(int t1, int t2, int t3, int t4, int t5, int t6, int t7, int t8, int t9) {
	setNo(t1);
	setSubjectNo(t2);
	setRoomNo(t3);
	setInstructorNo(t4);
	setDay(t5);
	setTimeStartHour(t6);
	setTimeStartMinute(t7);
	setTimeEndHour(t8);
	setTimeEndMinute(t9);
}
void Section::setNo(int t1) {
	no = t1;
}
//* set section number.
void Section::setSubjectNo(int t2) {
	subjectNo = t2;
}
//* set subject number.
void Section::setRoomNo(int t3) {
	roomNo = t3;
}
//* set Room number.
void Section::setInstructorNo(int t4) {
	instructorNo = t4;
}
//* set instructor number.
void Section::setDay(int t5) {
	day = t5;
}
//* set a day of course.
void Section::setTimeStartHour(int t6) {
	timeStartHour = t6;
}
//* set start hour.
void Section::setTimeStartMinute(int t7) {
	timeStartMinute = t7;
}
//* set start minute.
void Section::setTimeEndHour(int t8) {
	timeEndHour = t8;
}
//* set end hour.
void Section::setTimeEndMinute(int t9) {
	timeEndMinute = t9;
}
//* set end minute.

//
int Section::getNo() const {
	return no;
}
int Section::getSubjectNo() const {
	return subjectNo;
}
int Section::getRoomNo() const {
	return roomNo;
}
int Section::getInstructorNo() const {
	return instructorNo;
}
int Section::getDay() const {
	return day;
}
int Section::getTimeStartHour() const {
	return timeStartHour;
}
int Section::getTimeStartMinute() const {
	return timeStartMinute;
}
int Section::getTimeEndHour() const {
	return timeEndHour;
}
int Section::getTimeEndMinute() const {
	return timeEndMinute;
}
//return a data.
