#include "MatrixNode.h"

void MatrixNode::addUser(User user) {
	this->users->addLast(user);
}