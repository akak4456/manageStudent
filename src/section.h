#pragma once
#include "subject.h"
#include "room.h"
#include "instructor.h"
#include "subject.h"
#include "room.h"
class Section {
private:
	int no;
	int subjectNo;
	int roomNo;
	int instructorNo;
	int day;
	int timeStartHour;
	int timeStartMinute;
	int timeEndHour;
	int timeEndMinute;
public:
	Section();
	Section(int, int, int, int, int, int, int, int, int);
	void setNo(int);
	void setSubjectNo(int);
	void setRoomNo(int);
	void setInstructorNo(int);
	void setDay(int);
	void setTimeStartHour(int);
	void setTimeStartMinute(int);
	void setTimeEndHour(int);
	void setTimeEndMinute(int);
	int getNo() const;
	int getSubjectNo() const;
	int getRoomNo() const;
	int getInstructorNo() const;
	int getDay() const;
	int getTimeStartHour() const;
	int getTimeStartMinute() const;
	int getTimeEndHour() const;
	int getTimeEndMinute() const;
};