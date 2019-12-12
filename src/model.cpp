#include "model.h"
#include "controller.h"
void Model::init(Controller* c) {
	controller = c;
}
void Model::load() {
	string fileName[6] = { "./datas/userInfo.dat","./datas/instructorInfo.dat","./datas/roomInfo.dat","./datas/studentInfo.dat","./datas/subjectInfo.dat","./datas/courseInfo.dat" };
	/*
	f[0] userInfo.dat is for Administrator's data
	f[1] instructorInfo.dat is for Instructor's data
	f[2] roomInfo.dat is for Room's data
	f[3] studentInfo.dat is for Student's Data
	f[4] subjectInfo.dat is for Subject's Data
	f[5] courseInfo.dat is for Section's Data
	*/
	for (int i = 0; i < 6; i++) {
		f[i].open(fileName[i], ios::in | ios::out | ios::binary);
		//open file
		if (!f[i].is_open()) {
			//if there is no file
			f[i].close();
			f[i].open(fileName[i], ios::out | ios::binary);
			//write file
			f[i].close();
			f[i].open(fileName[i], ios::in | ios::out | ios::binary);
			//open file again
			controller->addUserInfo(1,"jay","1234");
			//first admin jay's ID and PW
		}
	}
	//load datas
	UserInfo tmp0;
	f[0].clear();
	f[0].seekg(0);
	while (f[0]&&!f[0].eof()) {
		f[0].read(reinterpret_cast<char*>(&tmp0), sizeof(UserInfo));
		userInfo.insert({ tmp0.getNo(),tmp0 });
		f[0].flush();
	}
	Instructor tmp1;
	f[1].clear();
	f[1].seekg(0);
	while (f[1]&&!(f[1].eof())) {
		f[1].read(reinterpret_cast<char*>(&tmp1), sizeof(Instructor));
		instructor.insert({ tmp1.getNo(),tmp1 });
		f[1].flush();
	}
	Room tmp2;
	f[2].clear();
	f[2].seekg(0);
	while (f[2]&&!(f[2].eof())) {
		f[2].read(reinterpret_cast<char*>(&tmp2), sizeof(Room));
		room.insert({ tmp2.getNo(),tmp2 });
		f[2].flush();
	}
	Student tmp3;
	f[3].clear();
	f[3].seekg(0);
	while (f[3]&&!(f[3].eof())) {
		f[3].read(reinterpret_cast<char*>(&tmp3), sizeof(Student));
		student.insert({ tmp3.getNo(),tmp3 });
		f[3].flush();
	}
	Subject tmp4;
	f[4].clear();
	f[4].seekg(0);
	while (f[4]&&!(f[4].eof())) {
		f[4].read(reinterpret_cast<char*>(&tmp4), sizeof(Subject));
		subject.insert({ tmp4.getNo(),tmp4 });
		f[4].flush();
	}
	Section tmp5;
	f[5].clear();
	f[5].seekg(0);
	while (f[5]&&!(f[5].eof())) {
		f[5].read(reinterpret_cast<char*>(&tmp5), sizeof(Section));
		section.insert({ tmp5.getNo(),tmp5 });
		f[5].flush();
	}
}
void Model::makeFile(int count) {
	//build file
	UserInfo tmpuserInfo;
	Instructor tmpinstructor;
	Room tmproom;
	Student tmpstudent;
	Subject tmpsubject;
	Section tmpsection;
	f[0].clear();
	f[0].seekp(0);
	for (int i = 0; i < count; i++) {
		f[0].write(reinterpret_cast<const char*>(&tmpuserInfo), sizeof(UserInfo));
		f[0].flush();
	}
	f[1].clear();
	f[1].seekp(0);
	for (int i = 0; i < count; i++) {
		f[1].write(reinterpret_cast<const char*>(&tmpinstructor), sizeof(Instructor));
		f[1].flush();
	}
	f[2].clear();
	f[2].seekp(0);
	for (int i = 0; i < count; i++) {
		f[2].write(reinterpret_cast<const char*>(&tmproom), sizeof(Room));
		f[2].flush();
	}
	f[3].clear();
	f[3].seekp(0);
	for (int i = 0; i < count; i++) {
		f[3].write(reinterpret_cast<const char*>(&tmpstudent), sizeof(Student));
		f[3].flush();
	}
	f[4].clear();
	f[4].seekp(0);
	for (int i = 0; i < count; i++) {
		f[4].write(reinterpret_cast<const char*>(&tmpsubject), sizeof(Subject));
		f[4].flush();
	}
	f[5].clear();
	f[5].seekp(0);
	for (int i = 0; i < count; i++) {
		f[5].write(reinterpret_cast<const char*>(&tmpsection), sizeof(Section));
		f[5].flush();
	}
	userInfo.clear();
	instructor.clear();
	room.clear();
	student.clear();
	subject.clear();
	section.clear();
	controller->addUserInfo(1, "jay", "1234");
}

void Model::saveUserInfo(int no) {
	UserInfo tmp;
	pair<map<int, UserInfo>::const_iterator, map<int, UserInfo>::const_iterator> it = getUserInfoInterval();
	if (userInfo.find(no) != it.second) {
		tmp = userInfo.find(no)->second;
	}
	f[0].clear();
	f[0].seekp((no - 1) * sizeof(UserInfo));
	f[0].write(reinterpret_cast<const char*>(&tmp), sizeof(UserInfo));
	f[0].flush();
}
pair<map<int, UserInfo>::const_iterator, map<int, UserInfo>::const_iterator> Model::getUserInfoInterval() {
	return pair<map<int, UserInfo>::const_iterator, map<int, UserInfo>::const_iterator>(userInfo.begin(),userInfo.end());
}
UserInfo Model::getUserInfo(int no) {
	return userInfo.find(no)->second;
}
void Model::insertUserInfo(int no, string id, string pw) {
	userInfo.insert({ no,UserInfo(no, id.c_str(), pw.c_str()) });
}
void Model::updateUserInfo(int no, string name, string password) {
	map<int, UserInfo>::iterator it = userInfo.find(no);
	it->second.setNo(no);
	it->second.setName(name.c_str());
	it->second.setPassword(password.c_str());
}
void Model::deleteUserInfo(int no) {
	userInfo.erase(userInfo.find(no));
}

void Model::saveInstructor(int no) {
	Instructor tmp;
	pair<map<int, Instructor>::const_iterator, map<int, Instructor>::const_iterator> it = getInstructorInterval();
	if (instructor.find(no) != it.second) {
		tmp = instructor.find(no)->second;
	}
	f[1].clear();
	f[1].seekp((no - 1) * sizeof(Instructor));
	f[1].write(reinterpret_cast<const char*>(&tmp), sizeof(Instructor));
	f[1].flush();
}
pair<map<int, Instructor>::const_iterator, map<int, Instructor>::const_iterator> Model::getInstructorInterval() {
	return pair<map<int, Instructor>::const_iterator, map<int, Instructor>::const_iterator>(instructor.begin(),instructor.end());
}
Instructor Model::getInstructor(int no) {
	return instructor.find(no)->second;
}
void Model::insertInstructor(int no, string name, string password, string rank) {
	instructor.insert({ no,Instructor(no, name.c_str(), password.c_str(), rank.c_str()) });
}
void Model::updateInstructor(int no, string name, string password, string rank) {
	map<int, Instructor>::iterator it = instructor.find(no);
	it->second.setNo(no);
	it->second.setName(name.c_str());
	it->second.setPassword(password.c_str());
	it->second.setRank(rank.c_str());
}
void Model::deleteInstructor(int no) {
	instructor.erase(instructor.find(no));
}

void Model::saveRoom(int no) {
	Room tmp;
	pair<map<int, Room>::const_iterator, map<int, Room>::const_iterator> it = getRoomInterval();
	if (room.find(no) != it.second) {
		tmp = room.find(no)->second;
	}
	f[2].clear();
	f[2].seekp((no - 1) * sizeof(Room));
	f[2].write(reinterpret_cast<const char*>(&tmp), sizeof(Room));
	f[2].flush();
}
pair<map<int, Room>::const_iterator, map<int, Room>::const_iterator>  Model::getRoomInterval() {
	return pair<map<int, Room>::const_iterator, map<int, Room>::const_iterator>(room.begin(),room.end());
}
Room Model::getRoom(int no) {
	return room.find(no)->second;
}
void Model::insertRoom(int no, string description, string type) {
	room.insert({ no,Room(no, description.c_str(), type.c_str()) });
}
void Model::updateRoom(int no, string description, string type) {
	map<int, Room>::iterator it = room.find(no);
	it->second.setNo(no);
	it->second.setDescription(description.c_str());
	it->second.setType(type.c_str());
}
void Model::deleteRoom(int no) {
	room.erase(room.find(no));
}

void Model::saveStudent(int no) {
	Student tmp;
	pair<map<int, Student>::const_iterator, map<int, Student>::const_iterator> it = getStudentInterval();
	if (student.find(no) != it.second) {
		tmp = student.find(no)->second;
	}
	f[3].clear();
	f[3].seekp((no - 1) * sizeof(Student));
	f[3].write(reinterpret_cast<const char*>(&tmp), sizeof(Student));
	f[3].flush();
}
pair<map<int, Student>::const_iterator, map<int, Student>::const_iterator> Model::getStudentInterval() {
	return pair<map<int, Student>::const_iterator, map<int, Student>::const_iterator>(student.begin(),student.end());
}
Student Model::getStudent(int no) {
	return student.find(no)->second;
}
void Model::insertStudent(int no, string name, string password,string major) {
	student.insert({ no,Student(no, name.c_str(), password.c_str(),major.c_str()) });
}
void Model::updateStudent(int no, string name, string password,string major) {
	map<int, Student>::iterator it = student.find(no);
	it->second.setNo(no);
	it->second.setName(name.c_str());
	it->second.setPassword(password.c_str());
	it->second.setMajor(major.c_str());
}
void Model::deleteStudent(int no) {
	student.erase(student.find(no));
}

void Model::saveSubject(int no) {
	Subject tmp;
	pair<map<int, Subject>::const_iterator, map<int, Subject>::const_iterator> it = getSubjectInterval();
	if (subject.find(no) != it.second) {
		tmp = subject.find(no)->second;
	}
	f[4].clear();
	f[4].seekp((no - 1) * sizeof(Subject));
	f[4].write(reinterpret_cast<const char*>(&tmp), sizeof(Subject));
	f[4].flush();
}
pair<map<int, Subject>::const_iterator, map<int, Subject>::const_iterator> Model::getSubjectInterval() {
	return pair<map<int, Subject>::const_iterator, map<int, Subject>::const_iterator>(subject.begin(),subject.end());
}
Subject Model::getSubject(int no) {
	return subject.find(no)->second;
}
void Model::insertSubject(int no, string description, int unit) {
	subject.insert({ no,Subject(no, description.c_str(), unit) });
}
void Model::updateSubject(int no,string description, int unit) {
	map<int, Subject>::iterator it = subject.find(no);
	it->second.setNo(no);
	it->second.setDescription(description.c_str());
	it->second.setUnit(unit);
}
void Model::deleteSubject(int no) {
	subject.erase(subject.find(no));
}

void Model::saveSection(int no) {
	Section tmp;
	pair<map<int, Section>::const_iterator, map<int, Section>::const_iterator> it = getSectionInterval();
	if (section.find(no) != it.second) {
		tmp = section.find(no)->second;
	}
	f[5].clear();
	f[5].seekp((no - 1) * sizeof(Section));
	f[5].write(reinterpret_cast<const char*>(&tmp), sizeof(Section));
	f[5].flush();
}
pair<map<int, Section>::const_iterator, map<int, Section>::const_iterator> Model::getSectionInterval() {
	return pair<map<int, Section>::const_iterator, map<int, Section>::const_iterator>(section.begin(),section.end());
}
Section Model::getSection(int index) {
	return section.at(index);
}
void Model::insertSection(int t1, int t2, int t3,int t4,int t5,int t6,int t7,int t8,int t9) {
	section.insert({ t1,Section(t1,t2,t3,t4,t5,t6,t7,t8,t9) });
}
void Model::updateSection(int t1, int t2, int t3, int t4, int t5, int t6, int t7, int t8, int t9) {
	map<int, Section>::iterator it = section.find(t1);
	it->second.setNo(t1);
	it->second.setSubjectNo(t2);
	it->second.setRoomNo(t3);
	it->second.setInstructorNo(t4);
	it->second.setDay(t5);
	it->second.setTimeStartHour(t6);
	it->second.setTimeStartMinute(t7);
	it->second.setTimeEndHour(t8);
	it->second.setTimeEndMinute(t9);
}
void Model::deleteSection(int no) {
	section.erase(section.find(no));
}
void Model::addSectionToStudent(int subjectnum) {
	for (map<int,Student>::iterator it = student.begin(); it != student.end(); it++) {
		if (it->second.getName() == ID) {
			for (int i = 0; i < subjectNumLength; i++) {
				if (subjectnum == it->second.getSubjectNum(i)) {
					break;
				}
				else if (it->second.getSubjectNum(i) == 0) {
					it->second.setSubjectNum(i, subjectnum);
					break;
				}
			}
			break;
		}
	}
}
int Model::getSectionToStudent(int index) {
	for (map<int,Student>::iterator it = student.begin(); it != student.end(); it++) {
		if (it->second.getName() == ID) {
			return it->second.getSubjectNum(index);
			break;
		}
	}
}