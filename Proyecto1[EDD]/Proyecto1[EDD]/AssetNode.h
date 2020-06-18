#pragma once

#include "TreeNode.h"

class AssetNode
{

public:

	AssetNode* next;
	TreeNode* node;


	AssetNode(TreeNode* _node): node(_node) {

		this->next = nullptr;
	}



};

