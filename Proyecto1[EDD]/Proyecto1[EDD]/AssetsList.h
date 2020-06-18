#pragma once

#include "AssetNode.h"

class AssetsList
{


public:

	AssetNode* head;
	int size;

	AssetsList() {
		head = nullptr;
		size = 0;
	}


	bool isEmpty();

	void addLast(TreeNode* node);

	Assets* findAsset(std::string ID);

	void printAssets();

	void deleteAsset(std::string ID);


	void printRents();

};

