#include "CircularList.h"

bool CircularList::isEmpty() {

	return head == nullptr;

}


void CircularList::insert(CircularNode* node) {

	if (isEmpty()) {

		head = node;

		head->next = head;
		head->previous = head;

	}
	else {


		CircularNode* aux = head;
		bool isHigher;

		do {

			if (node->transaction.getID() > aux->transaction.getID()) {
				aux = aux->next;
			}
			else {
				break;
			}
			
		} while (aux!=head);

		aux = aux->previous;

		if (aux==head) {
			
			if (aux->transaction.getID() > node->transaction.getID()) {

				
				node->previous = head->previous;
				head->previous->next = node;

				node->next = head;
				head->previous = node;

				head = node;
			}
			else {

				head->next->previous = node;
				node->next = head->next;
				node->previous = head;

				node->previous = head;
				head->next = node;
			}


		}
		else {

			if (aux->transaction.getID() < node->transaction.getID()) {

				aux->next->previous = node;
				node->next = aux->next;
				
				aux->next = node;
				node->previous = aux;

			}
			else {

				aux->previous->next = node;
				node->previous = aux->previous;

				aux->previous = node;
				node->next = aux;

			}

			

		}

	}


}