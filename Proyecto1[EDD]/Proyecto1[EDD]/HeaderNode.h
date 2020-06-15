#pragma once

#include <iostream>
#include "MatrixNode.h"


class HeaderNode
{

public:

	HeaderNode* nextHeader;
	MatrixNode* next;
	HeaderNode* belowHeader;
	MatrixNode* below;
	

	std::string name;
	int x, y;

	HeaderNode(std::string _name, int _x, int _y):name(_name), x(_x), y(_y) {
		this->nextHeader = nullptr;
		this->belowHeader = nullptr;
		this->next = nullptr;
		this->below = nullptr;
	}



};

