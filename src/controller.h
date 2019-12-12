#pragma once
#include <iostream>
#include <utility>
#include "model.h"
#include "view.h"
#include "define.h"
using namespace std;
class Controller {
private:
	string ID;
	Model* model;
	View* view;
public:
	void setID(string id) {
		ID = id;
	}
	void init(Model*, View*);
	void loadData();
	void makeFile(int);
	int login(string, string);

	void addUserInfo(int, string, string);
	void addInstructor(int, string, string, string);
	void addRoom(int, string, string);
	void addStudent(int, string, string,string);
	void addSubject(int, string, int);
	void addSection(int, int, int, int, int, int, int, int, int);

	void updateUserInfo(int, string, string);
	void updateInstructor(int, string, string, string);
	void updateRoom(int, string, string);
	void updateStudent(int, string, string,string);
	void updateSubject(int, string, int);
	void updateSection(int, int, int, int, int, int, int, int, int);

	void deleteUserInfo(int);
	void deleteInstructor(int);
	void deleteRoom(int);
	void deleteStudent(int);
	void deleteSubject(int);
	void deleteSection(int);

	string getAllUserInfo();
	string getAllInstructor();
	string getAllRoom(); 
	string getAllStudent();
	string getAllSubject();
	string getAllSection();
	string getAllEnrollSection();
	string getAllMySchedule();

	bool isThereUserInfo(int);
	bool isThereInstructor(int);
	bool isThereRoom(int);
	bool isThereStudent(int);
	bool isThereSubject(int);
	bool isThereSection(int);
	bool addSectionTostudent(int);

	int searchByNameInStudent();
	void updateStudentPassword(string);
};