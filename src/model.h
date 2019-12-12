#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include "student.h"
#include "userInfo.h"
#include "instructor.h"
#include "room.h"
#include "subject.h"
#include "section.h"
using namespace std;
class Controller;
class Model {
private:
	string ID;
	fstream f[6];

	Controller* controller;
	map<int,UserInfo> userInfo;
	map<int,Student> student;
	map<int,Instructor> instructor;
	map<int,Room> room;
	map<int,Subject> subject;
	map<int,Section> section;
public:
	void setID(string id) {
		ID = id;
	}
	void init(Controller*);
	void load();
	void makeFile(int);

	void saveUserInfo(int);
	pair<map<int,UserInfo>::const_iterator, map<int, UserInfo>::const_iterator> getUserInfoInterval();
	UserInfo getUserInfo(int);
	void insertUserInfo(int,string,string);
	void updateUserInfo(int, string, string);
	void deleteUserInfo(int);

	void saveInstructor(int);
	pair<map<int, Instructor>::const_iterator, map<int, Instructor>::const_iterator> getInstructorInterval();
	Instructor getInstructor(int);
	void insertInstructor(int, string, string, string);
	void updateInstructor(int, string, string, string);
	void deleteInstructor(int);

	void saveRoom(int);
	pair<map<int, Room>::const_iterator, map<int, Room>::const_iterator> getRoomInterval();
	Room getRoom(int);
	void insertRoom(int, string, string);
	void updateRoom(int, string, string);
	void deleteRoom(int);

	void saveStudent(int);
	pair<map<int, Student>::const_iterator, map<int, Student>::const_iterator> getStudentInterval();
	Student getStudent(int);
	void insertStudent(int, string, string,string);
	void updateStudent(int, string, string,string);
	void deleteStudent(int);

	void saveSubject(int);
	pair<map<int, Subject>::const_iterator, map<int, Subject>::const_iterator> getSubjectInterval();
	Subject getSubject(int);
	void insertSubject(int, string, int);
	void updateSubject(int, string, int);
	void deleteSubject(int);

	void saveSection(int);
	pair<map<int, Section>::const_iterator, map<int, Section>::const_iterator> getSectionInterval();
	Section getSection(int);
	void insertSection(int, int,int,int,int, int, int, int, int);
	void updateSection(int, int,int,int,int, int, int, int, int);
	void deleteSection(int);

	void addSectionToStudent(int);
	int getSectionToStudent(int);
};