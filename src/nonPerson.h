#pragma once
#include <iostream>
#include <cstring>
#include "define.h"

using namespace std;

class NonPerson {
private:
	int no;
	char description[descriptionLength];
public:
	NonPerson(int, const char*);
	void setNo(int);
	void setDescription(const char*);
	int getNo() const;
	const char* getDescription() const;
};