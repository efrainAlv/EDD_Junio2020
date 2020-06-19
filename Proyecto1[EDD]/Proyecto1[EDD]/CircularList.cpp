#include "CircularList.h"

#include <fstream>

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


void CircularList::ascendenet() {

	CircularNode* aux = head;

	do {

		std::cout << "ID: " << aux->transaction.getID() << " ID ACTIVO: " << aux->transaction.getIDAsset() << " USUARIO:" << aux->transaction.getUser()->getFullName();

		aux = aux->next;

	} while (aux != head);

}

void CircularList::descendent() {


	CircularNode* aux = head->previous;

	do {

		std::cout << "ID: " << aux->transaction.getID() << " ID ACTIVO: " << aux->transaction.getIDAsset() << " USUARIO:" << aux->transaction.getUser()->getFullName();

		aux = aux->previous;

	} while (aux != head);

}


void CircularList::createFileCircularList() {


	CircularNode* aux = head;

	std::string links="";


	do {


		links += '"' + aux->transaction.getID() + '"' + "[shape = record label =" + '"' + "{" + "ID: " + aux->transaction.getID() + "|" + "Activo: " + aux->transaction.getIDAsset() + "|" + "Usuario: " + aux->transaction.getUser()->getUserName() + "}" + '"' + " style = filled fillcolor = bisque1]"+"\n";
		links += '"' + aux->next->transaction.getID() + '"' + "[shape = record label =" + '"' + "{" + "ID: " + aux->next->transaction.getID() + "|" + "Activo: " + aux->next->transaction.getIDAsset() + "|" + "Usuario: " + aux->next->transaction.getUser()->getUserName() + "}" + '"' + " style = filled fillcolor = bisque1]" + "\n";
		links += '"' + aux->transaction.getID()+ '"' +"->"+ '"'+aux->next->transaction.getID() + '"' + "\n";
		links += '"' + aux->next->transaction.getID() + '"' + "->" + '"' +aux->transaction.getID() + '"' + "\n";

		aux = aux->next;

	} while (aux!=head);


	std::ofstream file;
	file.open("C:/Users/efrai/Desktop/GRAPHS/ListaCircular/listaCircular.txt");

	file << "digraph G{";

	file << links;

	file << "}";
	file.close();

	std::string path = "dot -Tpng C:\\Users\\efrai\\Desktop\\GRAPHS\\ListaCircular\\listaCircular.txt -o C:\\Users\\efrai\\Desktop\\GRAPHS\\ListaCircular\\ListaCircular.png";

	std::cout << path.c_str();

	system(path.c_str());


}

