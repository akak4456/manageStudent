#include "instructor.h"


Instructor::Instructor() :Person(0, " ", " ") {
	setRank(" ");
}

Instructor::Instructor(int t1, const char* t2, const char* t3, const char* t4) : Person(t1, t2, t3) {
	setRank(t4);
}
void Instructor::setRank(const char* t4) {
	unsigned int len = strlen(t4) < rankLength ? strlen(t4) : rankLength-1;
	strncpy_s(rank, t4, len);
	rank[len] = '\0';
}
//* setRank of instructor.


const char* Instructor::getRank() const {
	return rank;
}
//* return a data.