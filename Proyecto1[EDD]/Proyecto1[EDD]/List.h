#pragma once

#include "Nodo.h"

class List
{

public:
	Nodo* head;
	int size;

	List(){
		head = nullptr;
		size = 0;
	}


	bool isEmpty();

	void addLast(User user);



};

