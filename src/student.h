#pragma once
#include <iostream>
#include <cstring>
#include "person.h"

using namespace std;
class Student :public Person {
private:
	char major[majorLength];
	int subjectNum[subjectNumLength];
public:
	Student();
	Student(int, const char*, const char*,const char*);
	void setMajor(const char*);
	const char* getMajor();
	void setSubjectNum(int, int);
	int getSubjectNum(int);
};