#include "AssetsList.h"

#include <fstream>

bool AssetsList::isEmpty() {

	if (head == nullptr) {
		return true;
	}
	else {
		return false;
	}

}

void AssetsList::addLast(TreeNode* newNode) {

	bool pass =false;

	AssetNode* newN = new AssetNode(newNode);


	if (isEmpty()) {
		head = newN;
		head->next = nullptr;
		size++;
	}
	else {

		AssetNode* auxNode = head;

		while (auxNode->next != nullptr) {
			
			if (auxNode== newN) {
				pass = true;
			}
			auxNode = auxNode->next;
		}
		
		if (!pass) {
			auxNode->next = newN;
			auxNode->next->next = nullptr;
			size++;
		}
	}

}


Assets* AssetsList::findAsset(std::string ID) {

	AssetNode* aux = head;

	do {

		if (aux->node->asset->getID()==ID) {
			break;
		}
		else {

			aux = aux->next;
		}

	} while (aux != nullptr);


	if (aux != nullptr) {
		return aux->node->asset;
	}
	else {
		return nullptr;
	}

}


void AssetsList::printRents() {

	AssetNode* node = head;

	do {

		std::cout << "ID: " << node->node->asset->getID() << "  NOMBRE: " << node->node->asset->getName();
		if (!node->node->asset->isAvaliable()) {

		}

		node = node->next;

	} while (node != nullptr);

}


void AssetsList::printAssets() {

	AssetNode* node = head;

	do {

		std::cout << "ID: " << node->node->asset->getID() << "  NOMBRE: " << node->node->asset->getName() << std::endl;

		node = node->next;

	} while (node!=nullptr);

}


void AssetsList::deleteAsset(std::string ID) {

	AssetNode* aux= head;
	AssetNode* auxNex = aux->next;

	int n = 1;

	if (head->node->asset->getID() == ID) {

		head = head->next;

	}
	else {

		do {

			if (aux->next->node->asset->getID() == ID && aux->next->next != nullptr) {

				aux->next = aux->next->next;

			}
			if (aux->next->next==nullptr && aux->next->node->asset->getID()==ID) {
				aux->next = nullptr;
			}

			aux = aux->next;

		} while (aux->next!= nullptr);

	}


}


void AssetsList::createFileList() {

	AssetNode* aux = head;

	std::string links;

	do {

		
		links += '"' + aux->node->asset->getID() + '"' + "[shape = record label =" + '"' + "{" + "ACtivo: " + aux->node->asset->getID() + "|" + "Activo: " + aux->node->asset->getName() + "}" + '"' + " style = filled fillcolor = bisque1]" + "\n";
		
		if (aux->next != nullptr) {
			links += '"' + aux->node->asset->getID() + '"' + "->" + '"' + aux->next->node->asset->getID() + '"' + "\n";
		}

		aux = aux->next;

	} while (aux!=nullptr);



	std::ofstream file;
	file.open("C:/Users/efrai/Desktop/GRAPHS/Lista/Lista.txt");

	file << "digraph G{";

	file << links;

	file << "}";
	file.close();

	std::string path = "dot -Tpng C:\\Users\\efrai\\Desktop\\GRAPHS\\Lista\\lista.txt -o C:\\Users\\efrai\\Desktop\\GRAPHS\\Lista\\lista.png";

	std::cout << path.c_str();

	system(path.c_str());

}