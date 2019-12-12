#pragma once
#include "nonPerson.h"
class Room :public NonPerson {
private:
	char type[typeLength];
public:
	Room();
	Room(int, const char*, const char*);
	void setType(const char*);
	const char* getType() const;
};