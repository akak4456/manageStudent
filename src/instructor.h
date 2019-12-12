#pragma once
#include <iostream>
#include <cstring>
#include "person.h"
using namespace std;
class Instructor :public Person {
private:
	char rank[rankLength];
public:
	Instructor();
	Instructor(int, const char*, const char*, const char*);
	void setRank(const char*);
	const char* getRank() const;
};