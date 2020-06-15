#pragma once
#include "User.h"

class Nodo
{
public:

	Nodo* next;
	User user;

	Nodo(User _user) :user(_user) {
		next = nullptr;
	}


};

