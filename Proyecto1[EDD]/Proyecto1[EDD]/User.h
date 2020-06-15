#pragma once

#include <iostream>

class User
{
private:
	std::string fullName;
	std::string userName;
	std::string password;

public:
	User(std::string fullName_, std::string userName_, std::string password_):fullName(fullName_), userName(userName_), password(password_) {}

	void setFullName(std::string _fullName);
	std::string getFullName();

	void setUserName(std::string _userName);
	std::string getUserName();

	void setPassword(std::string _password);
	std::string getPassword();

	void printUser();

};

