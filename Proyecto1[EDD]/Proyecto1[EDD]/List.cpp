#include "List.h"

#include "Nodo.h"
#include <iostream>

bool List::isEmpty() {

	if (head == nullptr) {
		return true;
	}
	else {
		return false;
	}

}

void List::addLast(User user) {

	Nodo* newNode;
	newNode = new Nodo(user);

	if (isEmpty()) {
		head = newNode;
		head->next = nullptr;
		size++;
	}
	else {

		Nodo* auxNode = head;

		while (auxNode->next != nullptr) {
			auxNode = auxNode->next;
		}
		newNode->next = nullptr;
		auxNode->next = newNode;
		size++;
	}

}