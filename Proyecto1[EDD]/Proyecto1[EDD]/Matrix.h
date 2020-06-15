#pragma once

#ifndef MATRIX_
#define MATRIX_

#include <iostream>
#include "HeaderNode.h"

class Matrix
{
public:

	HeaderNode* pivot;
	std::string adminUser;
	std::string pass;
	int width;
	int height;

	Matrix(std::string _adminUser, std::string _pass):adminUser(_adminUser), pass(_pass) {
		
		pivot = new HeaderNode("PIVOT", 0,0);
		
		pivot->nextHeader = nullptr;
		pivot->belowHeader = nullptr;

		this->height = 0;
		this->width = 0;

	}


	bool isEmpty();

	void addUser(User user, std::string dept, std::string emp);
	
	MatrixNode* getExistingNode(int x, int y);




};

#endif

