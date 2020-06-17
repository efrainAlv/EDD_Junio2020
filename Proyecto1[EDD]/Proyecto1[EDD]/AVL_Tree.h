#pragma once

#include "TreeNode.h"

class AVL_Tree
{
	
public:
	
	TreeNode* root;
	std::string name;

	AVL_Tree(std::string _name): name(_name) {

		this->root = nullptr;
	}

	bool isEmpty();

	void add(std::string _name);

	void updateHeightAndBF(TreeNode* leaf);


	
	TreeNode* balance(TreeNode* leaf, bool isRoot);

	TreeNode* rightRotation(TreeNode* leaf);
	
	TreeNode* leftRotation(TreeNode* leaf);

	TreeNode* doubleRotationRL(TreeNode* leaf);

	TreeNode* doubleRotationLR(TreeNode* leaf);

	void printTree();



};

