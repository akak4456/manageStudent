#include "userInfo.h"

UserInfo::UserInfo() :Person(0, " ", " ") {
}
UserInfo::UserInfo(int t1, const char* t2, const char* t3) : Person(t1, t2, t3) {
}