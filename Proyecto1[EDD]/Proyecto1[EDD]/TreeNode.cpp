#include "TreeNode.h"

#include "TreeNode.h"

bool TreeNode::isParent() {

	return leftChild != nullptr || rightChild != nullptr;
}


bool TreeNode::isChild() {

	return parent != nullptr;
}