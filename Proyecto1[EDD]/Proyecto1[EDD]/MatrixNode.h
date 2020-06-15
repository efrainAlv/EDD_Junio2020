#pragma once

#ifndef MATRIXNODE_
#define MATRIXNODE_


#include <iostream>
#include "List.h"

class MatrixNode
{
public:

	MatrixNode* next;
	MatrixNode* previous;
	MatrixNode* above;
	MatrixNode* below;
	List* users;

	int y;
	int x;

	MatrixNode(int _x, int _y): x(_x), y(_y) {

		this->next = nullptr;
		this->previous = nullptr;
		this->above = nullptr;
		this->below = nullptr;

		users = new List();
	}


	void addUser(User user);



};

#endif
