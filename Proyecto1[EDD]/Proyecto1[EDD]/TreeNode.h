#pragma once

#include <iostream>

class TreeNode
{
public:
	TreeNode* parent;
	TreeNode* sibling;
	TreeNode* leftChild;
	TreeNode* rightChild;

	int height;
	int BF; //FACTOR DE BALANCEO

	std::string name;


	TreeNode(std::string _name): name(_name) {

		this->parent = nullptr;
		this->sibling = nullptr;
		this->leftChild = nullptr;
		this->rightChild = nullptr;

		this->height = 1;
		this->BF = 0;

	}


	bool isParent();

	bool isChild();


};

