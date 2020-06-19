#pragma once

#include "CircularNode.h"
#include <iostream>


class CircularList
{

public:
	CircularNode* head;
	std::string listName;
	int size;

	CircularList(std::string _listName):listName(_listName) {
		head = nullptr;
	}


	bool isEmpty();

	void insert(CircularNode* node);

	void ascendenet();

	void descendent();

	void createFileCircularList();


};




