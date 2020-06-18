#pragma once

#include <iostream>
#include "Transaction.h"

class CircularNode
{

public:

	CircularNode* next;
	CircularNode* previous;

	Transaction transaction;

	CircularNode(Transaction _transaction): transaction(_transaction) {

		this->next = nullptr;
		this->previous = nullptr;
	}



};

