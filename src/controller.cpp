#include "controller.h"
void Controller::init(Model* m, View* v) {
	model = m;
	view = v;
}
void Controller::loadData() {
	model->load();
}
void Controller::makeFile(int count) {
	model->makeFile(count);
}
int Controller::login(string id, string pw) {
	pair<map<int, UserInfo>::const_iterator, map<int, UserInfo>::const_iterator> interval1 = model->getUserInfoInterval();
	for (map<int,UserInfo>::const_iterator it = interval1.first; it != interval1.second; it++) {
		UserInfo tmp = it->second;
		if (tmp.getName() == id&&tmp.getPassword() == pw) {
			//if admin login success
			model->setID(id);
			view->setID(id);
			setID(id);
			return 1;
		}
	}
	pair<map<int, Student>::const_iterator, map<int, Student>::const_iterator> interval2 = model->getStudentInterval();
	for (map<int,Student>::const_iterator it = interval2.first; it != interval2.second; it++) {
		Student tmp = it->second;
		if (tmp.getName() == id&&tmp.getPassword() == pw) {
			//if student login success
			model->setID(id);
			view->setID(id);
			setID(id);
			return 2;
		}
	}
	return 0;
}

//*
void Controller::addUserInfo(int no, string id, string pw) {
	model->insertUserInfo(no, id, pw);
	model->saveUserInfo(no);
}
void Controller::addInstructor(int no, string name, string password, string rank) {
	model->insertInstructor(no, name, password, rank);
	model->saveInstructor(no);
}
void Controller::addRoom(int no, string description, string type) {
	model->insertRoom(no, description, type);
	model->saveRoom(no);
}
void Controller::addStudent(int no, string name, string password,string major) {
	model->insertStudent(no, name, password,major);
	model->saveStudent(no);
}
void Controller::addSubject(int no, string description, int unit) {
	model->insertSubject(no, description, unit);
	model->saveSubject(no);
}
void Controller::addSection(int t1, int t2, int t3, int t4, int t5, int t6, int t7, int t8, int t9) {
	model->insertSection(t1, t2, t3, t4, t5, t6, t7, t8, t9);
	model->saveSection(t1);
}

void Controller::updateUserInfo(int no, string id, string pw) {
	model->updateUserInfo(no, id, pw);
	model->saveUserInfo(no);
}
void Controller::updateInstructor(int no, string name, string password, string rank) {
	model->updateInstructor(no, name, password, rank);
	model->saveInstructor(no);
}
void Controller::updateRoom(int no, string description, string type) {
	model->updateRoom(no, description, type);
	model->saveRoom(no);
}
void Controller::updateStudent(int no, string name, string password,string major) {
	model->updateStudent(no, name, password,major);
	model->saveStudent(no);
}
void Controller::updateSubject(int no, string description, int unit) {
	model->updateSubject(no, description, unit);
	model->saveSubject(no);
}
void Controller::updateSection(int t1, int t2, int t3, int t4, int t5, int t6, int t7, int t8, int t9) {
	model->updateSection(t1, t2, t3, t4, t5, t6, t7, t8, t9);
	model->saveSection(t1);
}

void Controller::deleteUserInfo(int no) {
	model->deleteUserInfo(no);
	model->saveUserInfo(no);
}
void Controller::deleteInstructor(int no) {
	model->deleteInstructor(no);
	model->saveInstructor(no);
}
void Controller::deleteRoom(int no) {
	model->deleteRoom(no);
	model->saveRoom(no);
}
void Controller::deleteStudent(int no) {
	model->deleteStudent(no);
	model->saveStudent(no);
}
void Controller::deleteSubject(int no) {
	model->deleteSubject(no);
	model->saveSubject(no);
}
void Controller::deleteSection(int no) {
	model->deleteSection(no);
	model->saveSection(no);
}
//* Pass the necessary information to the model.

string Controller::getAllUserInfo() {
	string result;
	pair<map<int, UserInfo>::const_iterator, map<int, UserInfo>::const_iterator> interval = model->getUserInfoInterval();
	for (map<int,UserInfo>::const_iterator it = interval.first; it != interval.second; it++) {
		UserInfo tmp = it->second;
		if (tmp.getNo() != 0) {
			string no = to_string(tmp.getNo());
			string name = tmp.getName();
			string password = tmp.getPassword();
			//*
			for (int j = 0; j < 5 - no.size(); j++) {
				result += " ";
			}
			result += no;
			for (int j = 0; j < nameLength - name.size(); j++) {
				result += " ";
			}
			result += name;
			for (int j = 0; j < passwordLength - password.size(); j++) {
				result += " ";
			}
			result += password;
			//* Sets the size of the space.
			result += '\n';
		}
	}
	return result;
}
string Controller::getAllRoom() {
	string result;
	pair<map<int, Room>::const_iterator, map<int, Room>::const_iterator> interval = model->getRoomInterval();
	for (map<int,Room>::const_iterator it = interval.first; it != interval.second; it++) {
		Room tmp = it->second;
		if (tmp.getNo() != 0) {
			string no = to_string(tmp.getNo());
			string description = tmp.getDescription();
			string type = tmp.getType();
			//*
			for (int j = 0; j < 5 - no.size(); j++) {
				result += " ";
			}
			result += no;
			for (int j = 0; j < descriptionLength - description.size(); j++) {
				result += " ";
			}
			result += description;
			for (int j = 0; j < typeLength - type.size(); j++) {
				result += " ";
			}
			result += type;
			//* Sets the size of the space.
			result += '\n';
		}
	}
	return result;
}
string Controller::getAllInstructor() {
	string result;
	pair<map<int, Instructor>::const_iterator, map<int, Instructor>::const_iterator> interval = model->getInstructorInterval();
	for (map<int,Instructor>::const_iterator it = interval.first; it != interval.second; it++) {
		Instructor tmp = it->second;
		if (tmp.getNo() != 0) {
			string no = to_string(tmp.getNo());
			string name = tmp.getName();
			string rank = tmp.getRank();
			for (int j = 0; j < 5 - no.size(); j++) {
				result += " ";
			}
			result += no;
			for (int j = 0; j < nameLength - name.size(); j++) {
				result += " ";
			}
			result += name;
			for (int j = 0; j < rankLength - rank.size(); j++) {
				result += " ";
			}
			result += rank;
			result += '\n';
		}
	}
	return result;
}
string Controller::getAllStudent() {
	string result;
	pair<map<int, Student>::const_iterator, map<int, Student>::const_iterator> interval = model->getStudentInterval();
	for (map<int,Student>::const_iterator it = interval.first; it != interval.second; it++) {
		Student tmp = it->second;
		if (tmp.getNo() != 0) {
			string no = to_string(tmp.getNo());
			string name = tmp.getName();
			string major = tmp.getMajor();
			for (int j = 0; j < 5 - no.size(); j++) {
				result += " ";
			}
			result += no;
			for (int j = 0; j < nameLength - name.size(); j++) {
				result += " ";
			}
			result += name;
			for (int j = 0; j < majorLength - major.size(); j++) {
				result += " ";
			}
			result += major;
			result += '\n';
		}
	}
	return result;
}
string Controller::getAllSubject() {
	string result;
	pair<map<int, Subject>::const_iterator, map<int, Subject>::const_iterator> interval = model->getSubjectInterval();
	for (map<int,Subject>::const_iterator it = interval.first; it !=interval.second; it++) {
		Subject tmp = it->second;
		if (tmp.getNo() != 0) {
			string no = to_string(tmp.getNo());
			string description = tmp.getDescription();
			string unit = to_string(tmp.getUnit());
			for (int j = 0; j < 5 - no.size(); j++) {
				result += " ";
			}
			result += no;
			for (int j = 0; j < descriptionLength - description.size(); j++) {
				result += " ";
			}
			result += description;
			for (int j = 0; j < 5 - unit.size(); j++) {
				result += " ";
			}
			result += unit;
			result += '\n';
		}
	}
	return result;
}
string Controller::getAllSection() {
	string result;
	pair<map<int, Section>::const_iterator, map<int, Section>::const_iterator> interval = model->getSectionInterval();
	try {
		for (map<int, Section>::const_iterator it = interval.first; it != interval.second; it++) {
			Section tmp = it->second;
			if (tmp.getNo() != 0) {
				string no = to_string(tmp.getNo());
				if (!isThereSubject(tmp.getSubjectNo())) {
					throw tmp.getNo();
				}
				if (!isThereRoom(tmp.getRoomNo())) {
					throw tmp.getNo();
				}
				if (!isThereInstructor(tmp.getInstructorNo())) {
					throw tmp.getNo();
				}
				Subject subject = model->getSubject(tmp.getSubjectNo());
				Room room = model->getRoom(tmp.getRoomNo());
				Instructor instructor = model->getInstructor(tmp.getInstructorNo());
				string subjectName = subject.getDescription();
				string roomName = room.getDescription();
				string instructorName = instructor.getName();
				string day = "";;
				switch (tmp.getDay()) {
				case 1:
					day = "Mon";
					break;
				case 2:
					day = "Tue";
					break;
				case 3:
					day = "Wed";
					break;
				case 4:
					day = "Thu";
					break;
				case 5:
					day = "Fri";
					break;
				case 6:
					day = "Sat";
					break;
				}
				string time = "";
				if (to_string(tmp.getTimeStartHour()).size() == 1) {
					time += "0" + to_string(tmp.getTimeStartHour());
				}
				else {
					time += to_string(tmp.getTimeStartHour());
				}
				time += ":";
				if (to_string(tmp.getTimeStartMinute()).size() == 1) {
					time += "0" + to_string(tmp.getTimeStartMinute());
				}
				else {
					time += to_string(tmp.getTimeStartMinute());
				}
				time += "~";
				if (to_string(tmp.getTimeEndHour()).size() == 1) {
					time += "0" + to_string(tmp.getTimeEndHour());
				}
				else {
					time += to_string(tmp.getTimeEndHour());
				}
				time += ":";
				if (to_string(tmp.getTimeEndMinute()).size() == 1) {
					time += "0" + to_string(tmp.getTimeEndMinute());
				}
				else {
					time += to_string(tmp.getTimeEndMinute());
				}
				for (int j = 0; j < 5 - no.size(); j++) {
					result += " ";
				}
				result += no;
				for (int j = 0; j < descriptionLength - subjectName.size(); j++) {
					result += " ";
				}
				result += subjectName;
				for (int j = 0; j < descriptionLength - roomName.size(); j++) {
					result += " ";
				}
				result += roomName;
				for (int j = 0; j < nameLength - instructorName.size(); j++) {
					result += " ";
				}
				result += instructorName;
				for (int j = 0; j < 5 - day.size(); j++) {
					result += " ";
				}
				result += day;
				for (int j = 0; j < 15 - time.size(); j++) {
					result += " ";
				}
				result += time;
				result += '\n';
			}
		}
	}
	catch (int e) {
		result = "It Has Some Problem. So It is automatically deleted";
		deleteSection(e);
	}
	return result;
}
string Controller::getAllEnrollSection() {
	string result;
	pair<map<int, Section>::const_iterator, map<int, Section>::const_iterator> interval = model->getSectionInterval();
	try {
		for (map<int, Section>::const_iterator it = interval.first; it != interval.second; it++) {
			Section tmp = it->second;
			if (tmp.getNo() != 0) {
				string no = to_string(tmp.getNo());
				if (!isThereSubject(tmp.getSubjectNo())) {
					throw tmp.getNo();
				}
				if (!isThereRoom(tmp.getRoomNo())) {
					throw tmp.getNo();
				}
				if (!isThereInstructor(tmp.getInstructorNo())) {
					throw tmp.getNo();
				}
				Subject subject = model->getSubject(tmp.getSubjectNo());
				string subjectName = subject.getDescription();
				string day = "";;
				switch (tmp.getDay()) {
				case 1:
					day = "Mon";
					break;
				case 2:
					day = "Tue";
					break;
				case 3:
					day = "Wed";
					break;
				case 4:
					day = "Thu";
					break;
				case 5:
					day = "Fri";
					break;
				case 6:
					day = "Sat";
					break;
				}
				string time = "";
				if (to_string(tmp.getTimeStartHour()).size() == 1) {
					time += "0" + to_string(tmp.getTimeStartHour());
				}
				else {
					time += to_string(tmp.getTimeStartHour());
				}
				time += ":";
				if (to_string(tmp.getTimeStartMinute()).size() == 1) {
					time += "0" + to_string(tmp.getTimeStartMinute());
				}
				else {
					time += to_string(tmp.getTimeStartMinute());
				}
				time += "~";
				if (to_string(tmp.getTimeEndHour()).size() == 1) {
					time += "0" + to_string(tmp.getTimeEndHour());
				}
				else {
					time += to_string(tmp.getTimeEndHour());
				}
				time += ":";
				if (to_string(tmp.getTimeEndMinute()).size() == 1) {
					time += "0" + to_string(tmp.getTimeEndMinute());
				}
				else {
					time += to_string(tmp.getTimeEndMinute());
				}
				for (int j = 0; j < 8 - no.size(); j++) {
					result += " ";
				}
				result += no;
				for (int j = 0; j < descriptionLength - subjectName.size(); j++) {
					result += " ";
				}
				result += subjectName;

				for (int j = 0; j < 5 - day.size(); j++) {
					result += " ";
				}
				result += day;

				for (int j = 0; j < 15 - time.size(); j++) {
					result += " ";
				}
				result += time;
				result += '\n';
			}
		}
	}
	catch (int e) {
		result = "It Has Some Problem. So It is automatically deleted";
		deleteSection(e);
	}
	return result;
}
string Controller::getAllMySchedule() {
	string result;
	try {
		for (int i = 0; i < subjectNumLength; i++) {
			int t = model->getSectionToStudent(i);
			if (t == 0) {
				break;
			}
			Section tmp = model->getSection(t);
			string no = to_string(tmp.getNo());
			if (!isThereSubject(tmp.getSubjectNo())) {
				throw tmp.getNo();
			}
			if (!isThereRoom(tmp.getRoomNo())) {
				throw tmp.getNo();
			}
			if (!isThereInstructor(tmp.getInstructorNo())) {
				throw tmp.getNo();
			}
			Subject subject = model->getSubject(tmp.getSubjectNo());
			string subjectName = subject.getDescription();
			string day = "";;
			switch (tmp.getDay()) {
			case 1:
				day = "Mon";
				break;
			case 2:
				day = "Tue";
				break;
			case 3:
				day = "Wed";
				break;
			case 4:
				day = "Thu";
				break;
			case 5:
				day = "Fri";
				break;
			case 6:
				day = "Sat";
				break;
			}
			string time = "";
			if (to_string(tmp.getTimeStartHour()).size() == 1) {
				time += "0" + to_string(tmp.getTimeStartHour());
			}
			else {
				time += to_string(tmp.getTimeStartHour());
			}
			time += ":";
			if (to_string(tmp.getTimeStartMinute()).size() == 1) {
				time += "0" + to_string(tmp.getTimeStartMinute());
			}
			else {
				time += to_string(tmp.getTimeStartMinute());
			}
			time += "~";
			if (to_string(tmp.getTimeEndHour()).size() == 1) {
				time += "0" + to_string(tmp.getTimeEndHour());
			}
			else {
				time += to_string(tmp.getTimeEndHour());
			}
			time += ":";
			if (to_string(tmp.getTimeEndMinute()).size() == 1) {
				time += "0" + to_string(tmp.getTimeEndMinute());
			}
			else {
				time += to_string(tmp.getTimeEndMinute());
			}
			for (int j = 0; j < 8 - no.size(); j++) {
				result += " ";
			}
			result += no;
			for (int j = 0; j < descriptionLength - subjectName.size(); j++) {
				result += " ";
			}
			result += subjectName;
			for (int j = 0; j < 5 - day.size(); j++) {
				result += " ";
			}
			result += day;
			for (int j = 0; j < 15 - time.size(); j++) {
				result += " ";
			}
			result += time;
			result += '\n';
		}
	}
	catch (int e) {
		result = "It Has Some Problem. So It is automatically deleted";
		deleteSection(e);
	}
	return result;
}

bool Controller::isThereUserInfo(int no) {
	pair<map<int, UserInfo>::const_iterator, map<int, UserInfo>::const_iterator> interval = model->getUserInfoInterval();
	for (map<int, UserInfo>::const_iterator it = interval.first; it != interval.second; it++) {
		if (it->second.getNo() == no) {
			return true;
		}
	}
	return false;
}
bool Controller::isThereInstructor(int no) {
	pair<map<int, Instructor>::const_iterator, map<int, Instructor>::const_iterator> interval = model->getInstructorInterval();
	for (map<int, Instructor>::const_iterator it = interval.first; it != interval.second; it++) {
		if (it->second.getNo() == no) {
			return true;
		}
	}
	return false;
}
bool Controller::isThereRoom(int no) {
	pair<map<int, Room>::const_iterator, map<int, Room>::const_iterator> interval = model->getRoomInterval();
	for (map<int, Room>::const_iterator it = interval.first; it != interval.second; it++) {
		if (it->second.getNo() == no) {
			return true;
		}
	}
	return false;
}
bool Controller::isThereStudent(int no) {
	pair<map<int, Student>::const_iterator, map<int, Student>::const_iterator> interval = model->getStudentInterval();
	for (map<int, Student>::const_iterator it = interval.first; it != interval.second; it++) {
		if (it->second.getNo() == no) {
			return true;
		}
	}
	return false;
}
bool Controller::isThereSubject(int no) {
	pair<map<int, Subject>::const_iterator, map<int, Subject>::const_iterator> interval = model->getSubjectInterval();
	for (map<int, Subject>::const_iterator it = interval.first; it != interval.second; it++) {
		if (it->second.getNo() == no) {
			return true;
		}
	}
	return false;
}
bool Controller::isThereSection(int no) {
	pair<map<int, Section>::const_iterator, map<int, Section>::const_iterator> interval = model->getSectionInterval();
	for (map<int, Section>::const_iterator it = interval.first; it != interval.second; it++) {
		if (it->second.getNo() == no) {
			return true;
		}
	}
	return false;
}
bool Controller::addSectionTostudent(int no) {
	if (isThereSection(no)) {
		Section original = model->getSection(no);
		for (int i = 0; i < subjectNumLength; i++) {
			if (model->getSectionToStudent(i) == 0) {
				break;
			}
			Section tmp = model->getSection(model->getSectionToStudent(i));
			int day = tmp.getDay();
			int sumStart = tmp.getTimeStartHour()*60+tmp.getTimeStartMinute();
			int sumEnd = tmp.getTimeEndHour() * 60 + tmp.getTimeEndMinute();
			int sumStart2 = original.getTimeStartHour() * 60 + original.getTimeStartMinute();
			int sumEnd2 = original.getTimeEndHour() * 60 + original.getTimeEndMinute();
			if (day == original.getDay() &&
				((sumStart2 <= sumStart&&sumEnd2 >= sumStart)|| 
				(sumStart2 <= sumEnd&&sumEnd2 >= sumEnd)|| 
				(sumStart2 >= sumStart&&sumEnd2 <= sumEnd))) {
				//if time confilction occur
				return false;
			}
		}
		model->addSectionToStudent(no);
		model->saveStudent(searchByNameInStudent());
		return true;
	}
	return false;
}
int Controller::searchByNameInStudent() {
	pair<map<int, Student>::const_iterator, map<int, Student>::const_iterator> interval = model->getStudentInterval();
	for (map<int, Student>::const_iterator it = interval.first; it != interval.second; it++) {
		if (it->second.getName() == ID) {
			return it->second.getNo();
		}
	}
	return -1;
}

void Controller::updateStudentPassword(string password) {

	Student me = model->getStudent(searchByNameInStudent());

	updateStudent(me.getNo(), me.getName(), password,me.getMajor());

};