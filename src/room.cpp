#include "room.h"
Room::Room() :NonPerson(0, " ") {
	setType(" ");
}
Room::Room(int t1, const char* t2, const char* t3) : NonPerson(t1, t2) {
	setType(t3);
}
void Room::setType(const char* t3) {
	unsigned int len = strlen(t3) < typeLength ? strlen(t3) : typeLength-1;
	strncpy_s(type, t3, len);
	type[len] = '\0';
}
//* setType of Room.


const char* Room::getType() const {
	return type;
}
//* return a data.