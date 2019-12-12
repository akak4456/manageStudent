#pragma once
#include "nonPerson.h"
class Subject :public NonPerson {
private:
	int unit;
public:
	Subject();
	Subject(int, const char*, int);
	void setUnit(int);
	const int getUnit() const;
};