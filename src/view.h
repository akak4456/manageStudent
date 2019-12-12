#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <vector>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include "define.h"
using namespace std;
class Controller;
class View {
private:
	string ID;
	Controller* controller;
	HANDLE console;
	COORD CursorPosition;
	void showAdminMainMenu();
	void showStudentMainMenu();

	void showInstructorInformationMenu();
	void showInstructorList();
	void updateInstructor();
	void addInstructor();
	void deleteInstructor();

	void showRoomInformationMenu();
	void showRoomList();
	void updateRoom();
	void addRoom();
	void deleteRoom();

	void showStudentInformationMenu();
	void showStudentList();
	void updateStudent();
	void addStudent();
	void deleteStudent();

	void showSubjectInformationMenu();
	void showSubjectList();
	void updateSubject();
	void addSubject();
	void deleteSubject();

	void showClassScheduleInformationMenu();
	void showSectionList();
	void updateSection();
	void addSection();
	void deleteSection();

	void showUserInformationMenu();
	void showUserInfoList();
	void updateUserInfo();
	void addUserInfo();
	void deleteUserInfo();

	void showBuildFileMenu();

	void enrollClass();
	void viewAvailableCourse();
	void viewMySchedule();
	void updatePassword();
public:
	void setID(string id) {
		ID = id;
	}
	void init(Controller*);
	void gotoXY(int, int);
	void showLogin();
};