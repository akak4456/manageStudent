#pragma once
#include <iostream>
#include <cstring>
#include "person.h"

using namespace std;

class UserInfo :public Person {
public:
	UserInfo();
	UserInfo(int, const char*, const char*);
};