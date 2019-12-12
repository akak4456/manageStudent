#include "view.h"
#include "controller.h"
void View::init(Controller* c) {
	console = GetStdHandle(STD_OUTPUT_HANDLE);
	controller = c;
}
void View::gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}
void View::showLogin() {
	while (true) {
		cout << endl << endl << endl;
		cout << "          --------------------Login--------------------" << endl;
		cout << "          |                                           |" << endl;
		cout << "          |     Enter Username :                      |" << endl;
		cout << "          |     Enter Password :                      |" << endl;
		cout << "          |                                           |" << endl;
		cout << "          ---------------------------------------------" << endl;
		string userName = "";
		string password = "";
		gotoXY(35, 5);
		cin >> userName;
		gotoXY(35, 6);
		char t = 0;
		while (t = _getch()) {
			if (t == 13) {
				//if t is Enter key
				break;
			}
			else if (t == 8) {
				//if t is backspace key
				if (password.length() > 0) {
					password.erase(password.length() - 1);
					gotoXY(35 + password.length(), 6);
					cout << " ";
					gotoXY(35 + password.length(), 6);
				}
			}
			else {
				password += t;
				gotoXY(35 + password.length() - 1, 6);
				cout << "*";
			}
		}
		int result = controller->login(userName, password);
		system("cls");
		if (result == 0) {
			//this mean login is wrong
		}
		else if (result == 1) {
			//this mean admin login
			showAdminMainMenu();
			break;
		}
		else if (result == 2) {
			//this mean student login
			showStudentMainMenu();
			break;
		}
	}
}

//
void View::showAdminMainMenu() {
	char t = 0;
	while (t != 'X') {
		cout << endl << endl << endl;
		cout << "          -----------Scheduler's Menu(Admin)-----------" << endl;
		cout << "          |     (I)nstructor Information              |" << endl;
		cout << "          |     (R)oom Information                    |" << endl;
		cout << "          |     (S)tudent Information                 |" << endl;
		cout << "          |     (J)Subject Information                |" << endl;
		cout << "          |     (C)lass Schedule Information          |" << endl;
		cout << "          |     (U)ser Information                    |" << endl;
		cout << "          |     (B)uild Files                         |" << endl;
		cout << "          |     (X)Exit                               |" << endl;
		cout << "          ---------------------------------------------" << endl;
		cout << "          Enter Your Choice: ";
		cin >> t;
		//get user's choice
		system("cls");
		switch (t) {
		case 'I':
			showInstructorInformationMenu();
			break;
		case 'R':
			showRoomInformationMenu();
			break;
		case 'S':
			showStudentInformationMenu();
			break;
		case 'J':
			showSubjectInformationMenu();
			break;
		case 'C':
			showClassScheduleInformationMenu();
			break;
		case 'U':
			showUserInformationMenu();
			break;
		case 'B':
			showBuildFileMenu();
			break;
		}
	}
}
//* About viewing AdminMenu.


//
void View::showInstructorInformationMenu() {
	char t = 0;
	while (t != 'X') {
		cout << endl << endl << endl;
		cout << "          --Admin Sub-menu For Instructor Information--" << endl;
		cout << "          |          (S)how Instructor List           |" << endl;
		cout << "          |          (U)pdate Instructor              |" << endl;
		cout << "          |          (A)dd new Instructor             |" << endl;
		cout << "          |          (D)elete Instructor              |" << endl;
		cout << "          |          (X)EXIT back to menu             |" << endl;
		cout << "          ---------------------------------------------" << endl;
		cout << "          Enter Your Choice: ";
		cin >> t;
		//get user's choice
		system("cls");
		switch (t) {
		case 'S':
			showInstructorList();
			break;
		case 'U':
			updateInstructor();
			break;
		case 'A':
			addInstructor();
			break;
		case 'D':
			deleteInstructor();
			break;
		}
	}
}

void View::showInstructorList() {
	cout << "------------------------------Instructor List------------------------------" << endl;
	cout << setw(5) << "No." << setw(nameLength) << "Name" << setw(rankLength) << "Rank" << endl;
	cout << controller->getAllInstructor() << endl;
	//* Get a instructor list.
}
void View::updateInstructor() {
	try {
		cout << "Enter Number You Wanna Change:";
		int t1;
		cin >> t1;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		if (!controller->isThereInstructor(t1)) 
			//* When there is no matching instructor number.
		{
			throw string("There Is No Instructor");
		}
		if (t1 <= 0) {
			throw string("You Must Enter Number Over 0");
		}
		cout << "Enter Instructor's Name:";
		string t2;
		cin >> t2;
		cout << "Enter Instructor's Password:";
		string t3;
		cin >> t3;
		cout << "Enter Instructor's Rank:";
		string t4;
		cin >> t4;
		controller->updateInstructor(t1, t2, t3, t4);
		//* Pass the changes to the controller.
	}
	catch (string e) {
		cout << e << endl;
	}
	//* Using try and catch shows errors.
	cout << "Done Update" << endl;
}
void View::addInstructor() {
	try {
		cout << "Enter New Number:";
		int t1;
		cin >> t1;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		if (controller->isThereInstructor(t1))
	    //* When there is already instructor.
		{
			throw string("There Is Instructor");
		}
		if (t1 <= 0) {
			throw string("You Must Enter Number Over 0");
		}
		cout << "Enter New Instructor's Name:";
		string t2;
		cin >> t2;
		cout << "Enter New Instructor's Password:";
		string t3;
		cin >> t3;
		cout << "Enter New Instructor's Rank:";
		string t4;
		cin >> t4;
		
		controller->addInstructor(t1, t2, t3, t4);
		//* Pass the added data to the controller.
	}
	catch (string e) {
		cout << e << endl;
	}
	//* Using try and catch shows errors.
	cout << "Done Add" << endl;
}
void View::deleteInstructor() {
	try {
		cout << "Enter Number You Wanna Delete:";
		int t1;
		cin >> t1;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		if (!controller->isThereInstructor(t1)) 
		//* When there is no matching instructor number.
		{
			throw string("There Is No Instructor");
		}
		if (t1 <= 0) {
			throw string("You Must Enter Over Number 0");
		}
		
		controller->deleteInstructor(t1);
		//* Pass the data that you want to delete to controller.
	}
	catch (string e) {
		cout << e << endl;
	}
	//* Using try and catch shows errors.
	cout << "Done Delete" << endl;
}
//* About viewing InstructorInformationMenu

//
void View::showRoomInformationMenu() {
	char t = 0;
	while (t != 'X') {
		cout << endl << endl << endl;
		cout << "          -----Admin Sub-menu For Room Information-----" << endl;
		cout << "          |          (S)how Room List                 |" << endl;
		cout << "          |          (U)pdate Room                    |" << endl;
		cout << "          |          (A)dd new Room                   |" << endl;
		cout << "          |          (D)elete Room                    |" << endl;
		cout << "          |          (X)EXIT back to menu             |" << endl;
		cout << "          ---------------------------------------------" << endl;
		cout << "          Enter Your Choice: ";
		cin >> t;
		//get user's choice
		system("cls");
		switch (t) {
		case 'S':
			showRoomList();
			break;
		case 'U':
			updateRoom();
			break;
		case 'A':
			addRoom();
			break;
		case 'D':
			deleteRoom();
			break;
		}
	}
}
void View::showRoomList() {
	
	cout << "------------------------------Room List------------------------------" << endl;
	cout << setw(5) << "No." << setw(descriptionLength) << "Description" << setw(typeLength) << "Type" << endl;
	cout << controller->getAllRoom() << endl;
	
}
void View::updateRoom() {

	try {
		cout << "Enter Number You Wanna Change:";
		int t1;
		cin >> t1;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		if (!controller->isThereRoom(t1))
		//* When there is no matching room number.
		{
			throw string("There Is No Room");
		}
		if (t1 <= 0) {
			throw string("You Must Enter Number Over 0");
		}
		cout << "Enter Room's Description:";
		string t2;
		cin >> t2;
		cout << "Enter Room's Type:";
		string t3;
		cin >> t3;
		
		controller->updateRoom(t1, t2, t3);
		//* Pass the changes to the controller.
	}
	catch (string e) {
		cout << e << endl;
	}
	//* Using try and catch shows errors.
	cout << "Done Update" << endl;
}
void View::addRoom() {
	
	try {
		cout << "Enter New Number:";
		int t1;
		cin >> t1;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		if (controller->isThereRoom(t1)) 
		//* When there is already room.
		{
			throw string("There Is Room");
		}
		if (t1 <= 0) {
			throw string("You Must Enter Number Over 0");
		}
		cout << "Enter New Room's Description:";
		string t2;
		cin >> t2;
		cout << "Enter New Room's Type:";
		string t3;
		cin >> t3;
		controller->addRoom(t1, t2, t3);
		//* Pass the added data to the controller.
	}
	catch (string e) {
		cout << e << endl;
	}
	//* Using try and catch shows errors.
	cout << "Done Add" << endl;
}
void View::deleteRoom() {
	try {
		cout << "Enter Number You Wanna Delete:";
		int t1;
		cin >> t1;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		if (!controller->isThereRoom(t1))
		//* When there is no matching room number.
		{
			throw string("There Is No Room");
		}
		if (t1 <= 0) {
			throw string("You Must Enter Number Over 0");
		}
		controller->deleteRoom(t1);
		//* Pass the data that you want to delete to controller.
	}
	catch (string e) {
		cout << e << endl;
	}
	//* Using try and catch shows errors.
	cout << "Done Delete" << endl;
}
//* About Viewing Room information 

//
void View::showStudentInformationMenu() {
	char t = 0;
	while (t != 'X') {
		cout << endl << endl << endl;
		cout << "          ----Admin Sub-menu For Student Information---" << endl;
		cout << "          |          (S)how Student List              |" << endl;
		cout << "          |          (U)pdate Student                 |" << endl;
		cout << "          |          (A)dd new Student                |" << endl;
		cout << "          |          (D)elete Student                 |" << endl;
		cout << "          |          (X)EXIT back to menu             |" << endl;
		cout << "          ---------------------------------------------" << endl;
		cout << "          Enter Your Choice: ";
		cin >> t;
		//get user's choice
		system("cls");
		switch (t) {
		case 'S':
			showStudentList();
			break;
		case 'U':
			updateStudent();
			break;
		case 'A':
			addStudent();
			break;
		case 'D':
			deleteStudent();
			break;
		}
	}
}
void View::showStudentList() {
	cout << "------------------------------Student List------------------------------" << endl;
	cout << setw(5) << "No." << setw(nameLength) << "Name" <<setw(majorLength)<<"Major"<< endl;
	cout << controller->getAllStudent() << endl;
	//* Get a student list
}
void View::updateStudent() {
	try {
		cout << "Enter Number You Wanna Change:";
		int t1;
		cin >> t1;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		if (!controller->isThereStudent(t1)) 
		//* When there is no matching student number.
		{
			throw string("There Is No Student");
		}
		if (t1 <= 0) {
			throw string("You Must Enter Number Over 0");
		}
		cout << "Enter Student's Name:";
		string t2;
		cin >> t2;
		cout << "Enter Student's Password:";
		string t3;
		cin >> t3;
		cout << "Enter Student's Major:";
		string t4;
		cin >> t4;
		controller->updateStudent(t1, t2, t3,t4);
		//* Pass the changes to the controller.
	}
	catch (string e) {
		cout << e << endl;
	}
	//* Using try and catch shows errors.
	cout << "Done Update" << endl;
}
void View::addStudent() {
	try {
		cout << "Enter New Number:";
		int t1;
		cin >> t1;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		if (controller->isThereStudent(t1)) 
		//* When there is already student.
		{
			throw string("There Is Student");
		}
		if (t1 <= 0) {
			throw string("You Must Enter Number Over 0");
		}
		cout << "Enter New Student's Name:";
		string t2;
		cin >> t2;
		cout << "Enter New Student's Password:";
		string t3;
		cin >> t3;
		cout << "Enter New Student's Major:";
		string t4;
		cin >> t4;
		controller->addStudent(t1, t2, t3,t4);
		//* Pass the added data to controller.
	}
	catch (string e) {
		cout << e << endl;
	}
	//* Using try and catch shows errors.
	cout << "Done Add" << endl;
}
void View::deleteStudent() {
	try {
		cout << "Enter Number You Wanna Delete:";
		int t1;
		cin >> t1;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		if (!controller->isThereStudent(t1)) 
		//* When there is no matching student number.
		{
			throw string("There Is No Student");
		}
		if (t1 <= 0) {
			throw string("You Must Enter Number Over 0");
		}
		controller->deleteStudent(t1);
		//* Pass data that you want to delete.
	}
	catch (string e) {
		cout << e << endl;
	}
	//* Using try and catch shows errors.
	cout << "Done Delete" << endl;
}
//* About viewing student information meun. 

//
void View::showSubjectInformationMenu() {
	char t = 0;
	while (t != 'X') {
		cout << endl << endl << endl;
		cout << "          ----Admin Sub-menu For Subject Information---" << endl;
		cout << "          |          (S)how Subject List              |" << endl;
		cout << "          |          (U)pdate Subject                 |" << endl;
		cout << "          |          (A)dd new Subject                |" << endl;
		cout << "          |          (D)elete Subject                 |" << endl;
		cout << "          |          (X)EXIT back to menu             |" << endl;
		cout << "          ---------------------------------------------" << endl;
		cout << "          Enter Your Choice: ";
		cin >> t;
		//get user's choice
		system("cls");
		switch (t) {
		case 'S':
			showSubjectList();
			break;
		case 'U':
			updateSubject();
			break;
		case 'A':
			addSubject();
			break;
		case 'D':
			deleteSubject();
			break;
		}
	}
}
void View::showSubjectList() {
	cout << "------------------------------Subject List------------------------------" << endl;
	cout << setw(5) << "No." << setw(descriptionLength) << "Description" << setw(5) << "Unit" << endl;
	cout << controller->getAllSubject() << endl;
	//* Get a subject list
}
void View::updateSubject() {
	try {
		cout << "Enter Number You Wanna Change:";
		int t1;
		cin >> t1;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		if (!controller->isThereSubject(t1)) 
			//* When there is no matching subject number.
		{
			throw string("There Is No Subject");
		}
		if (t1 <= 0) {
			throw string("You Must Enter Number Over 0");
		}
		cout << "Enter Subject's Description:";
		string t2;
		cin >> t2;
		cout << "Enter Subject's Unit:";
		int t3;
		cin >> t3;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		if (t3 <= 0) {
			throw string("You Must Enter Number Over 0");
		}
		controller->updateSubject(t1, t2, t3);
		//* Pass the changes to the controller.
	}
	catch (string e) {
		cout << e << endl;
	}
	//* Using try and catch shows errors.
	cout << "Done Update" << endl;
}
void View::addSubject() {
	try {
		cout << "Enter New Number:";
		int t1;
		cin >> t1;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		if (controller->isThereSubject(t1))
			//* When there is already room.
		{
			throw string("There Is Subject");
		}
		if (t1 <= 0) {
			throw string("You Must Enter Number Over 0");
		}
		cout << "Enter New Subject's Description:";
		string t2;
		cin >> t2;
		cout << "Enter New Subject's Unit:";
		int t3;
		cin >> t3;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		if (t3 <= 0) {
			throw string("You Must Enter Number Over 0");
		}
		controller->addSubject(t1, t2, t3);
		//* Pass the added data to the controller.
	}
	catch (string e) {
		cout << e << endl;
	}
	//* Using try and catch shows errors.
	cout << "Done Add" << endl;
}
void View::deleteSubject() {
	try {
		cout << "Enter Number You Wanna Delete:";
		int t1;
		cin >> t1;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		if (!controller->isThereSubject(t1)) 
			//* When there is no matching subject number.
		{
			throw string("There Is No Subject");
		}
		if (t1 <= 0) {
			throw string("You Must Enter Number Over 0");
		}
		controller->deleteSubject(t1);
		//* Pass the data that you want to delete.
	}
	catch (string e) {
		cout << e << endl;
	}
	//* Using try and catch shows errors.
	cout << "Done Delete" << endl;
}
//* About viewing showSubjectInformationMenu.

//
void View::showClassScheduleInformationMenu() {
	char t = 0;
	while (t != 'X') {
		cout << endl << endl << endl;
		cout << "          ----Admin Sub-menu For Section Information---" << endl;
		cout << "          |          (S)how Section List              |" << endl;
		cout << "          |          (U)pdate Section                 |" << endl;
		cout << "          |          (A)dd new Section                |" << endl;
		cout << "          |          (D)elete Section                 |" << endl;
		cout << "          |          (X)EXIT back to menu             |" << endl;
		cout << "          ---------------------------------------------" << endl;
		cout << "          Enter Your Choice: ";
		cin >> t;
		//get user's choice
		system("cls");
		switch (t) {
		case 'S':
			showSectionList();
			break;
		case 'U':
			updateSection();
			break;
		case 'A':
			addSection();
			break;
		case 'D':
			deleteSection();
			break;
		}
	}
}
void View::showSectionList() {
	cout << "------------------------------Section List------------------------------" << endl;
	cout << setw(5) << "No." << setw(descriptionLength) << "Subject Name" << setw(descriptionLength) << "Room Name" << setw(descriptionLength) << "Instructor Name" << setw(5) << "Day" << setw(15) << "Time" << endl;
	cout << controller->getAllSection() << endl;
	//* Get a section list.
}
void View::updateSection() {
	try {
		cout << "Enter Number You Wanna Change:";
		int t1;
		cin >> t1;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		if (!controller->isThereSection(t1))
		//* When there is no matching section number.
        {
			throw string("There Is No Section");
		}
		if (t1 <= 0) {
			throw string("You Must Enter Number Over 0");
		}
		cout << "Enter Subject's Number:";
		int t2;
		cin >> t2;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		if (!controller->isThereSubject(t2)) 
	    //* When there is no matching subject number.
		{
			throw string("There Is No Subject");
		}
		if (t2 <= 0) {
			throw string("You Must Enter Number Over 0");
		}
		cout << "Enter Room's Number:";
		int t3;
		cin >> t3;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		if (!controller->isThereRoom(t3)) 
		//* When there is no matching room number.
		{
			throw string("There Is No Room");
		}
		if (t3 <= 0) {
			throw string("You Must Enter Number Over 0");
		}
		cout << "Enter Instructor's Number:";
		int t4;
		cin >> t4;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		if (!controller->isThereInstructor(t4))
		//* When there is no matching instructor number.
		{
			throw string("There Is No Room");
		}
		if (t4 <= 0) {
			throw string("You Must Enter Number Over 0");
		}
		int t5;
		cout << "Enter Day:";
		cin >> t5;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		if (t5 <= 0) {
			throw string("You Must Enter Number Over 0");
		}
		int t6;
		cout << "Enter TimeStartHour:";
		cin >> t6;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		int t7;
		cout << "Enter TimeStartMinute:";
		cin >> t7;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		int t8;
		cout << "Enter TimeEndHour:";
		cin >> t8;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		int t9;
		cout << "Enter TimeEndMinute:";
		cin >> t9;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		if (t6 * 60 + t7 >= t8 * 60 + t9) {
			throw string("You Cannot Enter Start Time Is Over End Time");
		}
		controller->updateSection(t1, t2, t3, t4, t5, t6, t7, t8, t9);
		//* Pass the changes to the controller.
	}
	catch (string e) {
		cout << e << endl;
	}
	//* Using try and catch shows errors.
	cout << "Done Update" << endl;
}
void View::addSection() {
	try {
		cout << "Enter New Number:";
		int t1;
		cin >> t1;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		if (controller->isThereSection(t1)) 
		//* When there is already section.
		{
			throw string("There Is Section");
		}
		if (t1 <= 0) {
			throw string("You Must Enter Number Over 0");
		}
		cout << "Enter Subject's Number:";
		int t2;
		cin >> t2;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		if (!controller->isThereSubject(t2))
		//* When there is already subject.
		{
			throw string("There Is No Subject");
		}
		if (t2 <= 0) {
			throw string("You Must Enter Number Over 0");
		}
		cout << "Enter Room's Number:";
		int t3;
		cin >> t3;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		if (!controller->isThereRoom(t3)) 
	    //* When there is already room.
		{
			throw string("There Is No Room");
		}
		if (t3 <= 0) {
			throw string("You Must Enter Number Over 0");
		}
		cout << "Enter Instructor's Number:";
		int t4;
		cin >> t4;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		if (!controller->isThereInstructor(t4))
		//* When there is already instructor.
		{
			throw string("There Is No Room");
		}
		if (t4 <= 0) {
			throw string("You Must Enter Number Over 0");
		}
		int t5;
		cout << "Enter Day:";
		cin >> t5;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		if (t5 <= 0) {
			throw string("You Must Enter Number Over 0");
		}
		int t6;
		cout << "Enter TimeStartHour:";
		cin >> t6;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		int t7;
		cout << "Enter TimeStartMinute:";
		cin >> t7;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		int t8;
		cout << "Enter TimeEndHour:";
		cin >> t8;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		int t9;
		cout << "Enter TimeEndMinute:";
		cin >> t9;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		if (t6 * 60 + t7 >= t8 * 60 + t9) {
			throw string("You Cannot Enter Start Time Is Over End Time");
		}
		controller->addSection(t1, t2, t3, t4, t5, t6, t7, t8, t9);
		//* Pass the added data to the controller.
	}
	catch (string e) {
		cout << e << endl;
	}
	//* Using try and catch shows errors.
	cout << "Done Add" << endl;
}
void View::deleteSection() {
	try {
		cout << "Enter Number You Wanna Delete:";
		int t1;
		cin >> t1;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		if (!controller->isThereSection(t1)) 
		//* When there is no matching section number.
		{
			throw string("There Is No Section");
		}
		if (t1 <= 0) {
			throw string("You Must Enter Number Over 0");
		}
		controller->deleteSection(t1);
		//* Pass the data that you want to delete.
	}
	catch (string e) {
		cout << e << endl;
	}
	//* Using try and catch shows errors.
	cout << "Done Delete" << endl;
}
//* About viewing classScheduleInformationMenu.

//
void View::showUserInformationMenu() {
	char t = 0;
	while (t != 'X') {
		cout << endl << endl << endl;
		cout << "          ---Admin Sub-menu For UserInfo Information---" << endl;
		cout << "          |          (S)how UserInfo List             |" << endl;
		cout << "          |          (U)pdate UserInfo                |" << endl;
		cout << "          |          (A)dd new UserInfo               |" << endl;
		cout << "          |          (D)elete UserInfo                |" << endl;
		cout << "          |          (X)EXIT back to menu             |" << endl;
		cout << "          ---------------------------------------------" << endl;
		cout << "          Enter Your Choice: ";
		cin >> t;
		//get user's choice
		system("cls");
		switch (t) {
		case 'S':
			showUserInfoList();
			break;
		case 'U':
			updateUserInfo();
			break;
		case 'A':
			addUserInfo();
			break;
		case 'D':
			deleteUserInfo();
			break;
		}
	}
}
void View::showUserInfoList() {
	cout << "------------------------------UserInfo Information------------------------------" << endl;
	cout << setw(5) << "No." << setw(nameLength) << "Name" << setw(passwordLength) << "Password" << endl;
	cout << controller->getAllUserInfo() << endl;
	//* Get a UserInfoList.
}
void View::updateUserInfo() {
	try {
		cout << "Enter Number You Wanna Change:";
		int t1;
		cin >> t1;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		if (!controller->isThereUserInfo(t1)) 
		//* When there is no matching user number.
		{
			throw string("There Is No User");
		}
		if (t1 <= 0) {
			throw string("You Must Enter Number Over 0");
		}
		cout << "Enter User's ID:";
		string t2;
		cin >> t2;
		cout << "Enter User's Password:";
		string t3;
		cin >> t3;
		controller->updateUserInfo(t1, t2, t3);
		//* Pass the changes to the controller.
	}
	catch (string e) {
		cout << e << endl;
	}
	//* Using try and catch shows errors.
	cout << "Done Update" << endl;
}
void View::addUserInfo() {
	try {
		cout << "Enter New Number:";
		int t1;
		cin >> t1;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		if (controller->isThereUserInfo(t1))
		//* When there is already user.
		{
			throw string("There Is User");
		}
		if (t1 <= 0) {
			throw string("You Must Enter Number Over 0");
		}
		cout << "Enter User's ID:";
		string t2;
		cin >> t2;
		cout << "Enter User's Password:";
		string t3;
		cin >> t3;
		controller->addUserInfo(t1, t2, t3);
		//* Pass the added data to the controller.
	}
	catch (string e) {
		cout << e << endl;
	}
	//* Using try and catch shows errors.
	cout << "Done Add" << endl;
}
void View::deleteUserInfo() {
	try {
		cout << "Enter Number You Wanna Delete:";
		int t1;
		cin >> t1;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		if (!controller->isThereUserInfo(t1)) 
		//* When there is no matching user number.
		{
			throw string("There Is No User");
		}
		if (t1 <= 0) {
			throw string("You Must Enter Number Over 0");
		}
		controller->deleteUserInfo(t1);
		//* Pass data that you want to delete.
	}
	catch (string e) {
		cout << e << endl;
	}
	//* Using try and catch shows errors.
	cout << "Done Delete" << endl;
}
//* About viewing UserInformationMenu.

//
void View::showBuildFileMenu() {
	try {
		cout << "Enter Number You Wanna Create:";
		int t1;
		cin >> t1;
		if (cin.fail()) {
			cin.clear();
			throw string("You Must Enter Number");
		}
		if (t1 <= 0) {
			throw string("You Must Enter Number Over 0");
		}
		char t;
		cout << "It Delete Every Data Including Admin. Do You Wanna Make File?(Y/N)";
		cin >> t;
		if (t == 'Y') {
			controller->makeFile(t1);
			//Pass the number of File you want to make.
		}
	}
	catch (string e) {
		cout << e << endl;
	}
	//* Using try and catch shows errors.
	cout << "Done Build File" << endl;
}
//* About viewing BuildFileMenu.

//
void View::showStudentMainMenu() {

	char t = 0;
	while (t != 'X') {
		cout << endl << endl << endl;
		cout << "          ----------------Student Menu  ---------------" << endl;
		cout << "          |          (E)nroll a class                 |" << endl;
		cout << "          |          (V)iew Available courses         |" << endl;
		cout << "          |          (M)View My Schedule              |" << endl;
		cout << "          |          (U)pdate password                |" << endl;
		cout << "          |          (X)EXIT                          |" << endl;
		cout << "          ---------------------------------------------" << endl;
		cout << "          Enter Your Choice: ";
		cin >> t;
		//get user's choice
		system("cls");
		switch (t) {
		case 'E':
			enrollClass();
			break;
		case 'V':
			viewAvailableCourse();
			break;
		case 'M':
			viewMySchedule();
			break;
		case 'U':
			updatePassword();
			break;
		}
	}


}

void View::enrollClass() {

	int subjectnum = 0;

	cout << "-------------------List Of Courses  --------------------------------------" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
	cout << setw(8) << "Courseno" << setw(descriptionLength) << "Course" << setw(5) << "Day" << setw(15) << "Time" << endl;

	cout << controller->getAllEnrollSection() << endl;
	//* cout enrollsection.

	cout << "Enter Course Number To Enroll : ";

	cin >> subjectnum;
	try {
		if(!controller->addSectionTostudent(subjectnum)) 
		//* When there is no matching subject number or already enrolled.
		{
			throw string("There Is Some Problem");
		}
	}
	catch (string e) {
		cout << e;
	}
	//* Using try and catch shows errors.
}

void View::viewAvailableCourse() {

	cout << "--------------------------Available Course----------------------------" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << setw(8) << "Courseno" << setw(descriptionLength) << "Course" << setw(5) << "Day" << setw(15) << "Time" << endl;
	cout << controller->getAllEnrollSection() << endl;
	//* cout available course.

}

void View::viewMySchedule() {

	int subjectnum = 0;

	cout << "-------------------------Enrolled Subject----------------------------" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << setw(8) << "Courseno" << setw(descriptionLength) << "Course" << setw(5) << "Day" << setw(15) << "Time" << endl;

	cout << controller->getAllMySchedule() << endl;

	//* cout schedule that you enrolled.

}

void View::updatePassword() {


	string password;

	cout << "----------------------Password Update--------------------------" << endl;
	cout << endl;
	cout << "Enter Password You Want To Change : ";

	cin >> password;

	controller->updateStudentPassword(password);
	//* update password using controller -> model.

	cout << "Done" << endl;

}
//* About viewing studentMenu.