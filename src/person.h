#pragma once
#include <iostream>
#include <cstring>
#include "define.h"

using namespace std;
class Person {
private:
	int no;
	char name[nameLength];
	char password[passwordLength];
public:
	Person(int, const char*, const char*);
	void setNo(int);
	void setName(const char*);
	void setPassword(const char*);
	int getNo() const;
	const char* getName() const;
	const char* getPassword() const;
};