#include "User.h"

#include <iostream>

using namespace std;

void User::setFullName(std::string fullName) {
	this->fullName = fullName;
}
std::string User::getFullName() {
	return this->fullName;
}

void User::setUserName(std::string userName) {
	this->userName = userName;
}
std::string User::getUserName() {
	return this->userName;
}

void User::setPassword(std::string password) {
	this->password = password;
}
std::string User::getPassword() {
	return this->password;
}

void User::printUser() {
	std::cout << "Full Name:" + getFullName() + " User Name:" + getUserName() + " Password:" + getPassword()<<std::endl;
}
